# POINTER_DEVICE_TYPE enumeration

## Description

Identifies the pointer device types.

## Constants

### `POINTER_DEVICE_TYPE_INTEGRATED_PEN:0x00000001`

Direct pen digitizer (integrated into display).

### `POINTER_DEVICE_TYPE_EXTERNAL_PEN:0x00000002`

Indirect pen digitizer (not integrated into display).

### `POINTER_DEVICE_TYPE_TOUCH:0x00000003`

Touch digitizer.

### `POINTER_DEVICE_TYPE_TOUCH_PAD:0x00000004`

Touchpad digitizer (Windows 8.1 and later).

### `POINTER_DEVICE_TYPE_MAX:0xFFFFFFFF`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. You should not use this value.

## See also

[Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/input_pointerdevice/enumerations)