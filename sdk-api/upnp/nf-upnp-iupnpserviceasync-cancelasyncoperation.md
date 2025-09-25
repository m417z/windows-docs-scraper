# IUPnPServiceAsync::CancelAsyncOperation

## Description

The **CancelAsyncOperation** method cancels a pending asynchronous operation initiated by the [BeginInvokeAction](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-begininvokeaction), [BeginQueryStateVariable](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-beginquerystatevariable), [BeginSubscribeToEvents](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-beginsubscribetoevents), or [BeginSCPDDownload](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-beginscpddownload) methods.

## Parameters

### `ullRequestID` [in]

A 64-bit **ULONG** value that corresponds to the pending asynchronous UPnP operation.

## Return value

Returns **S_OK** on success. Otherwise, the method returns a COM error code defined in **WinError.h** or one of the following values:

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failed to cancel the asynchronous operation. |
| **E_INVALIDARG** | *ullRequestID* does not match the pending asynchronous call. |

## Remarks

Calling this method for a pending [BeginSCPDDownload](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-beginscpddownload) operation the SCPD download will still take place in the background, but will not notify callbacks of events associated with the operation.

## See also

[IUPnPServiceAsync](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpserviceasync)

[IUPnPServiceAsync::BeginInvokeAction](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-begininvokeaction)

[IUPnPServiceAsync::BeginQueryStateVariable](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-beginquerystatevariable)

[IUPnPServiceAsync::BeginSCPDDownload](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-beginscpddownload)

[IUPnPServiceAsync::BeginSubscribeToEvents](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-beginsubscribetoevents)