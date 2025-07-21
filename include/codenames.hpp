
// source: https://en.wikichip.org/wiki/intel/cpuid


#pragma once

#include <cstdint>
#include <string_view>
#include <set>


using step_set = std::set<uint8_t>;

const step_set empty;


struct CodenameEntry {
  std::string_view  microarch;
  unsigned          year;
  std::string_view  core;
  uint8_t           extended_family;
  uint8_t           family;
  uint8_t           extended_model;
  uint8_t           model;
  step_set          steppings; // empty steppings set means "all steppings match"
};


const CodenameEntry codenames[] = {

    // Microarchitecture  year  Core name                           exfa fam  exmo model
    // family 19
    {"Diamond Rapids",        2025, "Panther Cove X",                 4, 0xF, 0x0, 0x1 },
    {"Nova Lake",             2026, "Coyote Cove, Arctic Wolf",       4, 0xF, 0x0, 0x0 },

    // family 15
    {"Modified Pentium M",    2006, "Cedar Mill, Dempsey",            0, 0xF, 0x0, 0x6 },
    {"Netburst (P68)",        2000, "Prescott",                       0, 0xF, 0x0, 0x4 },
    {"Netburst (P68)",        2000, "Prescott",                       0, 0xF, 0x0, 0x3 },
    {"Netburst (P68)",        2000, "Northwood",                      0, 0xF, 0x0, 0x2 },
    {"Netburst (P68)",        2000, "Willamette",                     0, 0xF, 0x0, 0x1 },

    // family 11
    {"Knights Corner",        2011, "62 cores",                       0, 0xB, 0x0, 0x1 },
    {"Knights Ferry",         2010, "32 cores",                       0, 0xB, 0x0, 0x6 },

    // family 6
    // family 11
    {"Knights Mill",          2017, "62 cores",                       0, 0x6, 0x8, 0x5 },
    {"Knights Landing",       2016, "32 cores",                       0, 0x6, 0x5, 0x7 },

    // small cores
    // TO DO


    // big cores - server
    { "Clearwater Forest",    2025, "CWF-AP, CWF-SP",                 0, 6, 0xD, 0xD },
    { "Sierra Forest",        2024, "Crestmont SP",                   0, 6, 0xA, 0xF },
    { "Granite Rapids",       2024, "Redwood Cove (D)",               0, 6, 0xA, 0xE },
    { "Granite Rapids",       2024, "Redwood Cove",                   0, 6, 0xA, 0xD },
    { "Emerald Rapids",       2023, "Golden Cove",                    0, 6, 0xC, 0xF },
    { "Sapphire Rapids",      2023, "Golden Cove SP",                 0, 6, 0x8, 0xF },
    { "Ice Lake (Server)",    2019, "DE",                             0, 6, 0x6, 0xC },
    { "Ice Lake (Server)",    2019, "SP",                             0, 6, 0x6, 0xA },
    { "Cooper Lake",          2015, "?",                              0, 6, 0x5, 0x5, step_set{11} },
    { "Cascade Lake",         2015, "SP, X, W",                       0, 6, 0x5, 0x5, step_set{5,6,7} },
    // ensure this is listed after the same models with specific steppings - entries are checked in order
    { "Skylake (Server)",     2015, "SP, X, DE, W",                   0, 6, 0x5, 0x5 /* all other steppings */ },

    {"Broadwell (Server)",    2014, "DE, Hewitt Lake",                0, 6, 0x5, 0x6 },
    {"Broadwell (Server)",    2014, "E, EP, EX",                      0, 6, 0x4, 0xF },
    {"Haswell (Server)",      2013, "E, EP, EX",                      0, 6, 0x3, 0xF },
    {"Ivy Bridge (Server)",   2012, "E, EN, EP, EX",                  0, 6, 0x3, 0xE },
    {"Sandy Bridge (Server)", 2011, "E, EN, EP",                      0, 6, 0x2, 0xD },
    {"Westmere (Server)",     2010, "EX",                             0, 6, 0x2, 0xF },
    {"Westmere (Server)",     2010, "EP, Gulftown",                   0, 6, 0x2, 0xC },
    {"Nehalem (Server)",      2008, "EX",                             0, 6, 0x2, 0xE },
    {"Nehalem (Server)",      2009, "Lynnfield",                      0, 6, 0x1, 0xE },
    {"Nehalem (Server)",      2008, "EP, WS, Bloomfield",             0, 6, 0x1, 0xA },

    {"Penryn (Server)",       2008, "Dunnington",                     0, 6, 0x1, 0xD },
    {"Penryn (Server)",       2007, "Harpertown, Penryn QC, Wolfdale, Yorkfield", 0, 6, 0x1, 0x7 },
    {"P6 (Pentium)",          1995, "",                               0, 6, 0x0, 0xA},


    // big cores - client
      // FUTURE { "Razer Lake","2027","Griffin Cove (P)/Golden Eagle (E)",0x0,6,0xC,? },
      // FUTURE { "Nova Lake","2026","Coyote Cove (P)/Arctic Wolf (E)",0x0,6,0xC,? },
      // FUTURE { "Wildcat Lake","2025","Cougar Cove (P)/Darkmont (LPE)",0x0,6,0xC,0xD },

    { "Panther Lake",         2025, "Cougar Cove / Darkmont",         0, 6, 0xC, 0xC },
    { "Bartlett Lake",        2025, "Raptor Cove (P)",                0, 6, 0xB, 0xF },
    { "Bartlett Lake",        2025, "Gracemont / BLL-N",              0, 6, 0xB, 0xE },
    { "Bartlett Lake",        2025, "Raptor Cove / BLL-P",            0, 6, 0xB, 0xA },
    { "Bartlett Lake",        2025, "Raptor Cove / BLL-S, Enhanced Gracemont", 0, 6, 0xB, 0x7 },

    { "Lunar Lake",           2024, "LNL-V, LNL-MX",                  0, 6, 0xB, 0xD },
    { "Lunar Lake",           2024, "Lion Cove, Skymont",             0, 6, 0xB, 0xC },

    { "Arrow Lake",           2024, "ARL-S",                          0, 6, 0xC, 0x6 },
    { "Arrow Lake",           2024, "Lion Cove ARL-H, Skymont",       0, 6, 0xC, 0x5 },
    { "Arrow Lake",           2024, "ARL-U",                          0, 6, 0xB, 0x5 },

    { "Meteor Lake",          2023, "Redwood Cove, Crestmont MTL-S",  0, 6, 0xA, 0xC },
    { "Meteor Lake",          2023, "MTL-N Crestmont",                0, 6, 0xA, 0xB },
    { "Meteor Lake",          2023, "MTL-N Crestmont",                0, 6, 0xA, 0xA },

    { "Raptor Lake",          2022, "Raptor Cove",                    0, 6, 0xB, 0xF }, // conflict
    { "Raptor Lake",          2022, "Gracemont RPL-N",                0, 6, 0xB, 0xE }, // conflict
    { "Raptor Lake",          2022, "Raptor Cove RPL-S, Enhanced Gracemont", 0, 6, 0xB, 0xA }, // conflict
    { "Raptor Lake",          2022, "Raptor Cove RPL-P",              0, 6, 0xB, 0xA }, // conflict

    { "Alder Lake",           2021, "Golden Cove ADL-P",              0, 6, 0x9, 0xA },
    { "Alder Lake",           2021, "ADL-S, Gracemont",               0, 6, 0x9, 0x7 },

    // monoprocessors (p-cores)
    { "Rocket Lake",          2021, "Cypress Cove RKL-S, RKL-U",      0, 6, 0xA, 0x7 },
    { "Comet Lake",           2020, "CML-U",                          0, 6, 0xA, 0x6 },
    { "Comet Lake",           2020, "CML-H, CML-S",                   0, 6, 0xA, 0x5 },

    { "Tiger Lake",           2020, "TGL-H",                          0, 6, 0x8, 0xD },
    { "Tiger Lake",           2020, "Willow Cove, TGL-U",             0, 6, 0x8, 0xC },

    { "Ice Lake (Client)",    2019, "Sunny Cove ICL-U",               0, 6, 0x7, 0xE },
    { "Ice Lake (Client)",    2019, "ICL-Y",                          0, 6, 0x7, 0xD },

    { "Cannon Lake",          2018, "Palm Cove CNL-U",                0, 6, 0x6, 0x6 },

    { "Coffee Lake",          2017, "CFL-H, CFL-S",                   0, 6, 0x9, 0xE},
    { "Coffee Lake",          2017, "CFL-U",                          0, 6, 0x8, 0xE, step_set{10} },

    // Attention - different order than wikichip
    { "Kaby Lake",            2016, "KBL-DT, KBL-X, KBL-H, KBL-S",    0, 6, 0x9, 0xE }, // conflict
    { "Amber Lake",           2016, "AML-Y",                          0, 6, 0x8, 0xE, step_set{9} },
    { "Whiskey Lake",         2016, "WHL-U",                          0, 6, 0x8, 0xE, step_set{11,12} },
    { "Kaby Lake",            2016, "KBL-Y,U",                        0, 6, 0x8, 0xE }, // keep this entry last of 6,8,E ones


    { "Skylake (Client)",     2015, "SKL-H, SKL-S, SKL-DT",           0, 6, 0x5, 0xE },
    { "Skylake (Client)",     2015, "SKL-Y, SKL-U",                   0, 6, 0x4, 0xE },



    { "Broadwell (Client)",   2014, "BDW-H, BDW-C, BDW-W",            0, 6, 0x4, 0x7 },
    { "Broadwell (Client)",   2014, "BDW-Y, BDW-U, BDW-S",            0, 6, 0x3, 0xD },


    { "Haswell (Client)",     2013, "HSW-MB",                         0, 6, 0x4, 0x6 },
    { "Haswell (Client)",     2013, "HSW-U",                          0, 6, 0x4, 0x5 },
    { "Haswell (Client)",     2013, "HSW-S",                          0, 6, 0x3, 0xC },

    { "Ivy Bridge (Client)",  2012, "IVB-M, IVB-H",                   0, 6, 0x3, 0xA },

    { "Sandy Bridge (Client)",2011, "SNB-M, SNB-H",                   0, 6, 0x2, 0xA },

    { "Westmere (Client)",    2010, "Arrandale, Clarkdale",           0, 6, 0x2, 0x5 },

    { "Nehalem (Client)",     2009, "Auburndale?, Havendale?",        0, 6, 0x1, 0xF },
    { "Nehalem (Client)",     2009, "Clarksfield",                    0, 6, 0x1, 0xE },

    { "Penryn (Client)",      2008, "Penryn, Wolfdale, Yorkfield",    0, 6, 0x1, 0x7 },

    { "Core (Client)",        2007, "Merom L",                        0, 6, 0x1, 0x6 },
    { "Core (Client)",        2007, "Merom",                          0, 6, 0x0, 0xF },

    { "Modified Pentium M",   2007, "Yonah",                          0, 6, 0x0, 0xE },

    { "Pentium M",            2007, "Tolapai",                        0, 6, 0x1, 0x5 },
    { "Pentium M",            2003, "Dothan",                         0, 6, 0x0, 0xD },
    { "Pentium M",            2003, "Banias",                         0, 6, 0x0, 0x9 },

    { "P6 Pentium",           2001, "Tualatin",                       0, 6, 0x0, 0xB },
    { "P6 Pentium",           1999, "Coppermine, Coppermine T",       0, 6, 0x0, 0x8 },
    { "P6 Pentium",           1999, "Katmai",                         0, 6, 0x0, 0x7 },
    { "P6 Pentium",           2000, "",                               0, 6, 0x0, 0x6 },
    { "P6 Pentium",           1998, "Deschutes",                      0, 6, 0x0, 0x5 },
    { "P6 Pentium",           1997, "Klamath Pentium II",             0, 6, 0x0, 0x3 },
    { "P6 Pentium",           1995, "Pentium Pro",                    0, 6, 0x0, 0x1 },

    // family 5

    { "Lakemont",             2013, "Quark D1000",                    0, 5, 0x0, 0xA },
    { "Lakemont",             2013, "Quark X1000",                    0, 5, 0x0, 0x9 },

    { "P5",                   1993, "P55C Mobile",                    0, 5, 0x0, 0x8 },
    { "P5",                   1993, "P55C Mobile",                    0, 5, 0x0, 0x7 },
    { "P5",                   1993, "P55C Pentium MMX",               0, 5, 0x0, 0x4 },
    { "P5",                   1993, "P54CS Pentium 75",               0, 5, 0x0, 0x2 },
    { "P5",                   1993, "Pentium P54CQS",                 0, 5, 0x0, 0x1 },
    { "P5",                   1993, "P5 A-step",                      0, 5, 0x0, 0x0 },



    // family 4
    { "Intel 486",            1993, "Intel 80486",                    0, 4, 0x0, 0x9 },
    { "Intel 486",            1994, "Intel 486DX4",                   0, 4, 0x0, 0x8 },
    { "Intel 486",            1989, "Intel 80486 (model 7)",          0, 4, 0x0, 0x7 },
    { "Intel 486",            1989, "Intel 80486 (model 5)",          0, 4, 0x0, 0x5 },
    { "Intel 486",            1992, "Intel 486SL",                    0, 4, 0x0, 0x4 },
    { "Intel 486",            1992, "Intel 486DX2",                   0, 4, 0x0, 0x3 },
    { "Intel 486",            1989, "Intel 486SX",                    0, 4, 0x0, 0x2 },
    { "Intel 486",            1989, "Intel 486DX",                    0, 4, 0x0, 0x1 },




    
};
