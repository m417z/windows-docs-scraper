# IWiaDevMgr::RegisterEventCallbackProgram

## Description

The **IWiaDevMgr::RegisterEventCallbackProgram** method registers an application to receive device events. It is primarily provided for backward compatibility with applications that were not written for WIA.

## Parameters

### `lFlags` [in]

Type: **LONG**

Specifies registration flags. Can be set to the following values:

| Registration Flag | Meaning |
| --- | --- |
| WIA_REGISTER_EVENT_CALLBACK | Register for the event. |
| WIA_UNREGISTER_EVENT_CALLBACK | Delete the registration for the event. |
| WIA_SET_DEFAULT_HANDLER | Set the application as the default event handler. |

### `bstrDeviceID` [in]

Type: **BSTR**

Specifies a device identifier. Pass **NULL** to register for the event on all WIA devices.

### `pEventGUID` [in]

Type: **const GUID***

Specifies the event for which the application is registering. For a list of valid event GUIDs, see [WIA Event Identifiers](https://learn.microsoft.com/windows/desktop/wia/-wia-wia-event-identifiers).

### `bstrCommandline` [in]

Type: **BSTR**

Specifies a string that contains the full path name and the appropriate command-line arguments needed to invoke the application. Two pairs of quotation marks should be used, for example, "\"C:\Program Files\MyExe.exe\" /arg1".

### `bstrName` [in]

Type: **BSTR**

Specifies the name of the application. This name is displayed to the user when multiple applications register for the same event.

### `bstrDescription` [in]

Type: **BSTR**

Specifies the description of the application. This description is displayed to the user when multiple applications register for the same event.

### `bstrIcon` [in]

Type: **BSTR**

Specifies the icon that represents the application. The icon is displayed to the user when multiple applications register for the same event. The string contains the name of the application and the 0-based index of the icon (there may be more than one icon that represent application) separated by a comma. For example, "MyApp, 0".

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Use **IWiaDevMgr::RegisterEventCallbackProgram** to register for hardware device events of the type WIA_ACTION_EVENT. When an event occurs for which an application is registered, the application is launched and the event information is transmitted to the application.

Applications use the [EnumRegisterEventInfo](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiaitem-enumregistereventinfo) method to retrieve a pointer to an enumerator object for event registration properties.

An application can find whether an event is an action type or notification type (or both) event by examining the **ulFlags** value of a [WIA_DEV_CAP](https://learn.microsoft.com/windows/desktop/api/wia_xp/ns-wia_xp-wia_dev_cap) structure returned by event enumeration.

Programs should only use the **IWiaDevMgr::RegisterEventCallbackProgram** method for backward compatibility with applications not written for the WIA architecture. New applications should use the Component Object Model (COM) interfaces provided by the WIA architecture. Specifically, they should call [IWiaDevMgr::RegisterEventCallbackInterface](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiadevmgr-registereventcallbackinterface) or [IWiaDevMgr::RegisterEventCallbackCLSID](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiadevmgr-registereventcallbackclsid) to register for device events.

Typically, this method is called by an install program or a script. The install program or script registers the application to receive WIA device events. When the event occurs, the application will be started by the WIA run-time system.