// Data for Season 6

#include <cstdint> // uint8_t

#include <array>
#include <map>
#include <string>
#include <utility>
#include <vector>

#define NUM_MEN 11
#define NUM_WOMEN 11
#define MAX_PAIRINGS 39916800
#define NUM_ROUND 9
using Man    = uint8_t;
using Woman  = uint8_t;
using Couple = std::pair<Man, Woman>;

const Man ZAK    = 0;
const Man TEVIN  = 1;
const Man KWASI  = 2;
const Man BRETT  = 3;
const Man CAM    = 4;
const Man TOMAS  = 5;
const Man SHAMOY = 6;
const Man ANDREW = 7;
const Man MOE    = 8;
const Man DANIEL = 9;
const Man LEWIS  = 10;

std::array<Man, NUM_MEN> ALL_MEN = {ZAK,    TEVIN,  KWASI, BRETT,  CAM,  TOMAS,
                                    SHAMOY, ANDREW, MOE,   DANIEL, LEWIS};

const std::map<Man, std::string> MAN_MAP = {
    {ZAK,    "ZAK"   },
    {TEVIN,  "TEVIN" },
    {KWASI,  "KWASI" },
    {BRETT,  "BRETT" },
    {CAM,    "CAM"   },
    {TOMAS,  "TOMAS" },
    {SHAMOY, "SHAMOY"},
    {ANDREW, "ANDREW"},
    {MOE,    "MOE"   },
    {DANIEL, "DANIEL"},
    {LEWIS,  "LEWIS" }
};

const Woman BRIA     = 0;
const Woman KENYA    = 1;
const Woman ASIA     = 2;
const Woman CALI     = 3;
const Woman KAYLA    = 4;
const Woman MORGAN   = 5;
const Woman MARIA    = 6;
const Woman LAUREN   = 7;
const Woman JASMINE  = 8;
const Woman NUTSA    = 9;
const Woman SAMANTHA = 10;

std::array<Woman, NUM_WOMEN> ALL_WOMEN = {BRIA,    KENYA,  ASIA,    CALI,
                                          KAYLA,   MORGAN, MARIA,   LAUREN,
                                          JASMINE, NUTSA,  SAMANTHA};

const std::map<Woman, std::string> WOMAN_MAP = {
    {BRIA,     "BRIA"    },
    {KENYA,    "KENYA"   },
    {ASIA,     "ASIA"    },
    {CALI,     "CALI"    },
    {KAYLA,    "KAYLA"   },
    {MORGAN,   "MORGAN"  },
    {MARIA,    "MARIA"   },
    {LAUREN,   "LAUREN"  },
    {JASMINE,  "JASMINE" },
    {NUTSA,    "NUTSA"   },
    {SAMANTHA, "SAMANTHA"}
};

const std::pair<Couple, bool> TB_RESULTS[] = {
    {{TOMAS, MARIA},  false},
    {{ANDREW, ASIA},  false},
    {{SHAMOY, MARIA}, true },
    {{BRETT, KENYA},  false},
    {{ZAK, BRIA},     false},
    {{BRETT, CALI},   false},
    {{ZAK, NUTSA},    false},
    {{TEVIN, KENYA},  true },
    {{CAM, SAMANTHA}, false},
};

const std::pair<std::array<Woman, NUM_MEN>, size_t> MC_RESULTS[] = {
    {{BRIA, KENYA, ASIA, CALI, KAYLA, MORGAN, MARIA, LAUREN, JASMINE, NUTSA,
      SAMANTHA},
     3},
    {{SAMANTHA, KENYA, LAUREN, ASIA, KAYLA, CALI, MARIA, MORGAN, BRIA, NUTSA,
      JASMINE},
     3},
    {{MORGAN, KENYA, JASMINE, CALI, KAYLA, BRIA, MARIA, LAUREN, NUTSA, SAMANTHA,
      ASIA},
     3},
    {{MORGAN, JASMINE, BRIA, KAYLA, ASIA, CALI, MARIA, NUTSA, SAMANTHA, LAUREN,
      KENYA},
     2},
    {{MORGAN, KENYA, JASMINE, NUTSA, KAYLA, CALI, MARIA, SAMANTHA, ASIA, BRIA,
      LAUREN},
     4},
    {{MORGAN, KENYA, ASIA, NUTSA, KAYLA, CALI, MARIA, LAUREN, JASMINE, SAMANTHA,
      BRIA},
     4},
    {{MORGAN, KENYA, ASIA, NUTSA, CALI, KAYLA, MARIA, LAUREN, JASMINE, SAMANTHA,
      BRIA},
     4},
    {{CALI, KENYA, JASMINE, NUTSA, LAUREN, MORGAN, MARIA, SAMANTHA, KAYLA, ASIA,
      BRIA},
     4},
    {{SAMANTHA, KENYA, NUTSA, BRIA, MORGAN, JASMINE, MARIA, CALI, KAYLA, LAUREN, ASIA},
     4},
};

// clang-format on