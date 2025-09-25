# IWiaEventCallback::ImageEventCallback

## Description

The **IWiaEventCallback::ImageEventCallback** method is invoked by the Windows Image Acquisition (WIA) run-time system when a hardware device event occurs.

## Parameters

### `pEventGUID` [in]

Type: **const GUID***

Specifies the unique identifier of the event. For a complete list of device events, see [WIA Event Identifiers](https://learn.microsoft.com/windows/desktop/wia/-wia-wia-event-identifiers).

### `bstrEventDescription` [in]

Type: **BSTR**

Specifies the string description of the event.

### `bstrDeviceID` [in]

Type: **BSTR**

Specifies the unique identifier of the WIA device.

### `bstrDeviceDescription` [in]

Type: **BSTR**

Specifies the string description of the device.

### `dwDeviceType` [in]

Type: **DWORD**

Specifies the type of the device. See [WIA Device Type Specifiers](https://learn.microsoft.com/windows/desktop/wia/-wia-wia-device-type-specifiers) for a list of possible values.

### `bstrFullItemName` [in]

Type: **BSTR**

Specifies the full name of the WIA item that represents the device.

### `pulEventType` [in, out]

Type: **ULONG***

Pointer to a **ULONG** that specifies whether an event is a notification event, an action event, or both. A value of 1 indicates a notification event, a value of 2 indicates an action event, and a value of 3 indicates that the event is of both notification and action type.

### `ulReserved` [in]

Type: **ULONG**

Reserved for user information.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To receive notification of WIA hardware device events, applications pass a pointer to the [IWiaEventCallback](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaeventcallback) interface to the [RegisterEventCallbackInterface](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiadevmgr-registereventcallbackinterface) method. The WIA run-time system then uses that interface pointer to invoke the **IWiaEventCallback::ImageEventCallback** method whenever a WIA hardware device event occurs.

Note that there is no guarantee the callback will be invoked on the same thread that registered the [IWiaEventCallback](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaeventcallback) interface.