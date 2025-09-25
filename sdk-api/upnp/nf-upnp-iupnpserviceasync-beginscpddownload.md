# IUPnPServiceAsync::BeginSCPDDownload

## Description

The **BeginSCPDDownload** method initiates the asynchronous download of an Service Control Protocol Description (SCPD) document.

## Parameters

### `pAsyncResult` [in, optional]

Specifies a pointer to an [IUPnPAsyncResult](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpasyncresult) object. When the **BeginSCPDDownload** call is complete,
UPnP will use the [IUPnPAsyncResult::AsyncOperationComplete](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpasyncresult-asyncoperationcomplete) method to notify the control
point.

### `pullRequestID` [out]

Pointer to a 64-bit **ULONG** value used to identify the **BeginSCPDDownload** operation requested prior to this call.

## Return value

Returns **S_OK** on success. Otherwise, the method returns a COM error code defined in **WinError.h** or one of the following values:

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failed to initiate the SCPD download. |
| **E_INVALIDARG** | *pAsyncResult* is invalid. |

## See also

[IUPnPAsyncResult::AsyncOperationComplete](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpasyncresult-asyncoperationcomplete)

[IUPnPServiceAsync](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpserviceasync)

[IUPnPServiceAsync::BeginInvokeAction](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-begininvokeaction)