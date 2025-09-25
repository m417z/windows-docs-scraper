# _WIA_DEV_CAP_DRV structure

## Description

The WIA_DEV_CAP_DRV structure is used to enumerate device capabilities. A device capability is defined by an event or command that the device supports.

## Members

### `guid`

Points to a GUID that identifies the device capability. This member can be set to any of the values specified for WIA device commands (WIA_CMD_*XXX* commands) or WIA event identifiers (WIA_EVENT_*XXX* event identifiers). For more information, see [WIA Device Commands](https://learn.microsoft.com/windows/win32/wia/-wia-wia-device-commands).

The driver can define its own capability GUID that it can send down to the device. An application would need to have specific knowledge about that capability in order for it to be able to respond to the new capability, however. An application normally recognizes only the standard WIA command and event GUIDs (WIA_CMD_XXX and WIA_EVENT_XXX).

### `ulFlags`

Specifies the type of event. This member can be set to one or both of the following:

| Flag | Meaning |
| --- | --- |
| WIA_ACTION_EVENT | Application can register action for the given event using the [IWiaDevMgr::RegisterEventCallbackProgram](https://learn.microsoft.com/windows/win32/api/wia_xp/nf-wia_xp-iwiadevmgr-registereventcallbackprogram) and [IwiaDevMgr::RegisterEventCallbackCLSID](https://learn.microsoft.com/windows/win32/api/wia_xp/nf-wia_xp-iwiadevmgr-registereventcallbackclsid) methods. An action event launches the application that is registered to handle such an event. |
| WIA_NOTIFICATION_EVENT | Application can register for notification on the given event using the [IwiaDevMgr::RegisterEventCallbackInterface](https://learn.microsoft.com/windows/win32/api/wia_xp/nf-wia_xp-iwiadevmgr-registereventcallbackinterface) method. A notification event is sent only to applications that are already running. |

### `wszName`

Specifies a string that contains a short version of the capability name.

### `wszDescription`

Specifies a string containing the version of the capability name that can be displayed to the user.

### `wszIcon`

Specifies a string containing the name of the icon for this capability. The icon can be displayed to the user .

## Remarks

The WIA service calls the minidriver's [IWiaMiniDrv::drvGetCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvgetcapabilities) function to fill in the members of a WIA_DEV_CAP_DRV structure.

When a driver is enumerating event handlers, the only valid value is WIA_IS_DEFAULT_HANDLER; which indicates that the currently registered handler should be used.

## See also

[Driver Capabilities](https://learn.microsoft.com/windows-hardware/drivers/image/driver-capabilities)

[IWiaMiniDrv::drvGetCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvgetcapabilities)