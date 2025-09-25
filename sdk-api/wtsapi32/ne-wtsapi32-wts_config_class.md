# WTS_CONFIG_CLASS enumeration

## Description

Contains
values that indicate the type of user configuration information to set or retrieve in a call to the
[WTSQueryUserConfig](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsqueryuserconfiga) and
[WTSSetUserConfig](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtssetuserconfiga) functions.

## Constants

### `WTSUserConfigInitialProgram`

A null-terminated string that contains the path of the initial program that Remote Desktop Services runs when the
user logs on.

If the **WTSUserConfigfInheritInitialProgram** value is 1, the initial program can be
any program specified by the client.

### `WTSUserConfigWorkingDirectory`

A null-terminated string that contains the path of the working directory for the initial program.

### `WTSUserConfigfInheritInitialProgram`

A value that indicates whether the client can specify the initial program.

| Value | Meaning |
| --- | --- |
| 0 | The client cannot specify the initial program. Instead, the **WTSUserConfigInitialProgram** string identifies an initial program that runs automatically when the user logs on to a remote computer. Remote Desktop Services logs the user off when the user exits that program. |
| 1 | The client can specify the initial program. |

### `WTSUserConfigfAllowLogonTerminalServer`

A value that indicates whether the user account is permitted to log on to an RD Session Host server.

| Value | Meaning |
| --- | --- |
| 0 | The user cannot log on. |
| 1 | The user can log on. |

### `WTSUserConfigTimeoutSettingsConnections`

A **DWORD** value that specifies the maximum connection duration, in milliseconds.
One minute before the connection time-out interval expires, the user is notified of the pending disconnection.
The user's session is disconnected or terminated depending on the
**WTSUserConfigBrokenTimeoutSettings** value. Every time the user logs on, the timer is
reset. A value of zero indicates that the connection timer is disabled.

### `WTSUserConfigTimeoutSettingsDisconnections`

A **DWORD** value that specifies the maximum duration, in milliseconds, that an
RD Session Host server retains a disconnected session before the logon is terminated. A value of zero indicates that the
disconnection timer is disabled.

### `WTSUserConfigTimeoutSettingsIdle`

A **DWORD** value that specifies the maximum idle time, in milliseconds. If there
is no keyboard or mouse activity for the specified interval, the user's session is disconnected or terminated
depending on the **WTSUserConfigBrokenTimeoutSettings** value. A value of zero
indicates that the idle timer is disabled.

### `WTSUserConfigfDeviceClientDrives`

This constant currently is not used by Remote Desktop Services.

A value that indicates whether the RD Session Host server automatically reestablishes
client drive mappings at logon.

| Value | Meaning |
| --- | --- |
| 0 | The server does not automatically connect to previously mapped client drives. |
| 1 | The server automatically connects to previously mapped client drives at logon. |

### `WTSUserConfigfDeviceClientPrinters`

RDP 5.0 and later clients: A value that indicates whether the RD Session Host server
automatically reestablishes client printer mappings at logon.

| Value | Meaning |
| --- | --- |
| 0 | The server does not automatically connect to previously mapped client printers. |
| 1 | The server automatically connects to previously mapped client printers at logon. |

### `WTSUserConfigfDeviceClientDefaultPrinter`

RDP 5.0 and later clients: A value that indicates whether the client printer
is the default printer.

| Value | Meaning |
| --- | --- |
| 0 | The client printer is not the default printer. |
| 1 | The client printer is the default printer. |

### `WTSUserConfigBrokenTimeoutSettings`

A value that indicates what happens when the connection or idle timers expire or when a connection is lost
due to a connection error.

| Value | Meaning |
| --- | --- |
| 0 | The session is disconnected. |
| 1 | The session is terminated. |

### `WTSUserConfigReconnectSettings`

A value that indicates how a disconnected session for this user can be reconnected.

| Value | Meaning |
| --- | --- |
| 0 | The user can log on to any client computer to reconnect to a disconnected session. |
| 1 | The user can reconnect to a disconnected session by logging on to the client computer used to establish the disconnected session. If the user logs on from a different client computer, the user gets a new logon session. |

### `WTSUserConfigModemCallbackSettings`

This constant currently is not used by Remote Desktop Services.

A value that indicates the configuration for dial-up connections in which the
RD Session Host server stops responding and then calls back the client to establish the connection.

| Value | Meaning |
| --- | --- |
| 0 | Callback connections are disabled. |
| 1 | The server prompts the user to enter a phone number and calls the user back at that phone number. You can use the **WTSUserConfigModemCallbackPhoneNumber** value to specify a default phone number. |
| 2 | The server automatically calls the user back at the phone number specified by the **WTSUserConfigModemCallbackPhoneNumber** value. |

### `WTSUserConfigModemCallbackPhoneNumber`

This constant currently is not used by Remote Desktop Services.

A null-terminated string that contains the phone number to use for callback
connections.

### `WTSUserConfigShadowingSettings`

RDP 5.0 and later clients: A value that indicates whether the user session
can be shadowed. Shadowing allows a user to remotely monitor the on-screen operations of another user.

| Value | Meaning |
| --- | --- |
| 0 | Disable |
| 1 | Enable input, notify |
| 2 | Enable input, no notify |
| 3 | Enable no input, notify |
| 4 | Enable no input, no notify |

### `WTSUserConfigTerminalServerProfilePath`

A null-terminated string that contains the path of the user's profile for RD Session Host server logon. The directory
the path identifies must be created manually, and must exist prior to the logon.
[WTSSetUserConfig](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtssetuserconfiga) will not create the directory
if it does not already exist.

### `WTSUserConfigTerminalServerHomeDir`

A null-terminated string that contains the path of the user's root directory for RD Session Host server logon. This
string can specify a local path or a UNC path (*\\ComputerName\Share\Path*). For more information, see
**WTSUserConfigfTerminalServerRemoteHomeDir**.

### `WTSUserConfigTerminalServerHomeDirDrive`

A null-terminated string that contains a drive name (a drive letter followed by a colon) to which the UNC
path specified in the **WTSUserConfigTerminalServerHomeDir** string is mapped. For more information, see
**WTSUserConfigfTerminalServerRemoteHomeDir**.

### `WTSUserConfigfTerminalServerRemoteHomeDir`

A value that indicates whether the user's root directory for RD Session Host server logon is a local path or a
mapped drive letter. Note that this value cannot be used with
[WTSSetUserConfig](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtssetuserconfiga).

| Value | Meaning |
| --- | --- |
| 0 | The **WTSUserConfigTerminalServerHomeDir** string contains the local path of the user's RD Session Host server logon root directory. |
| 1 | The **WTSUserConfigTerminalServerHomeDir** string contains the UNC path of the user's RD Session Host server logon root directory, and the **WTSUserConfigTerminalServerHomeDirDrive** string contains a drive letter to which the UNC path is mapped. |

### `WTSUserConfigUser`

A [WTSUSERCONFIG](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wtsuserconfiga) structure that contains configuration data for the session.

**Windows Server 2008 and Windows Vista:** This value is not supported.

## See also

[WTSQueryUserConfig](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsqueryuserconfiga)

[WTSSetUserConfig](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtssetuserconfiga)