# DISPLAYCONFIG_ROTATION enumeration

## Description

The DISPLAYCONFIG_ROTATION enumeration specifies the clockwise rotation of the display.

## Constants

### `DISPLAYCONFIG_ROTATION_IDENTITY:1`

Indicates that rotation is 0 degrees—landscape mode.

### `DISPLAYCONFIG_ROTATION_ROTATE90:2`

Indicates that rotation is 90 degrees clockwise—portrait mode.

### `DISPLAYCONFIG_ROTATION_ROTATE180:3`

Indicates that rotation is 180 degrees clockwise—inverted landscape mode.

### `DISPLAYCONFIG_ROTATION_ROTATE270:4`

Indicates that rotation is 270 degrees clockwise—inverted portrait mode.

### `DISPLAYCONFIG_ROTATION_FORCE_UINT32:0xFFFFFFFF`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. You should not use this value.