# INetFwOpenPorts::Remove

## Description

[The Windows Firewall API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For Windows Vista and later, use of the [Windows Firewall with Advanced Security](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-advanced-security-start-page) API is recommended.]

Closes a port and removes it from the collection.

## Parameters

### `portNumber` [in]

Port number to remove.

### `ipProtocol` [in]

Protocol of the port to remove.

## Return value

### C++

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The operation was aborted due to permissions issues. |
| **E_INVALIDARG** | The method failed due to an invalid parameter. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |

### VB

If the method succeeds, the return value is **S_OK**.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The operation was aborted due to permissions issues. |
| **E_INVALIDARG** | The method failed due to an invalid parameter. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |

## Remarks

If the port is already
closed ,the **Remove** method has no effect.

## See also

[INetFwOpenPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwopenport)

[INetFwOpenPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwopenports)

[NET_FW_IP_PROTOCOL](https://learn.microsoft.com/windows/desktop/api/icftypes/ne-icftypes-net_fw_ip_protocol)