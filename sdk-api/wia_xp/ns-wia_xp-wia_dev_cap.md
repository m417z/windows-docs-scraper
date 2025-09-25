# WIA_DEV_CAP structure

## Description

Applications use the **WIA_DEV_CAP** structure to enumerate device capabilities. A device capability is defined by an event or command that the device supports. For more information, see [IEnumWIA_DEV_CAPS](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-ienumwia_dev_caps).

## Members

### `guid`

Type: **GUID**

Specifies a GUID that identifies the device capability. This member can be set to any of the values specified in [WIA Device Commands](https://learn.microsoft.com/windows/desktop/wia/-wia-wia-device-commands) or [WIA Event Identifiers](https://learn.microsoft.com/windows/desktop/wia/-wia-wia-event-identifiers).

### `ulFlags`

Type: **ULONG**

Used when enumerating event handlers. The possible values are listed in this table.

| Value | Description |
| --- | --- |
| WIA_IS_DEFAULT_HANDLER | The currently registered handler should be used. This is the only valid value when enumerating event handlers. It is not a valid value when enumerating event capabilities of a device. |
| WIA_ACTION_EVENT | The event is of the action type, so programs that use persistent registration APIs, [IWiaDevMgr::RegisterEventCallbackProgram](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiadevmgr-registereventcallbackprogram) and [IWiaDevMgr::RegisterEventCallbackCLSID](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiadevmgr-registereventcallbackclsid), can receive it. |
| WIA_NOTIFICATION_EVENT | The event is of the notification type, so programs that use the runtime registration function, [IWiaDevMgr::RegisterEventCallbackInterface](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiadevmgr-registereventcallbackinterface), can receive it. |

### `bstrName`

Type: **BSTR**

Specifies a string that contains a short version of the capability name.

### `bstrDescription`

Type: **BSTR**

Specifies a string that contains a description of the capability that is displayed to the user.

### `bstrIcon`

Type: **BSTR**

Specifies a string that represents the location and resource ID of the icon that represents this capability or handler. The string must be of the following form: *drive***:\\***path***\\***module***,***n*, where *n* is the icon's negated resource ID (that is, if the resource ID of the icon is 100, then *n* is -100).

### `bstrCommandline`

Type: **BSTR**

Specifies a string that represents command line arguments.