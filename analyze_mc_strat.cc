#include <cstdio>

#include <algorithm>
#include <array>
#include <random>
#include <utility>

// Efficient storage of pairings:
// A full pairing of men and woman can be represented by N tuples.
// There is no inherent ordering of the tuples, so let us always
// store it with the men in the same order. If we do so, we do not
// need to explicitly store the men at all and instead can just
// store the woman. This reflects that there are N! pairings total,
// for the N! of permutations of the woman with respect to a fixed
// ordering of men.

#include "season4.h"
// #include "season6.h"

// Utility class for operating on pairings.
struct Pairing {
    std::array<Woman, NUM_MEN> women; // Indexed by men.

    bool contains(const Couple c) const { return women[c.first] == c.second; }

    void print() const {
        for (size_t i = 0; i < NUM_MEN; i++) {
            printf("(%s,%s)", MAN_MAP.at(i).c_str(),
                   WOMAN_MAP.at(women[i]).c_str());
        }
        printf("\n");
    }

    bool tb(std::pair<Couple, bool> tb_result) const {
        if (tb_result.second) {
            // TB couple is a PM.
            // Pairing is valid iff contains couple.
            return contains(tb_result.first);
        } else {
            // TB couple is not a PM.
            // Pairing is valid iff doesn't contain couple.
            return !contains(tb_result.first);
        }
    }

    bool
    mc(const std::pair<std::array<Woman, NUM_MEN>, size_t> &mc_result) const {
        // If we get K lights in a week, that means a pairing is valid iff
        // it shares exactly K couples with the MC pairing.
        return shared(mc_result.first) == mc_result.second;
    }

    size_t shared(const std::array<Woman, NUM_MEN> &pairing) const {
        size_t num_couple_same = 0;
        for (Man i = 0; i < NUM_MEN; i++) {
            num_couple_same += (women[i] == pairing[i]);
        }
        return num_couple_same;
    }
};

int main(void) {
    // Generate all pairings.
    Pairing *pairings   = new Pairing[MAX_PAIRINGS];
    bool *pairing_valid = new bool[MAX_PAIRINGS];
    size_t pairing_idx  = 0;
    do {
        Man man = 0;
        for (const auto &woman : ALL_WOMEN) {
            pairings[pairing_idx].women[man] = woman;
            man++;
        }
        pairing_valid[pairing_idx] = true;
        pairing_idx++;
    } while (std::next_permutation(ALL_WOMEN.begin(), ALL_WOMEN.end()));

    size_t sims_run = 0;
    std::vector<size_t> game_won(NUM_ROUND, 0);
    std::vector<size_t> one_left(NUM_ROUND, 0);

    // Create a lookup structure for valid pairings. First `num_valid_after_mc`
    // entries will be indices of valid pairings, rest is garbage. Sampling
    // from valid_idxs is much faster when number of valid pairings shrinks
    // as a sample-until-valid strategy starts turning into needle-in-haystack.
    int num_valid_after_mc = MAX_PAIRINGS;
    size_t *valid_idxs     = new size_t[MAX_PAIRINGS];
    for (size_t sim = 0; sim < 1000; sim++) {
        std::default_random_engine eng(sim + 1);
        // Reset validity.
        for (size_t i = 0; i < MAX_PAIRINGS; i++) {
            pairing_valid[i] = true;
        }
        num_valid_after_mc = MAX_PAIRINGS;
        for (size_t round = 0; round < NUM_ROUND; round++) {
            // Pick a random valid pairing
            size_t r;
            if (round == 0) {
                do {
                    std::uniform_int_distribution<int> dist(0,
                                                            MAX_PAIRINGS - 1);
                    r = dist(eng);
                } while (!pairing_valid[r]);
            } else {
                std::uniform_int_distribution<int> dist(0,
                                                        num_valid_after_mc - 1);
                r = valid_idxs[dist(eng)];
            }
            // Determine number of lights by comparing to winning pairing.
            const size_t lights =
                pairings[r].shared(MC_RESULTS[NUM_ROUND - 1].first);
            game_won[round] += int(lights == NUM_MEN);
            // Make into a MC result.
            const std::pair<std::array<Woman, NUM_MEN>, size_t> mc_result = {
                pairings[r].women, lights};
            // Remove invalid pairings and store lookup for valid parings to
            // speed up sampling.
            num_valid_after_mc = 0;
            for (size_t i = 0; i < MAX_PAIRINGS; i++) {
                if (!pairing_valid[i])
                    continue;
                pairing_valid[i] &= pairings[i].mc(mc_result);
                if (pairing_valid[i]) {
                    valid_idxs[num_valid_after_mc] = i;
                    num_valid_after_mc++;
                }
            }
            // Record statistics.
            one_left[round] += int(num_valid_after_mc == 1);
        }
        sims_run++;
    }

    printf("Sims run:  %6zu\n", sims_run);
    for (size_t round = 0; round < NUM_ROUND; round++) {
        printf("Games won in week %2zu: %6zu\n", round + 1, game_won[round]);
    }
    for (size_t round = 0; round < NUM_ROUND; round++) {
        printf("One left in week %2zu: %6zu\n", round + 1, one_left[round]);
    }
}

// Sims run:     100
// Games won in week  1:      0
// Games won in week  2:      0
// Games won in week  3:      0
// Games won in week  4:      0
// Games won in week  5:      0
// Games won in week  6:      0
// Games won in week  7:      1
// Games won in week  8:      6
// Games won in week  9:     12
// Games won in week 10:     36
// One left in week  1:      0
// One left in week  2:      0
// One left in week  3:      0
// One left in week  4:      0
// One left in week  5:      0
// One left in week  6:      0
// One left in week  7:      2
// One left in week  8:     10
// One left in week  9:     23
// One left in week 10:     52
// ./analyze_mc_strat  3.20s user 0.01s system 96% cpu 3.341 total

// Sims run:    1000
// Games won in week  1:      0
// Games won in week  2:      0
// Games won in week  3:      0
// Games won in week  4:      0
// Games won in week  5:      0
// Games won in week  6:      4
// Games won in week  7:     10
// Games won in week  8:     56
// Games won in week  9:    153
// Games won in week 10:    343
// One left in week  1:      0
// One left in week  2:      0
// One left in week  3:      0
// One left in week  4:      0
// One left in week  5:      0
// One left in week  6:      5
// One left in week  7:     29
// One left in week  8:    102
// One left in week  9:    245
// One left in week 10:    493