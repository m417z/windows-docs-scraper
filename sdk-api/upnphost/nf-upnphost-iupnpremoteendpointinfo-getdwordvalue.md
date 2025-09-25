# IUPnPRemoteEndpointInfo::GetDwordValue

## Description

The **GetDwordValue** method gets a 4-byte value that provides information about either a request or requester.

## Parameters

### `bstrValueName` [in]

String that specifies the category of information to be retrieved.

### `pdwValue` [out]

Pointer to a 4-byte value, the meaning of which depends on the value of *bstrValueName*.

If *bstrValueName* is "AddressFamily", the 4-byte value indicates the format of the requester's IP address as follows. The values are defined in Winsock2.h.

| Value | Meaning |
| --- | --- |
| **AF_INET** | IP (IP version 4) |
| **AF_INET6** | IP6 (IP version 6) |

## Return value

If the method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## Remarks

Currently, the only valid value for the *bstrValueName* parameter is "AddressFamily". For any other value, this method will return the COM error code E_INVALIDARG.

## See also

[GetGuidValue](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpremoteendpointinfo-getguidvalue)

[GetStringValue](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpremoteendpointinfo-getstringvalue)

[IUPnPRemoteEndpointInfo](https://learn.microsoft.com/windows/desktop/api/upnphost/nn-upnphost-iupnpremoteendpointinfo)