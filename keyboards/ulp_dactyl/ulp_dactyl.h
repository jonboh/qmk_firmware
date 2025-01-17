#pragma once

#define ____ KC_NO

#define LAYOUT( \
    L00, L01, L02, L03, L04,                     R04, R03, R02, R01, R00, \
    L10, L11, L12, L13, L14,                     R14, R13, R12, R11, R10, \
    L20, L21, L22, L23, L24,                     R24, R23, R22, R21, R20, \
    L40,           L44, L34,                     R34, R44,           R40, \
                   L43, L33,                          R43, \
                   L42,                               R42 \
                            ) { \
    { L04, L03, L02, L01, L00 }, \
    { L14, L13, L12, L11, L10 }, \
    { L24, L23, L22, L21, L20 }, \
    { L34, L33, ____, ____, ____ }, \
    { L44, L43, L42, ____, L40 }, \
\
    { R04, R03, R02, R01, R00 }, \
    { R14, R13, R12, R11, R10 }, \
    { R24, R23, R22, R21, R20 }, \
    { R34, ____, ____, ____, ____ }, \
    { R44, R43, R42, ____, R40 } \
}
//bfzhnionue,.aoqi;acccaafffaaccggffeeeeeeeggffffffggg
