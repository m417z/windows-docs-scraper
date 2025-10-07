# MPCLEAN\_DATA structure

Notification data passed to clean callback function.

## Members

**ThreatID**

Type: **MPTHREAT\_ID**

Threat identifier for the **MPNOTIFY\_CLEAN\_THREAT\_START**/**MPNOTIFY\_CLEAN\_THREAT\_SUCCEEDED**/**MPNOTIFY\_CLEAN\_THREAT\_FAILED** events. Upper bit is set to identify antivirus-related threats.

**ThreatAction**

Type: **[**MPTHREAT\_ACTION**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-action)**

Threat action for the **MPNOTIFY\_CLEAN\_THREAT\_START**/**MPNOTIFY\_CLEAN\_THREAT\_SUCCEEDED**/**MPNOTIFY\_CLEAN\_THREAT\_FAILED** events. See [**MPTHREAT\_ACTION**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-action).

**dwStatus**

Type: **DWORD**

Additional status or actions associated with the action taken. This is a combination of bit flags from [**MPSTATUS\_FLAG**](https://learn.microsoft.com/windows/win32/lwef/mpstatus-flag).

**ResourceInfo**

Type: **PMPRESOURCE\_INFO**

Resource information for the **MPNOTIFY\_CLEAN\_THREAT\_START**/**MPNOTIFY\_CLEAN\_THREAT\_SUCCEEDED**/**MPNOTIFY\_CLEAN\_THREAT\_FAILED** events. See [**MPRESOURCE\_INFO**](https://learn.microsoft.com/windows/win32/lwef/mpresource-info).

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | MpClient.h |

## See also

[**MPRESOURCE\_INFO**](https://learn.microsoft.com/windows/win32/lwef/mpresource-info)

[**MPSTATUS\_FLAG**](https://learn.microsoft.com/windows/win32/lwef/mpstatus-flag)

[**MPTHREAT\_ACTION**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-action)

