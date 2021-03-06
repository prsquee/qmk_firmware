#pragma once

#ifdef AUDIO_ENABLE
    /* #define STARTUP_SONG SONG(ONE_UP_SOUND) */
    #define STARTUP_SONG SONG( H__NOTE(_G5), H__NOTE(_FS5), H__NOTE(_E5), H__NOTE(_E5), W__NOTE(_FS5))
    #define DEFAULT_LAYER_SONGS { SONG(SONIC_RING), SONG(COIN_SOUND) }

    #define STILL_ALIVE H__NOTE(_A4), H__NOTE(_AS4), W__NOTE(_C5),  W__NOTE(_F5),  H__NOTE(_E5), H__NOTE(_D5), \
                        H__NOTE(_D5), H__NOTE(_C5),  H__NOTE(_D5),  H__NOTE(_C5),  W__NOTE(_C5), W__NOTE(_C5), \
                        H__NOTE(_A4), H__NOTE(_AS4), W__NOTE(_C5),  W__NOTE(_F5),  H__NOTE(_G5), H__NOTE(_F5), \
                        H__NOTE(_E5), H__NOTE(_D5),  H__NOTE(_D5),  H__NOTE(_E5),  W__NOTE(_F5), W__NOTE(_F5), \
                        H__NOTE(_G5), H__NOTE(_A5),  H__NOTE(_AS5), H__NOTE(_AS5), W__NOTE(_A5), W__NOTE(_G5), \
                        H__NOTE(_F5), H__NOTE(_G5),  H__NOTE(_A5),  H__NOTE(_A5),  W__NOTE(_G5), W__NOTE(_F5), \
                        H__NOTE(_D5), H__NOTE(_C5),  H__NOTE(_D5),  H__NOTE(_F5),  H__NOTE(_F5), W__NOTE(_E5), \
                        H__NOTE(_E5), H__NOTE(_FS5), H__NOTE(_FS5)
#endif

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

// enable click sound for each keypress
#define AUDIO_CLICKY
