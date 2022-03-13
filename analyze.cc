// #include <cstdio>
// #include <algorithm>
// #include <array>
// #include <map>
// #include <set>
// #include <string>
// #include <vector>

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

    bool mc(std::pair<std::array<Woman, NUM_MEN>, size_t> mc_result) const {
        // If we get K lights in a week, that means a pairing is valid iff
        // it shares exactly K couples with the MC pairing.
        size_t num_couple_same = 0;
        for (Man i = 0; i < NUM_MEN; i++) {
            num_couple_same += (women[i] == mc_result.first[i]);
        }
        return num_couple_same == mc_result.second;
    }
};

// Prints out the number of each time each couple appears in valid pairings.
void printCoupleCounts(const Pairing *pairings, const bool *pairing_valid,
                       bool dropZeros) {
    std::vector<std::vector<size_t>> count;
    for (Man m = 0; m < NUM_MEN; m++)
        count.push_back(std::vector<size_t>(NUM_WOMEN, 0));
    for (size_t i = 0; i < MAX_PAIRINGS; i++) {
        if (!pairing_valid[i])
            continue;
        for (Man m = 0; m < NUM_MEN; m++) {
            count[m][pairings[i].women[m]]++;
        }
    }

    for (Man m = 0; m < NUM_MEN; m++) {
        printf("%s\n", MAN_MAP.at(m).c_str());
        for (Woman w = 0; w < NUM_WOMEN; w++) {
            if (count[m][w] == 0 && dropZeros)
                continue;
            printf("  %10s %9zu\n", WOMAN_MAP.at(w).c_str(), count[m][w]);
        }
    }
}

int main(void) {
    // Generate all pairings.
    Pairing *pairings = new Pairing[MAX_PAIRINGS];
    bool *pairing_valid = new bool[MAX_PAIRINGS];
    size_t pairing_idx = 0;
    do {
        Man man = 0;
        for (const auto &woman : ALL_WOMEN) {
            pairings[pairing_idx].women[man] = woman;
            man++;
        }
        pairing_valid[pairing_idx] = true;
        pairing_idx++;
    } while (std::next_permutation(ALL_WOMEN.begin(), ALL_WOMEN.end()));
    printf("Initial pairings %9d\n", MAX_PAIRINGS);

    for (size_t round = 0; round < NUM_ROUND; round++) {
        auto [tb_couple, tb_are_pm] = TB_RESULTS[round];
        int num_valid_after_tb = 0;
        for (size_t i = 0; i < MAX_PAIRINGS; i++) {
            if (!pairing_valid[i])
                continue;
            pairing_valid[i] &= pairings[i].tb(TB_RESULTS[round]);
            num_valid_after_tb += pairing_valid[i];
        }
        printf("After Week %2zu TB %9d\n", round + 1, num_valid_after_tb);

        int num_valid_after_mc = 0;
        for (size_t i = 0; i < MAX_PAIRINGS; i++) {
            if (!pairing_valid[i])
                continue;
            pairing_valid[i] &= pairings[i].mc(MC_RESULTS[round]);
            num_valid_after_mc += pairing_valid[i];
        }
        printf("After Week %2zu MC %9d\n", round + 1, num_valid_after_mc);
    }

    printCoupleCounts(pairings, pairing_valid, /*dropZeros=*/true);
}
