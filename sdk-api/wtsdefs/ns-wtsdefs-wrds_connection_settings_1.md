# WRDS_CONNECTION_SETTINGS_1 structure

## Description

Contains connection setting information for a remote session.

## Members

### `fInheritInitialProgram`

Specifies whether the initial program to start in the Remote Desktop Services shell is inherited. This value overwrites the **fInheritInitialProgram** listener registry value.

### `fInheritColorDepth`

Specifies whether to inherit the monitor color depth. This value overwrites the **fInheritColorDepth** listener registry value.

### `fHideTitleBar`

Specifies whether the title bar is hidden.

### `fInheritAutoLogon`

Specifies whether the logon process is automatic. This value overwrites the **fInheritAutoLogon** listener registry value.

### `fMaximizeShell`

Specifies whether the initial program is displayed maximized. This value is used if **fInheritInitialProgram** is set to **TRUE**.

### `fDisablePNP`

Specifies whether PNP redirection is enabled. This value is initially set from policy information. If you reset the value, the policy will be overwritten.

### `fPasswordIsScPin`

Specifies that a smart card was used during the logon process. The smart card PIN is the password. This value is used if **fInheritAutoLogon** is set to **TRUE**.

### `fPromptForPassword`

Specifies whether to prompt the user for a password. If this value is **TRUE**, the user will be prompted even if the **fInheritAutoLogon** registry value is **TRUE** and the "Always ask for a password" policy is not set.

### `fDisableCpm`

Specifies whether printer mapping is enabled. This value is initially set from policy information. If you reset the value, the policy will be overwritten.

### `fDisableCdm`

Specifies whether drive mapping is enabled. This value is initially set from policy information. If you reset the value, the policy will be overwritten.

### `fDisableCcm`

Specifies whether COM port mapping is enabled. This value is initially set from policy information. If you reset the value, the policy will be overwritten.

### `fDisableLPT`

Specifies whether LPT printer redirection is enabled. This value is initially set from policy information. If you reset the value, the policy will be overwritten.

### `fDisableClip`

Specifies whether clipboard redirection is enabled. This value is initially set from policy information. If you reset the value, the policy will be overwritten.

### `fResetBroken`

Specifies the action the server takes when the connection or idle timers expire, or when a connection is lost due to a connection error.

#### FALSE

The session is disconnected, but it remains on the server.

#### TRUE

The session is terminated.

### `fDisableEncryption`

Specifies whether to disable encryption for communication between the client and server.

### `fDisableAutoReconnect`

Specifies whether to disable automatic reconnect of the client.

### `fDisableCtrlAltDel`

Specifies whether the Ctrl+Alt+Delete keyboard shortcut is disabled.

### `fDoubleClickDetect`

Specifies whether the client can double-click.

### `fEnableWindowsKey`

Specifies whether the Windows key is enabled.

### `fUsingSavedCreds`

Specifies whether the client is using saved credentials during the logon process.

### `fMouse`

Specifies whether mouse input is enabled.

### `fNoAudioPlayback`

Specifies whether to turn on audio playback. A value of **TRUE** specifies no audio.

### `fRemoteConsoleAudio`

Specifies whether to leave audio playback on the remote computer.

### `EncryptionLevel`

Specifies the encryption level.

### `ColorDepth`

Specifies the client monitor color depth. For possible values, see the **ColorDepth** member of the [WTS_CLIENT_DISPLAY](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_client_display) structure.

### `ProtocolType`

Specifies the protocol type.

### `HRes`

Specifies the client monitor horizontal resolution.

### `VRes`

Specifies the client monitor vertical resolution.

### `ClientProductId`

The client software product id.

### `OutBufCountHost`

The number of output buffers on the host.

### `OutBufCountClient`

The number of output buffers on the client.

### `OutBufLength`

The length of output buffers, in bytes.

### `KeyboardLayout`

Specifies the keyboard layout.

### `MaxConnectionTime`

The maximum duration of the Remote Desktop Services session, in minutes.

### `MaxDisconnectionTime`

