# IUPnPServiceAsync::EndSCPDDownload

## Description

The **EndSCPDDownload** method retrieves the results of a previous asynchronous download of an Service Control Protocol Description (SCPD) document.

## Parameters

### `ullRequestID`

Pointer to a 64-bit **ULONG** value that corresponds to the [BeginSCPDDownload](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-beginscpddownload) operation requested prior to this call.

### `pbstrSCPDDoc` [out]

A buffer containing the SCPD document.

## Return value

Returns **S_OK** on success. Otherwise, the method returns a COM error code defined in **WinError.h** or one of the following values:

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failed to finalize the SCPD download and retrieve the document string. |
| **E_INVALIDARG** | *ullRequestID* does not match the pending async call. |

## See also

[IUPnPServiceAsync](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpserviceasync)

[IUPnPServiceAsync::BeginSCPDDownload](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-beginscpddownload)