# WTS_CLIENT_DATA structure

## Description

Contains information about the client connection.

## Members

### `fDisableCtrlAltDel`

Specifies whether the logon (CTRL+ALT+DELETE) key sequence is disabled.

### `fDoubleClickDetect`

Specifies whether the client can double-click.

### `fEnableWindowsKey`

Specifies whether the Windows key is enabled.

### `fHideTitleBar`

Specifies whether the title bar is hidden.

### `fInheritAutoLogon`

Specifies whether the logon process is automatic. This value overwrites the **fInheritAutoLogon** listener registry value.

### `fPromptForPassword`

Specifies whether to prompt the user for a password. If this value is **TRUE**, the user will be prompted even if the **fInheritAutoLogon** registry value is **TRUE** and the "Always ask for a password" policy is not set.

### `fUsingSavedCreds`

Specifies whether the client is using saved credentials during the logon process.

### `Domain`

A string value that specifies the domain of the user. This value is used if **fInheritAutoLogon** is set to **TRUE**.

### `UserName`

A string value that specifies the user name. This value is used if **fInheritAutoLogon** is set to **TRUE**.

### `Password`

A string value that specifies the user password. This value is used if **fInheritAutoLogon** is set to **TRUE**.

### `fPasswordIsScPin`

Specifies that a smart card was used during the logon process. The smart card PIN is the password. This value is used if **fInheritAutoLogon** is set to **TRUE**.

### `fInheritInitialProgram`

Specifies whether the initial program to start in the Remote Desktop Services shell is inherited. This value overwrites the **fInheritInitialProgram** listener registry value.

### `WorkDirectory`

A string value that specifies the directory where the initial program resides. This value is used if **fInheritInitialProgram** is set to **TRUE**.

### `InitialProgram`

A string value that specifies the name of the initial program. This value is used if **fInheritInitialProgram** is set to **TRUE**.

### `fMaximizeShell`

Specifies whether the initial program is displayed maximized. This value is used if **fInheritInitialProgram** is set to **TRUE**.

### `EncryptionLevel`

Specifies the encryption level.

### `PerformanceFlags`

Specifies a list of features that can be disabled to increase performance.

### `ProtocolName`

A string value that contains the protocol name.

### `ProtocolType`

Specifies the protocol type.

### `fInheritColorDepth`

Specifies whether to inherit the monitor color depth. This value overwrites the **fInheritColorDepth** listener registry value.

### `HRes`

Specifies the client monitor horizontal resolution.

### `VRes`

Specifies the client monitor vertical resolution.

### `ColorDepth`

Specifies the client monitor color depth. For possible values, see the **ColorDepth** member of the [WTS_CLIENT_DISPLAY](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_client_display) structure.

### `DisplayDriverName`

A string value that specifies the name of the display driver to load.

### `DisplayDeviceName`

A string value that specifies the name of the display device. For example, if a protocol creates a display device with the name "\\Device\VideoDev0", this field must contain the string "VideoDev".

### `fMouse`

Specifies whether mouse input is enabled.

### `KeyboardLayout`

Specifies the keyboard layout.

### `KeyboardType`

Specifies the keyboard type.

### `KeyboardSubType`

Specifies the keyboard subtype.

### `KeyboardFunctionKey`

Specifies the function key.

### `imeFileName`

Specifies the input method editor name.

### `ActiveInputLocale`

Specifies the input locale identifier. The low word contains a language identifier and the high word contains a device handle to the physical layout of the keyboard.

### `fNoAudioPlayback`

Specifies whether to turn on audio. A value of **TRUE** specifies no audio.

### `fRemoteConsoleAudio`

Specifies whether to leave audio playback on the remote computer.

### `AudioDriverName`

A string value that contains the name of the audio driver to load.

### `ClientTimeZone`

A [WTS_TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_time_zone_information) structure that contains client time zone information.

### `ClientName`

A string value that contains the fully qualified name of the client computer.

### `SerialNumber`

Client computer serial number.

### `ClientAddressFamily`

The client IP address family.

### `ClientAddress`

A string value that contains the client IP address in dotted decimal format.

### `ClientSockAddress`

A [WTS_SOCKADDR](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_sockaddr) structure that contains information about the client socket.

### `ClientDirectory`

A string value that contains the client directory.

### `ClientBuildNumber`

Client build number.

### `ClientProductId`

Client product ID.

### `OutBufCountHost`

Number of output buffers on the host computer.

### `OutBufCountClient`

Number of output buffers on the client computer.

### `OutBufLength`

Output buffer length.

### `ClientSessionId`

Client session ID.

### `ClientDigProductId`

A string value that contains a client product identifier.

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

### `fDisablePNP`

Specifies whether PNP redirection is enabled. This value is initially set from policy information. If you reset the value, the policy will be overwritten.