# WTSCONFIGINFOA structure

## Description

Contains information about a Remote Desktop Services session. This structure is returned by the [WTSQuerySessionInformation](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsquerysessioninformationa) function when you specify "WTSConfigInfo" for the *WTSInfoClass* parameter.

## Members

### `version`

This member is reserved.

### `fConnectClientDrivesAtLogon`

This member is reserved.

### `fConnectPrinterAtLogon`

This member is reserved.

### `fDisablePrinterRedirection`

Specifies whether the client can use printer redirection.

#### 0

Enable client printer redirection.

#### 1

Disable client printer redirection.

### `fDisableDefaultMainClientPrinter`

Specifies whether the printer connected to the client is the default printer for the user.

#### 0

The printer connected to the client is not the default printer for the user.

#### 1

The printer connected to the client is the default printer for the user.

### `ShadowSettings`

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

### `LogonUserName`

A null-terminated string that contains the user name used in automatic logon scenarios.

### `LogonDomain`

A null-terminated string that contains the domain name used in automatic logon scenarios.

### `WorkDirectory`

A null-terminated string that contains the path of the working directory of the initial program.

### `InitialProgram`

A null-terminated string that contains the name of the program to start immediately after the user logs on to the server.

### `ApplicationName`

This member is reserved.

## See also

[WTSQuerySessionInformation](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsquerysessioninformationa)

## Remarks

> [!NOTE]
> The wtsapi32.h header defines WTSCONFIGINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).