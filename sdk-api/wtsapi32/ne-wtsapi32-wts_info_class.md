# WTS_INFO_CLASS enumeration

## Description

Contains values that indicate the type of
session information to retrieve in a call to the
[WTSQuerySessionInformation](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsquerysessioninformationa) function.

## Constants

### `WTSInitialProgram`

A null-terminated string that contains the name of the initial program that Remote Desktop Services runs when the
user logs on.

### `WTSApplicationName`

A null-terminated string that contains the published name of the application that the session is running.

**Windows Server 2008 R2, Windows 7, Windows Server 2008 and Windows Vista:** This value is not supported

### `WTSWorkingDirectory`

A null-terminated string that contains the default directory used when launching the initial program.

### `WTSOEMId`

This value is not used.

### `WTSSessionId`

A **ULONG** value that contains the session identifier.

### `WTSUserName`

A null-terminated string that contains the name of the user associated with the session.

### `WTSWinStationName`

A null-terminated string that contains the name of the Remote Desktop Services session.

**Note** Despite its name, specifying this type does not return the window station name. Rather, it returns the
name of the Remote Desktop Services session. Each Remote Desktop Services session is associated with an interactive window
station. Because the only supported window station name for an interactive window station is
"WinSta0", each session is associated with its own "WinSta0" window station. For more information, see
[Window Stations](https://learn.microsoft.com/windows/desktop/winstation/window-stations).

### `WTSDomainName`

A null-terminated string that contains the name of the domain to which the logged-on user belongs.

### `WTSConnectState`

The session's current connection state. For more information, see
[WTS_CONNECTSTATE_CLASS](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ne-wtsapi32-wts_connectstate_class).

### `WTSClientBuildNumber`

A **ULONG** value that contains the build number of the client.

### `WTSClientName`

A null-terminated string that contains the name of the client.

### `WTSClientDirectory`

A null-terminated string that contains the directory in which the client is installed.

### `WTSClientProductId`

A **USHORT** client-specific product identifier.

### `WTSClientHardwareId`

A **ULONG** value that contains a client-specific hardware identifier. This option is reserved for future use. [WTSQuerySessionInformation](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsquerysessioninformationa) will always return a value of 0.

### `WTSClientAddress`

The network type and network address of the client. For more information, see
[WTS_CLIENT_ADDRESS](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_client_address).

The IP address is offset by two bytes from the start of the **Address** member of the [WTS_CLIENT_ADDRESS](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_client_address)
structure.

### `WTSClientDisplay`

Information about the display resolution of the client. For more information, see
[WTS_CLIENT_DISPLAY](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_client_display).

### `WTSClientProtocolType`

A **USHORT** value that specifies information about the protocol type for the
session. This is one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | The console session. |
| 1 | This value is retained for legacy purposes. |
| 2 | The RDP protocol. |

### `WTSIdleTime`

This value returns **FALSE**. If you call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get extended error information, **GetLastError** returns **ERROR_NOT_SUPPORTED**.

To caculate session idle time, use the [LastInputTime](https://learn.microsoft.com/en-us/windows/win32/api/wtsapi32/ns-wtsapi32-wtsinfoa) structure field.

**Windows Server 2008 and Windows Vista:** This value is not used.

### `WTSLogonTime`

This value returns **FALSE**. If you call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get extended error information, **GetLastError** returns **ERROR_NOT_SUPPORTED**.

**Windows Server 2008 and Windows Vista:** This value is not used.

### `WTSIncomingBytes`

This value returns **FALSE**. If you call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get extended error information, **GetLastError** returns **ERROR_NOT_SUPPORTED**.

**Windows Server 2008 and Windows Vista:** This value is not used.

### `WTSOutgoingBytes`

This value returns **FALSE**. If you call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get extended error information, **GetLastError** returns **ERROR_NOT_SUPPORTED**.

**Windows Server 2008 and Windows Vista:** This value is not used.

### `WTSIncomingFrames`

This value returns **FALSE**. If you call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get extended error information, **GetLastError** returns **ERROR_NOT_SUPPORTED**.

**Windows Server 2008 and Windows Vista:** This value is not used.

### `WTSOutgoingFrames`

This value returns **FALSE**. If you call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get extended error information, **GetLastError** returns **ERROR_NOT_SUPPORTED**.

**Windows Server 2008 and Windows Vista:** This value is not used.

### `WTSClientInfo`

Information about a Remote Desktop Connection (RDC) client. For more information, see [WTSCLIENT](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wtsclienta).

### `WTSSessionInfo`

Information about a client session on a RD Session Host server. For more information, see [WTSINFO](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wtsinfoa).

### `WTSSessionInfoEx`

Extended information about a session on a RD Session Host server. For more information, see [WTSINFOEX](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wtsinfoexa).

**Windows Server 2008 and Windows Vista:** This value is not supported.

### `WTSConfigInfo`

A [WTSCONFIGINFO](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wtsconfiginfoa) structure that contains information about the configuration of a RD Session Host server.

**Windows Server 2008 and Windows Vista:** This value is not supported.

### `WTSValidationInfo`

This value is not supported.

### `WTSSessionAddressV4`

A [WTS_SESSION_ADDRESS](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_session_address) structure that contains the IPv4 address assigned to the session.
If the session does not have a virtual IP address, the [WTSQuerySessionInformation](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsquerysessioninformationa) function returns **ERROR_NOT_SUPPORTED**.

**Windows Server 2008 and Windows Vista:** This value is not supported.

### `WTSIsRemoteSession`

Determines whether the current session is a remote session. The [WTSQuerySessionInformation](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsquerysessioninformationa) function returns a value of **TRUE** to indicate that the current session is a remote session, and **FALSE** to indicate that the current session is a local session. This value can only be used for the local machine, so the *hServer* parameter of the **WTSQuerySessionInformation** function must contain **WTS_CURRENT_SERVER_HANDLE**.

**Windows Server 2008 and Windows Vista:** This value is not supported.

### `WTSSessionActivityId`

A **GUID** value that contains the Terminal Services activity ID currently associated with the session.

**Versions prior to Windows Server 2025 or Windows 11 (23H2):** This value is not supported.

### `WTSCapabilityCheck`

An **array of UINT32** values corresponding to whether certain capabilities are supported by the session host.

If the list includes the value `59083637` then that means that RAIL protocol v2 is supported.

**Versions prior to Windows Server 2025 or Windows 11 (24H2):** This value is not supported.

## See also

[WTSQuerySessionInformation](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsquerysessioninformationa)