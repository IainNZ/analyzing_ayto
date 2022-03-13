// Data for Season 4

#include <cstdint> // uint8_t

#include <array>
#include <map>
#include <string>
#include <utility>
#include <vector>

#define NUM_MEN 10
#define NUM_WOMEN 10
#define MAX_PAIRINGS 3628800
#define NUM_ROUND 10
using Man = uint8_t;
using Woman = uint8_t;
using Couple = std::pair<Man, Woman>;


const Man PROSPER = 0;
const Man JOHN = 1;
const Man GIOVANNI = 2;
const Man ASAF = 3;
const Man CAM = 4;
const Man SAM = 5;
const Man CAMERON = 6;
const Man MORGAN = 7;
const Man STEPHEN = 8;
const Man TYLER = 9;
std::array<Man, NUM_MEN> ALL_MEN = {
    PROSPER, JOHN, GIOVANNI, ASAF, CAM, SAM,
    CAMERON, MORGAN, STEPHEN, TYLER};
const std::map<Man, std::string> MAN_MAP = {
    {PROSPER, "PROSPER"}, {JOHN, "JOHN"},
    {GIOVANNI, "GIOVANNI"}, {ASAF, "ASAF"},
    {CAM, "CAM"}, {SAM, "SAM"},
    {CAMERON, "CAMERON"}, {MORGAN, "MORGAN"},
    {STEPHEN, "STEPHEN"}, {TYLER, "TYLER"}};

const Woman CAMILLE = 0;
const Woman EMMA = 1;
const Woman KAYLEN = 2;
const Woman FRANCESCA = 3;
const Woman VICTORIA = 4;
const Woman ALYSSA = 5;
const Woman MIKALA = 6;
const Woman JULIA = 7;
const Woman NICOLE = 8;
const Woman TORI = 9;
std::array<Woman, NUM_WOMEN> ALL_WOMEN = {
    CAMILLE, EMMA, KAYLEN, FRANCESCA, VICTORIA,
    ALYSSA, MIKALA, JULIA, NICOLE, TORI};
const std::map<Woman, std::string> WOMAN_MAP = {
    {CAMILLE, "CAMILLE"}, {EMMA, "EMMA"},
    {KAYLEN, "KAYLEN"}, {FRANCESCA, "FRANCESCA"},
    {VICTORIA, "VICTORIA"}, {ALYSSA, "ALYSSA"},
    {MIKALA, "MIKALA"}, {JULIA, "JULIA"},
    {NICOLE, "NICOLE"}, {TORI, "TORI"}};

const std::pair<Couple, bool> TB_RESULTS[] = {
    {{PROSPER, TORI}, false},
    {{JOHN, JULIA}, false},
    {{CAMERON, MIKALA}, true},
    {{ASAF, TORI}, false},
    {{GIOVANNI, KAYLEN}, false},
    {{SAM, ALYSSA}, true},
    {{CAM, VICTORIA}, false},
    {{GIOVANNI, JULIA}, false},
    {{PROSPER, EMMA}, true},
    {{CAM, JULIA}, true},
};

const std::pair<std::array<Woman, NUM_MEN>, size_t> MC_RESULTS[] = {
    {{CAMILLE, EMMA, KAYLEN, FRANCESCA, VICTORIA,
      ALYSSA, MIKALA, JULIA, NICOLE, TORI}, 3},
    {{EMMA, NICOLE, KAYLEN, CAMILLE, JULIA,
      FRANCESCA, MIKALA, ALYSSA, TORI, VICTORIA}, 3},
    {{EMMA, VICTORIA, KAYLEN, CAMILLE, NICOLE,
      ALYSSA, MIKALA, FRANCESCA, TORI, JULIA}, 4},
    {{NICOLE, VICTORIA, KAYLEN, CAMILLE, EMMA,
      ALYSSA, MIKALA, TORI, JULIA, FRANCESCA}, 4},
    {{VICTORIA, TORI, FRANCESCA, CAMILLE, EMMA,
      ALYSSA, MIKALA, JULIA, NICOLE, KAYLEN}, 4},
    {{KAYLEN, EMMA, FRANCESCA, CAMILLE, VICTORIA,
      ALYSSA, MIKALA, TORI, JULIA, NICOLE}, 4},
    {{VICTORIA, KAYLEN, EMMA, FRANCESCA, NICOLE,
      ALYSSA, MIKALA, TORI, JULIA, CAMILLE}, 4},
    {{FRANCESCA, KAYLEN, NICOLE, CAMILLE, TORI,
      ALYSSA, MIKALA, VICTORIA, JULIA, EMMA}, 2},
    {{EMMA, VICTORIA, FRANCESCA, TORI, NICOLE,
      ALYSSA, MIKALA, JULIA, KAYLEN, CAMILLE}, 6},
    {{EMMA, VICTORIA, FRANCESCA, KAYLEN, JULIA,
      ALYSSA, MIKALA, TORI, NICOLE, CAMILLE}, 10}
};
