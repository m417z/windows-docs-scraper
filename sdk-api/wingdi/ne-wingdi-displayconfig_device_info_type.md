# DISPLAYCONFIG_DEVICE_INFO_TYPE enumeration

## Description

The DISPLAYCONFIG_DEVICE_INFO_TYPE enumeration specifies the type of display device info to configure or obtain through the [DisplayConfigSetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-displayconfigsetdeviceinfo) or [DisplayConfigGetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-displayconfiggetdeviceinfo) function.

## Constants

### `DISPLAYCONFIG_DEVICE_INFO_GET_SOURCE_NAME:1`

Specifies the source name of the display device. If the [DisplayConfigGetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-displayconfiggetdeviceinfo) function is successful, **DisplayConfigGetDeviceInfo** returns the source name in the [DISPLAYCONFIG_SOURCE_DEVICE_NAME](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_source_device_name) structure.

### `DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_NAME:2`

Specifies information about the monitor. If the [DisplayConfigGetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-displayconfiggetdeviceinfo) function is successful, **DisplayConfigGetDeviceInfo** returns info about the monitor in the [DISPLAYCONFIG_TARGET_DEVICE_NAME](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_target_device_name) structure.

### `DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_PREFERRED_MODE:3`

Specifies information about the preferred mode of a monitor. If the [DisplayConfigGetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-displayconfiggetdeviceinfo) function is successful, **DisplayConfigGetDeviceInfo** returns info about the preferred mode of a monitor in the [DISPLAYCONFIG_TARGET_PREFERRED_MODE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_target_preferred_mode) structure.

### `DISPLAYCONFIG_DEVICE_INFO_GET_ADAPTER_NAME:4`

Specifies the graphics adapter name. If the [DisplayConfigGetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-displayconfiggetdeviceinfo) function is successful, **DisplayConfigGetDeviceInfo** returns the adapter name in the [DISPLAYCONFIG_ADAPTER_NAME](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_adapter_name) structure.

### `DISPLAYCONFIG_DEVICE_INFO_SET_TARGET_PERSISTENCE:5`

Specifies how to set the monitor. If the [DisplayConfigSetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-displayconfigsetdeviceinfo) function is successful, **DisplayConfigSetDeviceInfo** uses info in the [DISPLAYCONFIG_SET_TARGET_PERSISTENCE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_set_target_persistence) structure to force the output in a boot-persistent manner.

### `DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_BASE_TYPE:6`

Specifies how to set the base output technology for a given target ID. If the [DisplayConfigGetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-displayconfiggetdeviceinfo) function is successful, **DisplayConfigGetDeviceInfo** returns base output technology info in the [DISPLAYCONFIG_TARGET_BASE_TYPE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_target_base_type) structure.

Supported by WDDM 1.3 and later user-mode display drivers running on Windows 8.1 and later.

### `DISPLAYCONFIG_DEVICE_INFO_GET_SUPPORT_VIRTUAL_RESOLUTION:7`

Specifies the state of virtual mode support. If the [DisplayConfigGetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-displayconfiggetdeviceinfo) function is successful, **DisplayConfigGetDeviceInfo** returns virtual mode support information in the [DISPLAYCONFIG_SUPPORT_VIRTUAL_RESOLUTION](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_support_virtual_resolution) structure. Supported starting in Windows 10.

### `DISPLAYCONFIG_DEVICE_INFO_SET_SUPPORT_VIRTUAL_RESOLUTION:8`

Specifies how to set the state of virtual mode support. If the [DisplayConfigSetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-displayconfigsetdeviceinfo) function is successful, **DisplayConfigSetDeviceInfo** uses info in the [DISPLAYCONFIG_SUPPORT_VIRTUAL_RESOLUTION](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_support_virtual_resolution) structure to change the state of virtual mode support. Supported starting in Windows 10.

### `DISPLAYCONFIG_DEVICE_INFO_GET_ADVANCED_COLOR_INFO:9`

### `DISPLAYCONFIG_DEVICE_INFO_SET_ADVANCED_COLOR_STATE:10`

### `DISPLAYCONFIG_DEVICE_INFO_GET_SDR_WHITE_LEVEL:11`

Specifies the current SDR white level for an HDR monitor. If the [DisplayConfigGetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-displayconfigsetdeviceinfo) function is successful, **DisplayConfigGetDeviceInfo** return SDR white level info in the [DISPLAYCONFIG_SDR_WHITE_LEVEL](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_sdr_white_level) structure.

Supported starting in Windows 10 Fall Creators Update (Version 1709).

### `DISPLAYCONFIG_DEVICE_INFO_FORCE_UINT32:0xFFFFFFFF`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. You should not use this value.

## See also

[DISPLAYCONFIG_ADAPTER_NAME](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_adapter_name)

[DISPLAYCONFIG_SET_TARGET_PERSISTENCE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_set_target_persistence)

[DISPLAYCONFIG_SOURCE_DEVICE_NAME](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_source_device_name)

[DISPLAYCONFIG_TARGET_BASE_TYPE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_target_base_type)

[DISPLAYCONFIG_TARGET_DEVICE_NAME](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_target_device_name)

[DISPLAYCONFIG_TARGET_PREFERRED_MODE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_target_preferred_mode)

[DisplayConfigGetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-displayconfiggetdeviceinfo)

[DisplayConfigSetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-displayconfigsetdeviceinfo)