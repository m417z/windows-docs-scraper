# MPTHREAT\_DATA structure

Notification data passed due to threat detection or modification.

## Members

**ThreatID**

Type: **MPTHREAT\_ID**

Threat identifier. Upper bit is set to identify antivirus-related threats.

**dwSessionID**

Type: **DWORD**

Session associated with the threat. Set to -1 if no session specific information is available.

**ThreatAction**

Type: **[**MPTHREAT\_ACTION**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-action)**

Threat action tried for the **MPNOTIFY\_THREAT\_CLEAN\_SUCCEEDED**/**MPNOTIFY\_THREAT\_CLEAN\_FAILED** events.

**dwStatus**

Type: **DWORD**

Additional status or actions associated with the action taken. This is a combination of bit flags from [**MPSTATUS\_FLAG**](https://learn.microsoft.com/windows/win32/lwef/mpstatus-flag).

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | MpClient.h |

## See also

[**MPSTATUS\_FLAG**](https://learn.microsoft.com/windows/win32/lwef/mpstatus-flag)

[**MPTHREAT\_ACTION**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-action)

