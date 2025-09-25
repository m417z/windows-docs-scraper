# INetFwOpenPorts::Add

## Description

[The Windows Firewall API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For Windows Vista and later, use of the [Windows Firewall with Advanced Security](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-advanced-security-start-page) API is recommended.]

Opens a new port and adds it to the collection.

## Parameters

### `port` [in]

Port to add to the collection.

## Return value

### C++

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The operation was aborted due to permissions issues. |
| **E_INVALIDARG** | The method failed because a parameter was not valid. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |
| **E_UNEXPECTED** | The method failed because the object is already in the collection. |

### VB

If the method succeeds, the return value is S_OK.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The operation was aborted due to permissions issues. |
| **E_INVALIDARG** | The method failed because a parameter was not valid. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |
| **E_UNEXPECTED** | The method failed because the object is already in the collection. |

## Remarks

If the port is already open, the existing settings are overwritten.

## See also

[INetFwOpenPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwopenport)

[INetFwOpenPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwopenports)