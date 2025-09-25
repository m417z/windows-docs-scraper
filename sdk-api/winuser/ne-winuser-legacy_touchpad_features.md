# LEGACY_TOUCHPAD_FEATURES enumeration

## Description

Identifies the settings for which a legacy touchpad has indicated support.

## Constants

### `LEGACY_TOUCHPAD_FEATURE_NONE:0x00000000`

No touchpad features are supported (or no legacy touchpad is detected).

### `LEGACY_TOUCHPAD_FEATURE_ENABLE_DISABLE:0x00000001`

The legacy touchpad supports being enabled and disabled.

### `LEGACY_TOUCHPAD_FEATURE_REVERSE_SCROLL_DIRECTION:0x00000004`

The legacy touchpad supports reversing its scroll direction.

## Remarks

When the corresponding setting is updated with SPIF_UPDATEINIFILE (to persist the setting), the legacy touchpad will respond accordingly.

## See also

[TOUCHPAD_PARAMETERS structure](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-touchpad_parameters)