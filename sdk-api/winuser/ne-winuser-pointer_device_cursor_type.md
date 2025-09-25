# POINTER_DEVICE_CURSOR_TYPE enumeration

## Description

Identifies the pointer device cursor types.

## Constants

### `POINTER_DEVICE_CURSOR_TYPE_UNKNOWN:0x00000000`

Unidentified cursor.

### `POINTER_DEVICE_CURSOR_TYPE_TIP:0x00000001`

Pen tip.

### `POINTER_DEVICE_CURSOR_TYPE_ERASER:0x00000002`

Pen eraser.

### `POINTER_DEVICE_CURSOR_TYPE_MAX:0xFFFFFFFF`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. You should not use this value.

## Remarks

Cursor objects represent pointing and selecting devices used with digitizer devices, most commonly tactile contacts on touch digitizers and tablet pens on pen digitizers. Physical pens may have multiple tips (such as normal and eraser ends), with each pen tip representing a different cursor object. Each cursor object has an associated cursor identifier.

## See also

[Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/input_pointerdevice/enumerations)