The maximum amount of time, in minutes, that a disconnected Remote Desktop Services session remains active on the RD Session Host server.

### `MaxIdleTime`

The maximum amount of time, in minutes, that the Remote Desktop Services session can remain idle.

### `PerformanceFlags`

Specifies a set of features that can be set at the server to improve performance. This can be a combination of one or more of the following values.

#### WRDS_PERF_DISABLE_NOTHING (0x00000000)

No features are disabled.

#### WRDS_PERF_DISABLE_WALLPAPER (0x00000001)

Wallpaper on the desktop is not displayed.

#### WRDS_PERF_DISABLE_FULLWINDOWDRAG (0x00000002)

Full-window drag is disabled; only the window outline is displayed when the window is moved.

#### WRDS_PERF_DISABLE_MENUANIMATIONS (0x00000004)

Menu animations are disabled.

#### WRDS_PERF_DISABLE_THEMING (0x00000008)

Themes are disabled.

#### WRDS_PERF_ENABLE_ENHANCED_GRAPHICS (0x00000010)

Enable enhanced graphics.

#### WRDS_PERF_DISABLE_CURSOR_SHADOW (0x00000020)

No shadow is displayed for the cursor.

#### WRDS_PERF_DISABLE_CURSORSETTINGS (0x00000040)

Cursor blinking is disabled.

#### WRDS_PERF_ENABLE_FONT_SMOOTHING (0x00000080)

Enable font smoothing.

#### WRDS_PERF_ENABLE_DESKTOP_COMPOSITION (0x00000100)

Enable desktop composition.

### `KeyboardType`

Specifies the keyboard type.

### `KeyboardSubType`

Specifies the keyboard subtype.

### `KeyboardFunctionKey`

Specifies the function key.

### `ActiveInputLocale`

Specifies the input locale identifier. The low word contains a language identifier and the high word contains a device handle to the physical layout of the keyboard.

### `SerialNumber`

The client computer's unique serial number.

### `ClientAddressFamily`

The client IP address family.

### `ClientBuildNumber`

The client build number.

### `ClientSessionId`

The client session Id.

### `WorkDirectory`

A string that contains the directory where the initial program resides. This value is used if **fInheritInitialProgram** is set to **TRUE**.

### `InitialProgram`

A string value that specifies the name of the initial program. This value is used if **fInheritInitialProgram** is set to **TRUE**.

### `UserName`

A string that specifies the user name. This value is used if **fInheritAutoLogon** is set to **TRUE**.

### `Domain`

A string that specifies the domain of the user. This value is used if **fInheritAutoLogon** is set to **TRUE**.

### `Password`

A string that specifies the user password. This value is used if **fInheritAutoLogon** is set to **TRUE**.

### `ProtocolName`

A string that contains the protocol name.

### `DisplayDriverName`

A string that specifies the name of the display driver to load.

### `DisplayDeviceName`

A string that specifies the name of the display device.

### `imeFileName`

Specifies the input method editor name.

### `AudioDriverName`

A string that contains the name of the audio driver to load.

### `ClientName`

A string that contains the fully qualified name of the client computer.

### `ClientAddress`

A string that contains the client IP address in dotted decimal format.

### `ClientDirectory`

The client directory.

A string that contains the client directory.

### `ClientDigProductId`

A string that contains a client product identifier.

### `ClientSockAddress`

A [WRDS_SOCKADDR](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_sockaddr) structure that contains socket address information.

### `ClientTimeZone`

A [WRDS_TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_time_zone_information) structure that contains client time zone information.

### `WRdsListenerSettings`

A [WRDS_LISTENER_SETTINGS](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wrds_listener_settings) structure that contains listener settings.

### `EventLogActivityId`

### `ContextSize.range`

### `ContextSize.range.0`

### `ContextSize.range.16384`

### `ContextData.size_is`

### `ContextData.size_is.ContextSize`

### `ContextSize`

The size, in bytes, of the **ContextData** array.

### `ContextData`

An array of bytes that contains contextual data for the connection. The size of this array is specified in the **ContextSize** member.