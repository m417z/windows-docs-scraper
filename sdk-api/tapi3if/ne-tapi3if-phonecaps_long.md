# PHONECAPS_LONG enumeration

## Description

The
**PHONECAPS_LONG** enum is used by methods that set or get phone capabilities described by a long value.

## Constants

### `PCL_HOOKSWITCHES:0`

Specifies the hookswitch devices available using one or more members of the
[PHONE_HOOK_SWITCH_DEVICE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phone_hook_switch_device) enum.

### `PCL_HANDSETHOOKSWITCHMODES`

Specifies the handset hook switch modes.

### `PCL_HEADSETHOOKSWITCHMODES`

Specifies the headset hook switch modes.

### `PCL_SPEAKERPHONEHOOKSWITCHMODES`

Specifies the speakerphone hook switch modes.

### `PCL_DISPLAYNUMROWS`

Specifies the number of rows in a phone display device.

### `PCL_DISPLAYNUMCOLUMNS`

Specifies the number of columns in a phone display device.

### `PCL_NUMRINGMODES`

Specifies the number of ring modes.

If a USB phone returns zero for this value, the phone typically does not have a ringer device. The ringing sound plays on the default audio device for the system; for example, on sound card speakers.

### `PCL_NUMBUTTONLAMPS`

Specifies the number of button lamps.

### `PCL_GENERICPHONE`

Specifies whether the phone is generic: a value of one indicates it is, a value of zero indicates it is not.

A generic phone is a phone device that declares itself as available on all addresses that support audio terminals. For example, a USB phone is generic, because it is not tied to a specific TAPI address.

## See also

[ITPhone::get_PhoneCapsLong](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-get_phonecapslong)