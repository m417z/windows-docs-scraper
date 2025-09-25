# IUPnPServiceAsync::BeginSubscribeToEvents

## Description

The **BeginSubscribeToEvents** initiates event subscription in asynchronous mode and registers the application callback with the UPnP framework.

## Parameters

### `pUnkCallback` [in]

Specifies the reference to the interface object that contains the callback to register. This object must either support the [IUPnPServiceCallback](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpservicecallback) interface or the [IDispatch](https://learn.microsoft.com/windows/desktop/WinAuto/idispatch-interface) interface.

### `pAsyncResult` [in, optional]

Specifies a reference to [IUPnPAsyncResult](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpasyncresult) object. When the **BeginSubscribeToEvents** call is complete,
UPnP will use the [IUPnPAsyncResult::AsyncOperationComplete](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpasyncresult-asyncoperationcomplete) method to notify the control point.

### `pullRequestID` [out]

Pointer to a 64-bit **ULONG** value used to identify the asynchronous I/O operation. The control point must use this handle while ending or cancelling the operation via [EndSubscribeToEvents](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-endsubscribetoevents) or [CancelAsyncOperation](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-cancelasyncoperation).

## Return value

Returns **S_OK** on success. Otherwise, the method returns a COM error code defined in **WinError.h** or one of the following values:

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failed to initiate the asynchronous operation. |

**Note** Some values can indicate that an error was received from a UPnP-certified device. For more information, see [Device Error Codes](https://learn.microsoft.com/windows/desktop/UPnP/device-error-codes).

## Remarks

Event subscription should be completed before querying any evented state variables with [BeginQueryStateVariable](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-beginquerystatevariable). If this does not occur, **UPNP_E_VARIABLE_VALUE_UNKNOWN** is returned, and event subscription will take place internally. As a result, the next **BeginQueryStateVariable** call will succeed.

**Note** For services without evented variables, [BeginQueryStateVariable](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-beginquerystatevariable) will always behave as expected.

Calling this method multiple times will result in the addition of multiple callbacks.

## See also

[IUPnPServiceAsync](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpserviceasync)

[IUPnPServiceAsync::CancelAsyncOperation](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-cancelasyncoperation)

[IUPnPServiceAsync::EndSubscribeToEvents](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-endsubscribetoevents)