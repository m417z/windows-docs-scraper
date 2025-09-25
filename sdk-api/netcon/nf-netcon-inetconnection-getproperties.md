# INetConnection::GetProperties

## Description

[Internet Connection Firewall may be altered or unavailable in subsequent versions. Instead, use the [Windows Firewall API](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page).]

The
**GetProperties** method retrieves a structure that contains the properties for this network connection.

## Parameters

### `ppProps` [out]

Pointer to a pointer that, on successful return, points to a
[NETCON_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/netcon/ns-netcon-netcon_properties) structure that contains the properties for this network connection.

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

## Remarks

The calling application should free the memory occupied by the
[NETCON_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/netcon/ns-netcon-netcon_properties) structure returned by **GetProperties**. Free the memory by calling the [NcFreeNetconProperties](https://learn.microsoft.com/windows/desktop/api/netcon/nf-netcon-ncfreenetconproperties) function. This function is defined in NetCon.h and is exported by NetShell.dll.

## See also

[INetConnection](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetconnection)

[Internet Connection Sharing and Internet Connection Firewall Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-interfaces)

[Internet Connection Sharing and Internet Connection Firewall Reference](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-reference)