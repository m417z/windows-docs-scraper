# TMGR_DIRECTION enumeration

## Description

The
**TMGR_DIRECTION** enum is used by the pluggable terminal methods to indicate terminal direction.

## Constants

### `TMGR_TD_CAPTURE:1`

The terminal can originate a media stream.

### `TMGR_TD_RENDER:2`

The terminal can render a media stream.

### `TMGR_TD_BOTH:3`

The terminal can handle both directions of a media stream.

## See also

[ITPluggableTerminalClassRegistration::get_Direction](https://learn.microsoft.com/windows/desktop/api/termmgr/nf-termmgr-itpluggableterminalclassregistration-get_direction)

[ITPluggableTerminalClassRegistration::put_Direction](https://learn.microsoft.com/windows/desktop/api/termmgr/nf-termmgr-itpluggableterminalclassregistration-put_direction)