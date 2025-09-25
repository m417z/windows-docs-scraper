# IUPnPServiceAsync::BeginQueryStateVariable

## Description

The **BeginQueryStateVariable** method initiates an asynchronous request for the state variable value from a specific service. Additionally, if opt-in is indicated for a delayed Service Control Protocol Description (SCPD) download and event subscription, and it has not taken place already, this method will initiate SCPD download and event subscription.

## Parameters

### `bstrVariableName` [in]

Specifies the requested state variable value.

### `pAsyncResult` [in, optional]

Pointer to a [IUPnPAsyncResult](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpasyncresult) object. When the **BeginQueryStateVariable** call is complete,
UPnP will use the [IUPnPAsyncResult::AsyncOperationComplete](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpasyncresult-asyncoperationcomplete) method to notify the control
point.

### `pullRequestID` [out]

Pointer to a 64-bit **ULONG** value used to identify the asynchronous I/O operation. The UPnP control point must use this handle when ending or cancelling this operation with [EndQueryStateVariable](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-endquerystatevariable).

## Return value

Returns **S_OK** on success. Otherwise, the method returns a COM error code defined in **WinError.h** or one of the following values:

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failed to initiate the asynchronous operation. |
| **UPNP_E_INVALID_VARIABLE** | The requested state variable, indicated by *bstrVariableName*, does not exist. |

**Note** Some values can indicate that an error was received from a UPnP-certified device. For more information, see [Device Error Codes](https://learn.microsoft.com/windows/desktop/UPnP/device-error-codes).

## Remarks

Event subscription should be completed before querying any evented state variables with this method. If this does not occur, **UPNP_E_VARIABLE_VALUE_UNKNOWN** is returned, and event subscription will take place internally. As a result, the next **BeginQueryStateVariable** call will succeed.

**Note** For services without evented variables, this method will always behave as expected.

## See also

[IUPnPServiceAsync](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpserviceasync)

[IUPnPServiceAsync::CancelAsyncOperation](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-cancelasyncoperation)