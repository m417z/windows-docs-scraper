# PHONE_LAMP_MODE enumeration

## Description

The
**PHONE_LAMP_MODE** enum provides indicators of a phone lamp's status.

## Constants

### `LM_DUMMY:0x1`

The lamp identifier has no corresponding lamp.

### `LM_OFF:0x2`

The lamp is off.

### `LM_STEADY:0x4`

The lamp is on steadily.

### `LM_WINK:0x8`

The lamp is winking, which means on and off at a normal rate.

### `LM_FLASH:0x10`

The lamp is flashing, which means a slow on and off.

### `LM_FLUTTER:0x20`

The lamp is fluttering, which means a fast on and off.

### `LM_BROKENFLUTTER:0x40`

The lamp is flashing, which means superposition of a flash and flutter.

### `LM_UNKNOWN:0x80`

The lamp mode is not known.

## See also

[ITPhone::get_LampMode](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-get_lampmode)

[ITPhone::put_LampMode](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-put_lampmode)