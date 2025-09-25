# INetFwOpenPorts::Item

## Description

[The Windows Firewall API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For Windows Vista and later, use of the [Windows Firewall with Advanced Security](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-advanced-security-start-page) API is recommended.]

Returns the specified port if it is in the collection.

## Parameters

### `portNumber` [in]

Port number to find.

### `ipProtocol` [in]

Protocol of the port to find by type [NET_FW_IP_PROTOCOL](https://learn.microsoft.com/windows/desktop/api/icftypes/ne-icftypes-net_fw_ip_protocol).

### `openPort` [out]

Reference to the returned [INetFwOpenPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwopenport) object.

## Return value

### C++

If the method succeeds, the return value is S_OK.

If the method fails, the return value is one of the following error codes.

| Error | Description |
| --- | --- |
| E_ACCESSDENIED | The operation was aborted due to permissions issues. |
| E_INVALIDARG | The method failed due to an invalid parameter. |
| E_OUTOFMEMORY | The method was unable to allocate required memory. |
| E_POINTER | The method failed due to an invalid pointer. |
| HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND) | The requested item does not exist. |

### VB

Reference to the returned
[INetFwOpenPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwopenport)
object.

## See also

[INetFwOpenPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwopenport)

[INetFwOpenPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwopenports)

[NET_FW_IP_PROTOCOL](https://learn.microsoft.com/windows/desktop/api/icftypes/ne-icftypes-net_fw_ip_protocol)