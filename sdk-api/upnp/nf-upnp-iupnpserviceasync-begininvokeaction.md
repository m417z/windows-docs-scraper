# IUPnPServiceAsync::BeginInvokeAction

## Description

The **BeginInvokeAction** method invokes an action on a device in asynchronous mode. Additionally, if a delayed SCPD download and event subscription is opted-in, and it has not taken place already, this method will initiate SCPD download.

## Parameters

### `bstrActionName` [in]

Specifies the method to invoke.

### `vInActionArgs` [in]

Specifies an array of input arguments to the method. If the action has no input arguments, this parameter must contain an empty array. The contents of this array are service-specific.

### `pAsyncResult` [in, optional]

Pointer to a [IUPnPAsyncResult](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpasyncresult) object. When the **BeginInvokeAction** call is complete,
UPnP will use the [IUPnPAsyncResult::AsyncOperationComplete](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpasyncresult-asyncoperationcomplete) method to notify the control
point.

### `pullRequestID` [out]

Pointer to a 64-bit **ULONG** value used to identify the asynchronous I/O operation. The control point must use this handle as a cookie while ending or cancelling this operation with [EndInvokeAction](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-endinvokeaction).

## Return value

Returns **S_OK** on success. Otherwise, the method returns a COM error code defined in **WinError.h** or one of the following values:

| Return code | Description |
| --- | --- |
| **E_PENDING** | Another async operation is being done on this [IUPnPServiceAsync](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpserviceasync) object. Create another **IUPnPServiceAsync** instance or cancel the running operation by using [IUPnPServiceAsync::CancelAsyncOperation](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-cancelasyncoperation). |
| **E_FAIL** | Failed to initiate the operation. |
| **UPNP_E_INVALID_ACTION** | This action is not supported by the device. |

**Note** Some values can indicate that an error was received from a UPnP-certified device. For more information, see [Device Error Codes](https://learn.microsoft.com/windows/desktop/UPnP/device-error-codes).

## See also

[IUPnPServiceAsync](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpserviceasync)

[IUPnPServiceAsync::EndInvokeAction](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-endinvokeaction)