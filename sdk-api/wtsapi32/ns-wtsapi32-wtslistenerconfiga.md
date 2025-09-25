# WTSLISTENERCONFIGA structure

## Description

Contains information about a Remote Desktop Services listener. This structure is used by the [WTSCreateListener](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtscreatelistenera) function.

## Members

### `version`

This member is reserved.

### `fEnableListener`

Specifies whether the listener is enabled. This member can be one of the following values.

#### 0

The listener is disabled.

#### 1

The listener is enabled.

### `MaxConnectionCount`

The maximum number of active connections that the listener accepts.

### `fPromptForPassword`

Specifies whether the listener always prompts the user for a password. This member can be one of the following values.

#### 0

Prompt the user for a password only when specified by the server.

#### 1

Always prompt the user for a password.

### `fInheritColorDepth`

Specifies whether the listener should use the color depth specified by the user. This member can be one of the following values.

#### 0

Use the color depth specified by the server.

#### 1

Use the color depth specified by the user.

### `ColorDepth`

The color depth setting for the listener. This setting only applies when the **fInheritColorDepth** member is zero. This can be one of the following values.

#### 1

8 bit

#### 2

15 bit

#### 3

16 bit

#### 4

24 bit

#### 5

32 bit

### `fInheritBrokenTimeoutSettings`

Specifies whether the listener should use the **BrokenTimeoutSettings** value specified by the user. This member can be one of the following values.

#### 0

Use the **BrokenTimeoutSettings** value specified by server.

#### 1

Use the **BrokenTimeoutSettings** value specified by the user.

### `BrokenTimeoutSettings`

The action the listener takes when a connection or idle timer expires, or when a connection is lost due to a connection error. This setting only applies when the **fInheritBrokenTimeoutSettings** member is zero. This member can be one of the following values.

#### 0

When a connection or idle timer expires, or when a connection is lost due to a connection error, the user is disconnected but the session remains on the server.

#### 1

When a connection or idle timer expires, or when a connection is lost due to a connection error, the session is terminated.

### `fDisablePrinterRedirection`

Specifies whether printer redirection is disabled. This member can be one of the following values.

#### 0

The user can enable printer redirection.

#### 1

Printer redirection is disabled.

### `fDisableDriveRedirection`

Specifies whether drive redirection is disabled. This member can be one of the following values.

#### 0

The user can enable drive redirection.

#### 1

Drive redirection is disabled.

### `fDisableComPortRedirection`

Specifies whether COM port redirection is disabled. This member can be one of the following values.

#### 0

The user can enable COM port redirection.

#### 1

COM port redirection is disabled.

### `fDisableLPTPortRedirection`

Specifies whether LPT port redirection is disabled. This member can be one of the following values.

#### 0

The user can enable LPT port redirection.

#### 1

LPT port redirection is disabled.

### `fDisableClipboardRedirection`

Specifies whether clipboard redirection is disabled. This member can be one of the following values.

#### 0

The user can enable clipboard redirection.

#### 1

Clipboard redirection is disabled.

### `fDisableAudioRedirection`

Specifies whether audio redirection is disabled. This member can be one of the following values.

#### 0

The user can enable audio redirection.

#### 1

Audio redirection is disabled.

### `fDisablePNPRedirection`

Specifies whether Plug and Play redirection is disabled. This member can be one of the following values.

#### 0

The user can enable Plug and Play redirection.

#### 1

Plug and Play redirection is disabled.

### `fDisableDefaultMainClientPrinter`

Specifies whether the client printer is the default printer. This member can be one of the following values.

#### 0

The client printer is not the default printer.

#### 1

The client printer is the default printer.

### `LanAdapter`

The network adapter that the listener uses.

### `PortNumber`

The port number of the listener.

### `fInheritShadowSettings`

Specifies whether the listener should use the **ShadowSettings** value specified by the user. This member can be one of the following values.

#### 0

Use the setting specified by the server.

#### 1

Use the setting specified by the user.

### `ShadowSettings`

The remote control setting for the listener. Remote control allows a user to remotely monitor the on-screen operations of another user. This setting only applies when the **fInheritShadowSettings** member is zero. This member can be one of the following values.

#### 0

Remote control is disabled.

#### 1

The user of remote control has full control of the user's session, with the user's permission.

#### 2

The user of remote control has full control of the user's session; the user's permission is not required.

#### 3

The user of remote control can view the session remotely, with the user's permission; the remote user cannot actively control the session.

#### 4

The user of remote control can view the session remotely but not actively control the session; the user's permission is not required.

### `TimeoutSettingsConnection`

The maximum connection duration, in milliseconds. Every time the user logs on, the timer is reset. A value of zero indicates that the connection timer is disabled.

### `TimeoutSettingsDisconnection`

The maximum duration, in milliseconds, that a server retains a disconnected session before the logon is terminated. A value of zero indicates that the disconnection timer is disabled.

### `TimeoutSettingsIdle`

The maximum idle time, in milliseconds. A value of zero indicates that the idle timer is disabled.

### `SecurityLayer`

The security layer of the listener. This member can be one of the following values.

#### 0

Remote Desktop Protocol (RDP) is used by the server and the client for authentication before a connection is established.

#### 1

The server and the client negotiate the method for authentication before a connection is established.

#### 2

Transport Layer Security (TLS) protocol is used by the server and the client for authentication before a connection is established.

### `MinEncryptionLevel`

Encryption level of the listener.
This member can be one of the following values.

#### 1

Data sent from the client to the server is encrypted by using 56-bit encryption. Data sent from the server to the client is not encrypted.

#### 2

All data sent from the client to the server and from the server to the client is encrypted by using the maximum key strength supported by the client.

#### 3

All data sent from the client to the server and from the server to the client is encrypted by using 128-bit encryption. Clients that do not support this level of encryption cannot connect.

#### 4

All data sent from the client to the server and from the server to the client is encrypted and decrypted by using the Federal Information Processing Standards (FIPS) encryption algorithms and Microsoft cryptographic modules.

### `UserAuthentication`

Specifies whether network-level user authentication is required before the connection is established. This member can be one of the following values.

#### 0

Network-level user authentication is not required.

#### 1

Network-level user authentication is required.

### `Comment`

A null-terminated string that contains a description of the listener.

### `LogonUserName`

A null-terminated string that contains the user name used in automatic logon scenarios.

### `LogonDomain`

A null-terminated string that contains the domain name used in automatic logon scenarios.

### `WorkDirectory`

A null-terminated string that contains the path of the working directory of the initial program.

### `InitialProgram`

A null-terminated string that contains the name of the program to start immediately after the user logs on to the server.

## See also

[WTSCreateListener](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtscreatelistenera)

## Remarks

> [!NOTE]
> The wtsapi32.h header defines WTSLISTENERCONFIG as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).