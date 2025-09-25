# INetFwMgr::RestoreDefaults

## Description

[The Windows Firewall API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For Windows Vista and later, use of the [Windows Firewall with Advanced Security](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-advanced-security-start-page) API is recommended.]

Restores the local configuration to its default, installed state.

## Return value

### C++

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The operation was stopped because of permissions issues. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |

### VB

If the method succeeds, the return value is S_OK.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The operation was stopped because of permissions issues. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |

## Remarks

This method deletes all user and application-added applications and ports that return the system to its installed state. This includes restoring the defaults for Internet Connection Sharing.

## See also

[INetFwMgr](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwmgr)

[INetFwMgr::IsIcmpTypeAllowed](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nf-netfw-inetfwmgr-isicmptypeallowed)

[INetFwMgr::IsPortAllowed](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nf-netfw-inetfwmgr-isportallowed)