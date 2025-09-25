# DISPLAYCONFIG_MODE_INFO_TYPE enumeration

## Description

The DISPLAYCONFIG_MODE_INFO_TYPE enumeration specifies that the information that is contained within the [DISPLAYCONFIG_MODE_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_mode_info) structure is either source or target mode.

## Constants

### `DISPLAYCONFIG_MODE_INFO_TYPE_SOURCE:1`

Indicates that the [DISPLAYCONFIG_MODE_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_mode_info) structure contains source mode information.

### `DISPLAYCONFIG_MODE_INFO_TYPE_TARGET:2`

Indicates that the [DISPLAYCONFIG_MODE_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_mode_info) structure contains target mode information.

### `DISPLAYCONFIG_MODE_INFO_TYPE_DESKTOP_IMAGE:3`

Indicates that the [DISPLAYCONFIG_MODE_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_mode_info) structure contains a valid [DISPLAYCONFIG_DESKTOP_IMAGE_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_desktop_image_info) structure. Supported starting in Windows 10.

### `DISPLAYCONFIG_MODE_INFO_TYPE_FORCE_UINT32:0xFFFFFFFF`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. You should not use this value.

## See also

[DISPLAYCONFIG_MODE_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_mode_info)