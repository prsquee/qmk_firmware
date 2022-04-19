#pragma once

#define AUDIO_INIT_DELAY
#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG( H__NOTE(_G5), H__NOTE(_FS5), H__NOTE(_E5), H__NOTE(_E5), W__NOTE(_FS5) )
    #define COIN E__NOTE(_A5), HD_NOTE(_E6)
    #define ZELDA1 Q__NOTE(_G5), Q__NOTE(_FS5), Q__NOTE(_DS5), Q__NOTE(_A4), Q__NOTE(_GS4), Q__NOTE(_E5), Q__NOTE(_GS5), HD_NOTE(_C6)
    #define ONE_UP Q__NOTE(_E6), Q__NOTE(_G6), Q__NOTE(_E7), Q__NOTE(_C7), Q__NOTE(_D7), Q__NOTE(_G7)
    #define DEFAULT_LAYER_SONGS { SONG(ZELDA1), SONG(COIN) }
    #define STILL_ALIVE H__NOTE(_A4), H__NOTE(_AS4), W__NOTE(_C5),  W__NOTE(_F5),  H__NOTE(_E5), H__NOTE(_D5), \
                        H__NOTE(_D5), H__NOTE(_C5),  H__NOTE(_D5),  H__NOTE(_C5),  W__NOTE(_C5), W__NOTE(_C5), \
                        H__NOTE(_A4), H__NOTE(_AS4), W__NOTE(_C5),  W__NOTE(_F5),  H__NOTE(_G5), H__NOTE(_F5), \
                        H__NOTE(_E5), H__NOTE(_D5),  H__NOTE(_D5),  H__NOTE(_E5),  W__NOTE(_F5), W__NOTE(_F5), \
                        H__NOTE(_G5), H__NOTE(_A5),  H__NOTE(_AS5), H__NOTE(_AS5), W__NOTE(_A5), W__NOTE(_G5), \
                        H__NOTE(_F5), H__NOTE(_G5),  H__NOTE(_A5),  H__NOTE(_A5),  W__NOTE(_G5), W__NOTE(_F5), \
                        H__NOTE(_D5), H__NOTE(_C5),  H__NOTE(_D5),  H__NOTE(_F5),  H__NOTE(_F5), W__NOTE(_E5), \
                        H__NOTE(_E5), H__NOTE(_FS5), H__NOTE(_FS5)
    #undef RICK_ROLL
    #define RICK_ROLL Q__NOTE(_F4),   \
                      Q__NOTE(_G4),   \
                      Q__NOTE(_BF4),  \
                      Q__NOTE(_G4),   \
                      HD_NOTE(_D5),   \
                      HD_NOTE(_D5),   \
                      W__NOTE(_C5),   \
                      S__NOTE(_REST), \
                      Q__NOTE(_F4),   \
                      Q__NOTE(_G4),   \
                      Q__NOTE(_BF4),  \
                      Q__NOTE(_G4),   \
                      HD_NOTE(_C5),   \
                      HD_NOTE(_C5),   \
                      W__NOTE(_BF4),  \
                      S__NOTE(_REST), \
                      Q__NOTE(_F4),   \
                      Q__NOTE(_G4),   \
                      Q__NOTE(_BF4),  \
                      Q__NOTE(_G4),   \
                      W__NOTE(_BF4),  \
                      H__NOTE(_C5),   \
                      H__NOTE(_A4),   \
                      H__NOTE(_A4),   \
                      H__NOTE(_G4),   \
                      H__NOTE(_F4),   \
                      H__NOTE(_F4),   \
                      W__NOTE(_C5),   \
                      W__NOTE(_BF4)

#endif

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

// enable click sound for each keypress
#define AUDIO_CLICKY
