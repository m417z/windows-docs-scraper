# DisplayConfigSetDeviceInfo function

## Description

The **DisplayConfigSetDeviceInfo** function sets the properties of a target.

## Parameters

### `setPacket` [in]

A pointer to a [DISPLAYCONFIG_DEVICE_INFO_HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_device_info_header) structure that contains information to set for the device. The type and size of additional data that **DisplayConfigSetDeviceInfo** uses for the configuration comes after the header structure. This additional data depends on the packet type, as specified by the **type** member of DISPLAYCONFIG_DEVICE_INFO_HEADER. For example, if the caller wants to change the boot persistence, that caller allocates and fills a [DISPLAYCONFIG_SET_TARGET_PERSISTENCE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_set_target_persistence) structure and passes a pointer to this structure in *setPacket*. Note that the first member of the DISPLAYCONFIG_SET_TARGET_PERSISTENCE structure is the DISPLAYCONFIG_DEVICE_INFO_HEADER.

## Return value

The function returns one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function succeeded. |
| **ERROR_INVALID_PARAMETER** | The combination of parameters and flags specified are invalid. |
| **ERROR_NOT_SUPPORTED** | The system is not running a graphics driver that was written according to the [Windows Display Driver Model (WDDM)](https://learn.microsoft.com/windows-hardware/drivers/display/windows-vista-display-driver-model-design-guide). The function is only supported on a system with a WDDM driver running. |
| **ERROR_ACCESS_DENIED** | The caller does not have access to the console session. This error occurs if the calling process does not have access to the current desktop or is running on a remote session. |
| **ERROR_INSUFFICIENT_BUFFER** | The size of the packet that the caller passes is not big enough. |
| **ERROR_GEN_FAILURE** | An unspecified error occurred. |

## Remarks

**DisplayConfigSetDeviceInfo** can currently only be used to start and stop boot persisted force projection on an analog target. For more information about boot persistence, see [Forced Versus Connected Targets](https://learn.microsoft.com/windows-hardware/drivers/display/forced-versus-connected-targets).

**DisplayConfigSetDeviceInfo** can only be used to set DISPLAYCONFIG_DEVICE_INFO_SET_XXX type of information. **DisplayConfigSetDeviceInfo** fails if the **type** member of [DISPLAYCONFIG_DEVICE_INFO_HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_device_info_header) is set to one of the DISPLAYCONFIG_DEVICE_INFO_GET_XXX values.

## See also

[DISPLAYCONFIG_DEVICE_INFO_HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_device_info_header)

[DisplayConfigGetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-displayconfiggetdeviceinfo)