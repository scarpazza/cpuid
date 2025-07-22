
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
    { "P5",                   1993, "?",                              0, 5, 0x0, 0x3 }, // Allen

    { "P5 MMX ",              1993, "P54CS Pentium 75",               0, 5, 0x0, 0x2 },
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




    // AMD



   FM  ( 0, 4,  0, 3,         *u = "Am486");
   FM  ( 0, 4,  0, 7,         *u = "Am486");
   FM  ( 0, 4,  0, 8,         *u = "Am486");
   FM  ( 0, 4,  0, 9,         *u = "Am486");
   F   ( 0, 4,                *u = "Am5x86");
   FM  ( 0, 5,  0, 6,         *u = "K6",          *p = ".30um");
   FM  ( 0, 5,  0, 7,         *u = "K6",          *p = ".25um"); // *p from sandpile.org
   FM  ( 0, 5,  0,13,         *u = "K6",          *p = ".18um"); // *p from sandpile.org
   F   ( 0, 5,                *u = "K6");
   FM  ( 0, 6,  0, 1,         *u = "K7",          *p = ".25um");
   FM  ( 0, 6,  0, 2,         *u = "K7",          *p = ".18um");
   F   ( 0, 6,                *u = "K7");
   FMS ( 0,15,  0, 4,  8,     *u = "K8",          *p = "754-pin, .13um");
   FM  ( 0,15,  0, 4,         *u = "K8",          *p = "940-pin, .13um");
   FM  ( 0,15,  0, 5,         *u = "K8",          *p = "940-pin, .13um");
   FM  ( 0,15,  0, 7,         *u = "K8",          *p = "939-pin, .13um");
   FM  ( 0,15,  0, 8,         *u = "K8",          *p = "754-pin, .13um");
   FM  ( 0,15,  0,11,         *u = "K8",          *p = "939-pin, .13um");
   FM  ( 0,15,  0,12,         *u = "K8",          *p = "754-pin, .13um");
   FM  ( 0,15,  0,14,         *u = "K8",          *p = "754-pin, .13um");
   FM  ( 0,15,  0,15,         *u = "K8",          *p = "939-pin, .13um");
   FM  ( 0,15,  1, 4,         *u = "K8",          *p = "754-pin, 90nm");
   FM  ( 0,15,  1, 5,         *u = "K8",          *p = "940-pin, 90nm");
   FM  ( 0,15,  1, 7,         *u = "K8",          *p = "939-pin, 90nm");
   FM  ( 0,15,  1, 8,         *u = "K8",          *p = "754-pin, 90nm");
   FM  ( 0,15,  1,11,         *u = "K8",          *p = "939-pin, 90nm");
   FM  ( 0,15,  1,12,         *u = "K8",          *p = "754-pin, 90nm");
   FM  ( 0,15,  1,15,         *u = "K8",          *p = "939-pin, 90nm");
   FM  ( 0,15,  2, 1,         *u = "K8",          *p = "940-pin, 90nm");
   FM  ( 0,15,  2, 3,         *u = "K8",          *p = "939-pin, 90nm");
   FM  ( 0,15,  2, 4,         *u = "K8",          *p = "754-pin, 90nm");
   FM  ( 0,15,  2, 5,         *u = "K8",          *p = "940-pin, 90nm");
   FM  ( 0,15,  2, 7,         *u = "K8",          *p = "939-pin, 90nm");
   FM  ( 0,15,  2,11,         *u = "K8",          *p = "939-pin, 90nm");
   FM  ( 0,15,  2,12,         *u = "K8",          *p = "754-pin, 90nm");
   FM  ( 0,15,  2,15,         *u = "K8",          *p = "939-pin, 90nm");
   FM  ( 0,15,  4, 1,         *u = "K8",          *p = "90nm");
   FM  ( 0,15,  4, 3,         *u = "K8",          *p = "90nm");
   FM  ( 0,15,  4, 8,         *u = "K8",          *p = "90nm");
   FM  ( 0,15,  4,11,         *u = "K8",          *p = "90nm");
   FM  ( 0,15,  4,12,         *u = "K8",          *p = "90nm");
   FM  ( 0,15,  4,15,         *u = "K8",          *p = "90nm");
   FM  ( 0,15,  5,13,         *u = "K8",          *p = "90nm");
   FM  ( 0,15,  5,15,         *u = "K8",          *p = "90nm");
   FM  ( 0,15,  6, 8,         *u = "K8",          *p = "65nm");
   FM  ( 0,15,  6,11,         *u = "K8",          *p = "65nm");
   FM  ( 0,15,  6,12,         *u = "K8",          *p = "65nm");
   FM  ( 0,15,  6,15,         *u = "K8",          *p = "65nm");
   FM  ( 0,15,  7,12,         *u = "K8",          *p = "65nm");
   FM  ( 0,15,  7,15,         *u = "K8",          *p = "65nm");
   FM  ( 0,15, 12, 1,         *u = "K8",          *p = "90nm");


     FM  ( 1,15,  0, 0,         *u = "K10",         *p = "65nm"); // sandpile.org
   FM  ( 1,15,  0, 2,         *u = "K10",         *p = "65nm");
   FM  ( 1,15,  0, 4,         *u = "K10",         *p = "45nm");
   FM  ( 1,15,  0, 5,         *u = "K10",         *p = "45nm");
   FM  ( 1,15,  0, 6,         *u = "K10",         *p = "45nm");
   FM  ( 1,15,  0, 8,         *u = "K10",         *p = "45nm");
   FM  ( 1,15,  0, 9,         *u = "K10",         *p = "45nm");
   FM  ( 1,15,  0,10,         *u = "K10",         *p = "45nm");
   F   ( 2,15,                *u = "Puma 2008",   *p = "65nm");
   F   ( 3,15,                *u = "K10",         *p = "32nm");
   F   ( 5,15,                *u = "Bobcat",      *p = "40nm");
   FM  ( 6,15,  0, 0,         *u = "Bulldozer",   *p = "32nm"); // instlatx64 engr sample
   FM  ( 6,15,  0, 1,         *u = "Bulldozer",   *p = "32nm");
   FM  ( 6,15,  0, 2,         *u = "Piledriver",  *p = "32nm");
   FM  ( 6,15,  1, 0,         *u = "Piledriver",  *p = "32nm");
   FM  ( 6,15,  1, 3,         *u = "Piledriver",  *p = "32nm");
   FM  ( 6,15,  3, 0,         *u = "Steamroller", *p = "28nm");
   FM  ( 6,15,  3, 8,         *u = "Steamroller", *p = "28nm");
   FM  ( 6,15,  4, 0,         *u = "Steamroller", *p = "28nm"); // Software Optimization Guide (15h) says it has the same inst latencies as (6,15),(3,x).
   FM  ( 6,15,  6, 0,         *u = "Excavator",   *p = "28nm"); // undocumented, but instlatx64 samples
   FM  ( 6,15,  6, 5,         *u = "Excavator",   *p = "28nm"); // undocumented, but sample from Alexandros Couloumbis
   FM  ( 6,15,  7, 0,         *u = "Excavator",   *p = "28nm");
   FM  ( 7,15,  0, 0,         *u = "Jaguar",      *p = "28nm");
   FM  ( 7,15,  2, 6,         *u = "Cato",        *p = "28nm"); // only instlatx64 example; engr sample?
   FM  ( 7,15,  3, 0,         *u = "Puma 2014",   *p = "28nm");
   // In Zen-based CPUs, the model uses only the extended model and the
   // high-order bit of the model.  The low-order 3 bits of the model are part
   // of the stepping.
   FMm ( 8,15,  0, 0,         *u = "Zen",         *p = "14nm");
   FMm ( 8,15,  0, 8,         *u = "Zen+",        *p = "12nm");
   FMm ( 8,15,  1, 0,         *u = "Zen",         *p = "14nm"); // found only on en.wikichip.org & instlatx64 examples
   FMm ( 8,15,  1, 8,         *u = "Zen+",        *p = "12nm");
   FMm ( 8,15,  2, 0,         *u = "Zen",         *p = "14nm");
   FMm ( 8,15,  3, 0,         *u = "Zen 2",       *p = "7nm");  // found only on en.wikichip.org
   FMm ( 8,15,  4, 0,         *u = "Zen 2",       *p = "7nm");  // only instlatx64 example; engr sample?
   FMm ( 8,15,  6, 0,         *u = "Zen 2",       *p = "7nm");
   FMm ( 8,15,  6, 8,         *u = "Zen 2",       *p = "7nm");  // undocumented, but instlatx64 samples
   FMm ( 8,15,  7, 0,         *u = "Zen 2",       *p = "7nm");  // undocumented, but samples from Steven Noonan
   FMm ( 8,15,  8, 0,         *u = "Zen 2",       *p = "7nm");  // undocumented, but sample via instlatx64
   FMm ( 8,15,  9, 0,         *u = "Zen 2",       *p = "7nm");  // undocumented, but sample via instlatx64 from @patrickschur_
   FMm ( 8,15,  9, 8,         *u = "Zen 2",       *p = "7nm");  // undocumented, but sample via instlatx64 from @zimogorets
   FMm ( 8,15, 10, 0,         *u = "Zen 2",       *p = "7nm");  // sample via instlatx64 from @ExecuFix
   FMm (10,15,  0, 0,         *u = "Zen 3",       *p = "TSMC 7nm");
   FMm (10,15,  0, 8,         *u = "Zen 3",       *p = "TSMC 7nm");  // undocumented, but sample via instlatx64 from @ExecuFix
   FMm (10,15,  1, 0,         *u = "Zen 4",       *p = "TSMC N5");
   FMm (10,15,  1, 8,         *u = "Zen 4",       *p = "TSMC 5FF");  // undocumented, but sample via instlatx64 from @patrickschur_
   FMm (10,15,  2, 0,         *u = "Zen 3",       *p = "TSMC 7FF");
   FMm (10,15,  3, 0,         *u = "Zen 3",       *p = "TSMC N5P");  // undocumented, but sample via instlatx64 from @patrickschur_
   FMm (10,15,  4, 0,         *u = "Zen 3",       *p = "TSMC N6");  // undocumented, but instlatx64 sample
   FMm (10,15,  5, 0,         *u = "Zen 3",       *p = "TSMC 7nm");
   FMm (10,15,  6, 0,         *u = "Zen 4",       *p = "TSMC N5");  // undocumented, but instlatx64 sample
   FMm (10,15,  7, 0,         *u = "Zen 4",       *p = "TSMC 4nm");  // undocumented, but engr sample via instlatx64 from bakerlab.org (6220795)
   FMm (10,15,  7, 8,         *u = "Zen 4",       *p = "TSMC 4nm");  // Coreboot*
   FMm (10,15,  8, 0,         *u = "Zen 4",       *p = "TSMC N5");  // undocumented, but LKML: https://lkml.org/lkml/2023/7/21/835 from AMD's Yazen Ghannam
   FMm (10,15,  9, 0,         *u = "Zen 4",       *p = "TSMC N5");  // undocumented, but LKML: https://lkml.org/lkml/2023/7/21/835 from AMD's Yazen Ghannam
   FMm (10,15, 10, 0,         *u = "Zen 4c",      *p = "TSMC N5");




   FMm (11,15,  0, 0,         *u = "Zen 5",       *p = "TSMC N4P");  // LX* & tangentially documented: 58088 AMD 1Ah Models 00h-0Fh and Models 10h-1Fh ACPI v6.5 Porting Guide
   FMm (11,15,  0, 8,         *u = "Zen 5",       *p = "TSMC N4P");  // undocumented, but LLVM patch from AMD's Ganesh Gopalasubramanian
   FMm (11,15,  1, 0,         *u = "Zen 5c",      *p = "TSMC N3");  // tangentially documented: 58088 AMD 1Ah Models 00h-0Fh and Models 10h-1Fh ACPI v6.5 Porting Guide
   FMm (11,15,  1, 8,         *u = "Zen 5c",      *p = "TSMC N3");  // undocumented, but LLVM patch from AMD's Ganesh Gopalasubramanian
   FMm (11,15,  2, 0,         *u = "Zen 5",       *p = "TSMC N4P");  // undocumented, but engr sample via instlatx64 from milkyway.cs.rpi.edu (996435)
   FMm (11,15,  2, 8,         *u = "Zen 5",       *p = "TSMC N4P");  // undocumented, but LLVM patch from AMD's Ganesh Gopalasubramanian
   FMm (11,15,  3, 0,         *u = "Zen 5",       *p = "TSMC N4P");  // undocumented, but LLVM patch from AMD's Ganesh Gopalasubramanian
   FMm (11,15,  3, 8,         *u = "Zen 5",       *p = "TSMC N4P");  // undocumented, but LLVM patch from AMD's Ganesh Gopalasubramanian
   FMm (11,15,  4, 0,         *u = "Zen 5",       *p = "TSMC N4P");  // undocumented, but LX* & engr sample via instlatx64 from einsteinathome.org (13142934)
   FMm (11,15,  4, 8,         *u = "Zen 5",       *p = "TSMC N4P");  // undocumented, but LLVM patch from AMD's Ganesh Gopalasubramanian
   FMm (11,15,  5, 0,         *u = "Zen 5",       *p = "TSMC N4P");  // undocumented, but LLVM patch from AMD's Ganesh Gopalasubramanian
   FMm (11,15,  5, 8,         *u = "Zen 5",       *p = "TSMC N4P");  // undocumented, but LLVM patch from AMD's Ganesh Gopalasubramanian
   FMm (11,15,  6, 0,         *u = "Zen 5",       *p = "TSMC N4P");  // undocumented, but engr sample via instlatx64 from @kepler_l2
   FMm (11,15,  6, 8,         *u = "Zen 5",       *p = "TSMC N4P");  // undocumented, but LLVM patch from AMD's Ganesh Gopalasubramanian
   FMm (11,15,  7, 0,         *u = "Zen 5",       *p = "TSMC N4P");  // undocumented, but LX* & engr sample via instlatx64 from @kepler_l2
   FMm (11,15,  7, 8,         *u = "Zen 5",       *p = "TSMC N4P");  // undocumented, but LLVM patch from AMD's Ganesh Gopalasubramanian

};
