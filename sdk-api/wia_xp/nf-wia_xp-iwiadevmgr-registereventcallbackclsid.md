# IWiaDevMgr::RegisterEventCallbackCLSID

## Description

The **IWiaDevMgr::RegisterEventCallbackCLSID** method registers an application to receive events even if the application may not be running.

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

Specifies the event for which the application is registering. For a list of standard events, see [WIA Event Identifiers](https://learn.microsoft.com/windows/desktop/wia/-wia-wia-event-identifiers).

### `pClsID` [in]

Type: **const GUID***

Pointer to the application's class ID (**CLSID**). The WIA run-time system uses the application's **CLSID** to start the application when an event occurs for which it is registered.

### `bstrName` [in]

Type: **BSTR**

Specifies the name of the application that registers for the event.

### `bstrDescription` [in]

Type: **BSTR**

Specifies a text description of the application that registers for the event.

### `bstrIcon` [in]

Type: **BSTR**

Specifies the name of an image file to be used for the icon for the application that registers for the event.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

WIA applications use this method to register to receive hardware device events of the type WIA_ACTION_EVENT. Once programs call **IWiaDevMgr::RegisterEventCallbackCLSID**, they are registered to receive WIA device events even if they are not running.

When the event occurs, the WIA system determines which application is registered to receive the event. It uses the [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) function and the class ID specified in the *pClsID* parameter to create an instance of the application. It then calls the application's [ImageEventCallback](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiaeventcallback-imageeventcallback) method to transmit the event information.

An application can invoke the [EnumRegisterEventInfo](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiaitem-enumregistereventinfo) method to enumerate event registration information.

An application can find whether an event is an action type or notification type (or both) event by examining the **ulFlags** value of a [WIA_DEV_CAP](https://learn.microsoft.com/windows/desktop/api/wia_xp/ns-wia_xp-wia_dev_cap) structure returned by event enumeration.

If the application is not a registered Component Object Model (COM) component and is not compatible with the WIA architecture, developers should use [IWiaDevMgr::RegisterEventCallbackProgram](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiadevmgr-registereventcallbackprogram) instead of this method.

**Note** In a multi-threaded application, there is no guarantee that the event notification callback will come in on the same thread that registered the callback.