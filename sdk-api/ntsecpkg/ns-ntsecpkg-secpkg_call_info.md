# SECPKG_CALL_INFO structure

## Description

The **SECPKG_CALL_INFO** structure contains information about a currently executing call. This structure is used by the
[GetCallInfo](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_get_call_info) function.

## Members

### `ProcessId`

The process identifier of the call.

### `ThreadId`

The thread identifier of the call.

### `Attributes`

The set of attribute flags that describe the call. The following table lists the valid attribute flag values.

| Value | Meaning |
| --- | --- |
| **SECPKG_CALL_KERNEL_MODE** | Call originated in kernel mode. |
| **SECPKG_CALL_ANSI** | Call came from ANSI stub. |
| **SECPKG_CALL_URGENT** | Call designated urgent. |
| **SECPKG_CALL_RECURSIVE** | Call is recursive. |
| **SECPKG_CALL_IN_PROC** | Call originated in process. |
| **SECPKG_CALL_CLEANUP** | Call is cleanup from a client. |
| **SECPKG_CALL_WOWCLIENT** | Call is from a WOW client process.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **SECPKG_CALL_THREAD_TERM** | Call is from a terminated thread. <br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **SECPKG_CALL_PROCESS_TERM** | Call is from a terminated process.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **SECPKG_CALL_IS_TCB** | Call is from TCB.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **SECPKG_CALL_NETWORK_ONLY** | Call asks for network logon only and not any cached logons.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **SECPKG_CALL_WINLOGON** | Call of [LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser) is from Winlogon.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **SECPKG_CALL_ASYNC_UPDATE** | Asynchronous update for unlock.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **SECPKG_CALL_SYSTEM_PROC** | Call originated from the System process.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **SECPKG_CALL_NEGO** | Call is from SPNego.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported. |
| **SECPKG_CALL_NEGO_EXTENDER** | Call is from NEGO extender.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported. |
| **SECPKG_CALL_BUFFER_MARSHALL** | The buffer passed is marshaled by RPC.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported. |

### `CallCount`

The call count.

### `MechOid`