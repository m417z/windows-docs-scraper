# DISPLAYCONFIG_SCANLINE_ORDERING enumeration

## Description

The DISPLAYCONFIG_SCANLINE_ORDERING enumeration specifies the method that the display uses to create an image on a screen.

## Constants

### `DISPLAYCONFIG_SCANLINE_ORDERING_UNSPECIFIED:0`

Indicates that scan-line ordering of the output is unspecified. The caller can only set the **scanLineOrdering** member of the [DISPLAYCONFIG_PATH_TARGET_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_path_target_info) structure in a call to the [SetDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdisplayconfig) function to DISPLAYCONFIG_SCANLINE_ORDERING_UNSPECIFIED if the caller also set the refresh rate denominator and numerator of the **refreshRate** member both to zero. In this case, **SetDisplayConfig** uses the best refresh rate it can find.

### `DISPLAYCONFIG_SCANLINE_ORDERING_PROGRESSIVE:1`

Indicates that the output is a progressive image.

### `DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED:2`

Indicates that the output is an interlaced image that is created beginning with the upper field.

### `DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED_UPPERFIELDFIRST`

Indicates that the output is an interlaced image that is created beginning with the upper field.

### `DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED_LOWERFIELDFIRST:3`

Indicates that the output is an interlaced image that is created beginning with the lower field.

### `DISPLAYCONFIG_SCANLINE_ORDERING_FORCE_UINT32:0xFFFFFFFF`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. You should not use this value.