# INetConnectionProps::get_MediaType

## Description

[Internet Connection Firewall may be altered or unavailable in subsequent versions. Instead, use the [Windows Firewall API](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page).]

The
**get_MediaType** method retrieves the media type for the connection.

## Parameters

### `pMediaType` [out]

Pointer to a variable of type
[NETCON_MEDIATYPE](https://learn.microsoft.com/windows/desktop/api/netcon/ne-netcon-netcon_mediatype) that, on successful return, receives a code that specifies the media type for the connection.

## Return value

If the method succeeds the return value is S_OK.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_ABORT** | The operation was aborted. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One of the parameters is invalid. |
| **E_NOINTERFACE** | A specified interface is not supported. |
| **E_NOTIMPL** | A specified method is not implemented. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |
| **E_POINTER** | A pointer passed as a parameter is not valid. |
| **E_UNEXPECTED** | The method failed for unknown reasons. |

## See also

[INetConnectionProps](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetconnectionprops)

[NETCON_MEDIATYPE](https://learn.microsoft.com/windows/desktop/api/netcon/ne-netcon-netcon_mediatype)