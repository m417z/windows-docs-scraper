# IsOS function

## Description

Checks for specified operating systems and operating system features.

## Parameters

### `dwOS` [in]

Type: **DWORD**

A value that specifies which operating system or operating system feature to check for. One of the following values (you cannot combine values).

| Name | Value | Description |
| --- | --- | --- |
| OS_WINDOWS | 0 | The program is running on one of the following versions of Windows:<br><br>* Windows 95<br>* Windows 98<br>* Windows Me<br><br>Equivalent to [VER_PLATFORM_WIN32_WINDOWS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa). Note that none of those systems are supported at this time. **OS_WINDOWS** returns **FALSE** on all supported systems. |
| OS_NT | 1 | Always returns **TRUE**. |
| OS_WIN95ORGREATER | 2 | Always returns **FALSE**. |
| OS_NT4ORGREATER | 3 | Always returns **FALSE**. |
| OS_WIN98ORGREATER | 5 | Always returns **FALSE**. |
| OS_WIN98_GOLD | 6 | Always returns **FALSE**. |
| OS_WIN2000ORGREATER | 7 | The program is running on Windows 2000 or one of its successors. |
| OS_WIN2000PRO | 8 | Do not use; use OS_PROFESSIONAL. |
| OS_WIN2000SERVER | 9 | Do not use; use OS_SERVER. |
| OS_WIN2000ADVSERVER | 10 | Do not use; use OS_ADVSERVER. |
| OS_WIN2000DATACENTER | 11 | Do not use; use OS_DATACENTER. |
| OS_WIN2000TERMINAL | 12 | The program is running on Windows 2000 Terminal Server in either Remote Administration mode or Application Server mode, or Windows Server 2003 (or one of its successors) in Terminal Server mode or Remote Desktop for Administration mode. Consider using a more specific value such as OS_TERMINALSERVER, OS_TERMINALREMOTEADMIN, or OS_PERSONALTERMINALSERVER. |
| OS_EMBEDDED | 13 | The program is running on Windows Embedded, any version. Equivalent to [VER_SUITE_EMBEDDEDNT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa). |
| OS_TERMINALCLIENT | 14 | The program is running as a Terminal Server client. Equivalent to [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics)(SM_REMOTESESSION). |
| OS_TERMINALREMOTEADMIN | 15 | The program is running on Windows 2000 Terminal Server in the Remote Administration mode or Windows Server 2003 (or one of its successors) in the Remote Desktop for Administration mode (these are the default installation modes). This is equivalent to [VER_SUITE_TERMINAL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa) && [VER_SUITE_SINGLEUSERTS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa). |
| OS_WIN95_GOLD | 16 | Always returns **FALSE**. |
| OS_MEORGREATER | 17 | Always returns **FALSE**. |
| OS_XPORGREATER | 18 | Always returns **FALSE**. |
| OS_HOME | 19 | Always returns **FALSE**. |
| OS_PROFESSIONAL | 20 | The program is running on Windows NT Workstation or Windows 2000 (or one of its successors) Professional. Equivalent to [VER_PLATFORM_WIN32_NT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa) && [VER_NT_WORKSTATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa). |
| OS_DATACENTER | 21 | The program is running on Windows Datacenter Server or Windows Server Datacenter Edition, any version. Equivalent to ([VER_NT_SERVER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa) || [VER_NT_DOMAIN_CONTROLLER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa)) && [VER_SUITE_DATACENTER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa). |
| OS_ADVSERVER | 22 | The program is running on Windows Advanced Server or Windows Server Enterprise Edition, any version. Equivalent to ([VER_NT_SERVER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa) || [VER_NT_DOMAIN_CONTROLLER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa)) && [VER_SUITE_ENTERPRISE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa) && ![VER_SUITE_DATACENTER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa). |
| OS_SERVER | 23 | The program is running on Windows Server (Standard) or Windows Server Standard Edition, any version. This value will not return **true** for [VER_SUITE_DATACENTER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa), [VER_SUITE_ENTERPRISE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa), [VER_SUITE_SMALLBUSINESS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa), or [VER_SUITE_SMALLBUSINESS_RESTRICTED](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa). |
| OS_TERMINALSERVER | 24 | The program is running on Windows 2000 Terminal Server in Application Server mode, or on Windows Server 2003 (or one of its successors) in Terminal Server mode. This is equivalent to [VER_SUITE_TERMINAL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa) && [VER_SUITE_SINGLEUSERTS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa). |
| OS_PERSONALTERMINALSERVER | 25 | The program is running on Windows XP (or one of its successors), Home Edition or Professional. This is equivalent to [VER_SUITE_SINGLEUSERTS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa) && ![VER_SUITE_TERMINAL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa). |
| OS_FASTUSERSWITCHING | 26 | Fast user switching is enabled. |
| OS_WELCOMELOGONUI | 27 | Always returns **FALSE**. |
| OS_DOMAINMEMBER | 28 | The computer is joined to a domain. |
| OS_ANYSERVER | 29 | The program is running on any Windows Server product. Equivalent to [VER_NT_SERVER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa) || [VER_NT_DOMAIN_CONTROLLER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa). |
| OS_WOW6432 | 30 | The program is a 32-bit program running on 64-bit Windows. |
| OS_WEBSERVER | 31 | Always returns **FALSE**. |
| OS_SMALLBUSINESSSERVER | 32 | The program is running on Microsoft Small Business Server with restrictive client license in force. Equivalent to [VER_SUITE_SMALLBUSINESS_RESTRICTED](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa). |
| OS_TABLETPC | 33 | The program is running on Windows XP Tablet PC Edition, or one of its successors. |
| OS_SERVERADMINUI | 34 | The user should be presented with administrator UI. It is possible to have server administrative UI on a non-server machine. This value informs the application that an administrator's profile has roamed to a non-server, and UI should be appropriate to an administrator. Otherwise, the user is shown a mix of administrator and nonadministrator settings. |
| OS_MEDIACENTER | 35 | The program is running on Windows XP Media Center Edition, or one of its successors. Equivalent to [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics)(SM_MEDIACENTER). |
| OS_APPLIANCE | 36 | The program is running on Windows Appliance Server. |

## Return value

Type: **BOOL**

Returns a nonzero value if the specified operating system or operating system feature is detected, otherwise **FALSE**.

## Remarks

Values are not provided for Windows Vista and Windows 7. To determine whether either of those operating systems are present, use [VerifyVersionInfo](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-verifyversioninfoa).

In Windows versions earlier than Windows Vista, **IsOS** was not exported by name or declared in a public header file. To use it in those cases, you must use [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) and request ordinal 437 from Shlwapi.dll to obtain a function pointer. Under Windows Vista, **IsOS** is included in Shlwapi.h and this is not necessary.

When referring to server products, "Windows Server" refers only to the Standard Edition server. If all server products are covered by a particular flag, it is called out explicitly in the table.

## See also

[GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics)

[GetVersionEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getversionexa)

[VerifyVersionInfo](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-verifyversioninfoa)