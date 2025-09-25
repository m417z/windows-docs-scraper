# IUPnPRemoteEndpointInfo::GetStringValue

## Description

The **GetStringValue** method gets a string that provides information about either a request or requester.

## Parameters

### `bstrValueName` [in]

String that specifies the category of information to be retrieved.

### `pbstrValue` [out]

Pointer to a string, the meaning of which depends on the value of *bstrValueName*.

If *bstrValueName* is "RemoteAddress", the string is the requester's IP address.**Windows 7:** To retrieve the HTTP UserAgent header, set *bstrValueName* to "HttpUserAgent".

## Return value

If the method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## Remarks

Currently, the only valid values for the *bstrValueName* parameter are "RemoteAddress" and (Windows 7 only) "HttpUserAgent". For any other value, this method will return the COM error code E_INVALIDARG.

## See also

[GetDwordValue](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpremoteendpointinfo-getdwordvalue)

[GetGuidValue](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpremoteendpointinfo-getguidvalue)

[IUPnPRemoteEndpointInfo](https://learn.microsoft.com/windows/desktop/api/upnphost/nn-upnphost-iupnpremoteendpointinfo)