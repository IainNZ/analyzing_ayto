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
#define NUM_ROUND 7
using Man = uint8_t;
using Woman = uint8_t;
using Couple = std::pair<Man, Woman>;

// clang-format off

const Man KAREEM = 0;
const Man ANTHONY = 1;
const Man MALCOLM = 2;
const Man KEITH = 3;
const Man JOE = 4;
const Man MICHAEL = 5;
const Man ETHAN = 6;
const Man CLINTON = 7;
const Man SHAD = 8;
const Man TYLER = 9;
const Man DIMITRI = 10;
std::array<Man, NUM_MEN> ALL_MEN = {
    KAREEM, ANTHONY, MALCOLM, KEITH, JOE, MICHAEL,
    ETHAN, CLINTON, SHAD, TYLER, DIMITRI};
const std::map<Man, std::string> MAN_MAP ={
    {KAREEM,"KAREEM"},  {ANTHONY,"ANTHONY"},    {MALCOLM,"MALCOLM"},
    {KEITH,"KEITH"},    {JOE,"JOE"},            {MICHAEL,"MICHAEL"},
    {ETHAN,"ETHAN"},    {CLINTON,"CLINTON"},    {SHAD,"SHAD"},
    {TYLER,"TYLER"},    {DIMITRI,"DIMITRI"}
};

const Woman ALIVIA = 0;
const Woman GELES = 1;
const Woman NURYS = 2;
const Woman ALEXIS = 3;
const Woman ZOE = 4;
const Woman KEYANA = 5;
const Woman JADA = 6;
const Woman UCHE = 7;
const Woman AUDREY = 8;
const Woman NICOLE = 9;
const Woman DIANDRA = 10;
std::array<Woman, NUM_WOMEN> ALL_WOMEN = {
    ALIVIA, GELES, NURYS, ALEXIS, ZOE, KEYANA,
    JADA, UCHE, AUDREY, NICOLE, DIANDRA};
const std::map<Woman, std::string> WOMAN_MAP = {
    {ALIVIA,"ALIVIA"},  {GELES,"GELES"},    {NURYS,"NURYS"},
    {ALEXIS,"ALEXIS"},  {ZOE,"ZOE"},        {KEYANA,"KEYANA"},
    {JADA,"JADA"},      {UCHE,"UCHE"},      {AUDREY,"AUDREY"},
    {NICOLE,"NICOLE"},  {DIANDRA,"DIANDRA"}
};

const std::pair<Couple, bool> TB_RESULTS[] = {
    {{ETHAN, KEYANA}, false},
    {{ANTHONY, GELES}, false},
    {{MALCOLM, NURYS}, false},
    {{DIMITRI, NICOLE}, false},
    {{CLINTON, UCHE}, false},
    {{KEITH, ALEXIS}, false},
    {{KEITH, ALIVIA}, false},
};

const std::pair<std::array<Woman, NUM_MEN>, size_t> MC_RESULTS[] = {
    {{
        ALIVIA, GELES, NURYS, ALEXIS, ZOE, KEYANA,
        JADA, UCHE, AUDREY, NICOLE, DIANDRA
    }, 3},
    {{
        ALIVIA, DIANDRA, NURYS, ALEXIS, AUDREY, KEYANA,
        JADA, UCHE, GELES, ZOE, NICOLE
    }, 1},
    {{
        ALIVIA, JADA, GELES, DIANDRA, ZOE, AUDREY,
        ALEXIS, UCHE, KEYANA, NICOLE, NURYS
    }, 2},
    {{
        DIANDRA, KEYANA, ALIVIA, NURYS, ZOE, GELES,
        NICOLE, UCHE, AUDREY, JADA, ALEXIS
    }, 3},
    {{
        ALIVIA, NICOLE, DIANDRA, ALEXIS, ZOE, NURYS,
        GELES, JADA, AUDREY, KEYANA, UCHE
    }, 1},
    {{
        NURYS, KEYANA, ALIVIA, ZOE, ALEXIS, UCHE,
        JADA, GELES, AUDREY, NICOLE, DIANDRA,
    }, 4},
    {{
        NURYS, KEYANA, ALEXIS, JADA, UCHE, AUDREY,
        ZOE, GELES, ALIVIA, NICOLE, DIANDRA
    }, 5}
};

// clang-format on