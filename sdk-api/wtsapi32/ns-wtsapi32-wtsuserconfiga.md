# WTSUSERCONFIGA structure

## Description

Contains configuration information for a user on a domain controller or Remote Desktop Session Host (RD Session Host) server. This structure is used by the [WTSQueryUserConfig](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsqueryuserconfiga) and [WTSSetUserConfig](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtssetuserconfiga) functions.

## Members

### `Source`

A value of the [WTS_CONFIG_SOURCE](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ne-wtsapi32-wts_config_source) enumeration type that specifies the source of configuration information returned by the [WTSQueryUserConfig](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsqueryuserconfiga) function.

### `InheritInitialProgram`

A value that indicates whether the client can specify the initial program. This member can be one of the following values.

#### 0

The client cannot specify the initial program. Instead, the program specified by the **InitialProgram** member starts automatically when the user logs on to the server. The server logs the user off when the user exits that program.

#### 1

The client can specify the initial program.

### `AllowLogonTerminalServer`

A value that indicates whether the user account is permitted to log on to an RD Session Host server. This member can be one of the following values.

#### 0

The user cannot log on.

#### 1

The user can log on.

### `TimeoutSettingsConnections`

The maximum connection duration, in milliseconds. One minute before the connection expires, the server notifies the user about the pending disconnection. When the connection times out, the server takes the action specified by the **BrokenTimeoutSettings** member. Every time the user logs on, the timer is reset. A value of zero indicates that the connection timer is disabled.

### `TimeoutSettingsDisconnections`

The maximum duration, in milliseconds, that the server retains a disconnected session before the logon is terminated. A value of zero indicates that the disconnection timer is disabled.

### `TimeoutSettingsIdle`

The amount of time, in milliseconds, that a connection can remain idle. If there is no keyboard or mouse activity for this period of time, the server takes the action specified by the **BrokenTimeoutSettings** member. A value of zero indicates that the idle timer is disabled.

### `DeviceClientDrives`

This member is reserved.

### `DeviceClientPrinters`

A value that indicates whether the server automatically connects to previously mapped client printers when the user logs on to the server. This member can be one of the following values.

#### 0

The server does not automatically connect to previously mapped client printers.

#### 1

The server automatically connects to previously mapped client printers.

### `ClientDefaultPrinter`

A value that indicates whether the client printer is the default printer. This member can be one of the following values.

#### 0

The client printer is not the default printer.

#### 1

The client printer is the default printer.

### `BrokenTimeoutSettings`

The action the server takes when the connection or idle timers expire, or when a connection is lost due to a connection error. This member can be one of the following values.

#### 0

The session is disconnected, but it remains on the server.

#### 1

The session is terminated.

### `ReconnectSettings`

A value that indicates how a disconnected session for this user can be reconnected. This member can be one of the following values.

#### 0

The user can log on to any client computer to reconnect to a disconnected session.

#### 1

The user must log on to the client computer originally used to establish the disconnected session. If the user logs on to a different client computer, the user gets a new session.

### `ShadowingSettings`

The remote control setting. Remote control allows a user to remotely monitor the on-screen operations of another user. This member can be one of the following values.

#### 0

Remote control is disabled.

#### 1

The user of remote control has full control of the user's session, with the user's permission.

#### 2

The user of remote control has full control of the user's session; the user's permission is
not required.

#### 3

The user of remote control can view the session remotely, with the user's permission; the remote user
cannot actively control the session.

#### 4

The user of remote control can view the session remotely but not actively control the session; the
user's permission is not required.

### `TerminalServerRemoteHomeDir`

A value that indicates whether the **TerminalServerHomeDir** member contains a path to a local directory or a network share. You cannot set this member by using the [WTSSetUserConfig](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtssetuserconfiga) function. This member can be one of the following values.

#### 0

The **TerminalServerHomeDir** member contains a path to a local directory.

#### 1

The **TerminalServerHomeDir** member contains a path to a network share, and the **TerminalServerHomeDirDrive** member contains a drive letter to which this path is mapped.

### `InitialProgram`

A null-terminated string that contains the name of the program to start immediately after the user logs on to the server.

### `WorkDirectory`

A null-terminated string that contains the path of the working directory for the initial program.

### `TerminalServerProfilePath`

A null-terminated string that contains the profile path that is assigned to the user when the user connects to the server. The directory specified by the path must be created manually, and must exist prior to the logon.

### `TerminalServerHomeDir`

A null-terminated string that contains the path to the home folder of the user's Remote Desktop Services sessions. The folder can be a local folder or a network share.

### `TerminalServerHomeDirDrive`

A null-terminated string that contains the drive name (a drive letter followed by a colon) to which the path specified in the **TerminalServerHomeDir** member is mapped. This member is only valid when the **TerminalServerRemoteHomeDir** member is set to one.

## See also

[WTSQueryUserConfig](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsqueryuserconfiga)

[WTSSetUserConfig](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtssetuserconfiga)

[WTS_CONFIG_SOURCE](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ne-wtsapi32-wts_config_source)

## Remarks

> [!NOTE]
> The wtsapi32.h header defines WTSUSERCONFIG as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).