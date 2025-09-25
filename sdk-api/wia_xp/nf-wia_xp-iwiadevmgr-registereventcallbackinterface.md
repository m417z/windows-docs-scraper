# IWiaDevMgr::RegisterEventCallbackInterface

## Description

The **IWiaDevMgr::RegisterEventCallbackInterface** method registers a running application Windows Image Acquisition (WIA) event notification.

## Parameters

### `lFlags` [in]

Type: **LONG**

Currently unused. Should be set to zero.

### `bstrDeviceID` [in]

Type: **BSTR**

Specifies a device identifier. Pass **NULL** to register for the event on all WIA devices.

### `pEventGUID` [in]

Type: **const GUID***

Specifies the event for which the application is registering. For a list of standard events, see [WIA Event Identifiers](https://learn.microsoft.com/windows/desktop/wia/-wia-wia-event-identifiers).

### `pIWiaEventCallback` [in]

Type: **[IWiaEventCallback](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaeventcallback)***

Pointer to the [IWiaEventCallback](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaeventcallback) interface that the WIA system used to send the event notification.

### `pEventObject` [out]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)****

Receives the address of a pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Warning** Using the **IWiaDevMgr::RegisterEventCallbackInterface**, [IWiaDevMgr2::RegisterEventCallbackInterface](https://learn.microsoft.com/windows/desktop/wia/-wia-iwiadevmgr2-registereventcallbackinterface), and [DeviceManager.RegisterEvent](https://learn.microsoft.com/previous-versions/windows/desktop/wiaaut/-wiaaut-idevicemanager-registerevent) methods from the same process after the Still Image Service is restarted may cause an access violation, if the functions were used before the service was stopped.

When they begin executing, WIA applications use this method to register to receive hardware device events of the type WIA_NOTIFICATION_EVENT. This prevents the application from being restarted when another event for which it is registered occurs. Once a program invokes **IWiaDevMgr::RegisterEventCallbackInterface** to register itself to receive WIA events from a device, the registered events are routed to the program by the WIA system.

Applications use the [EnumRegisterEventInfo](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiaitem-enumregistereventinfo) method to retrieve a pointer to an enumerator object for event registration properties.

An application can find whether an event is an action type or notification type (or both) event by examining the **ulFlags** value of a [WIA_DEV_CAP](https://learn.microsoft.com/windows/desktop/api/wia_xp/ns-wia_xp-wia_dev_cap) structure returned by event enumeration.

Applications can unregister for events by using the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer returned through the *pEventObject* parameter to call the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

**Note** In a multi-threaded application, there is no guarantee that the event notification callback will come in on the same thread that registered the callback.