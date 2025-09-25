# WRDS_SETTINGS_1 structure

## Description

Contains policy-related settings for a remote session.

This structure is mostly a subset of the [WRDS_CONNECTION_SETTINGS_1](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wrds_connection_settings_1) structure. The settings correspond to policy settings that can be found in the group policy editor (Gpedit.exe). The settings in this structure overwrite the initial policy settings.

## Members

### `WRdsDisableClipStatus`

The clipboard redirection state (not applicable, disabled, enabled, or not configured). For more information, see the group policy node topic for [Device and Resource Redirection](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/ee791794(v=ws.10)).

### `WRdsDisableClipValue`

The clipboard redirection value. A value of 1 indicates that clipboard functionality is disabled (clipboard redirection is enabled); any other value means clipboard functionality is enabled. This value only takes effect if the **WRdsDisableClipStatus** member is set to enabled.

### `WRdsDisableLPTStatus`

The LPT printer redirection state (not applicable, disabled, enabled, or not configured). For more information, see the group policy node topic for [Device and Resource Redirection](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/ee791794(v=ws.10)).

### `WRdsDisableLPTValue`

The LPT printer redirection value. A value of 1 indicates that LPT printer redirection is enabled; any other value means LPT printer redirection is disabled. This value only takes effect if the **WRdsDisableLPTStatus** member is set to enabled.

### `WRdsDisableCcmStatus`

The COM port mapping state (not applicable, disabled, enabled, or not configured). For more information, see the group policy node topic for [Device and Resource Redirection](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/ee791794(v=ws.10)).

### `WRdsDisableCcmValue`

The COM port mapping value. A value of 1 indicates that COM port mapping is enabled; any other value means COM port mapping is disabled. This value only takes effect if the **WRdsDisableCcmStatus** member is set to enabled.

### `WRdsDisableCdmStatus`

The drive mapping state (not applicable, disabled, enabled, or not configured). For more information, see the group policy node topic for [Device and Resource Redirection](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/ee791794(v=ws.10)).

### `WRdsDisableCdmValue`

The drive mapping value. A value of 1 indicates that drive mapping is enabled; any other value means drive mapping is disabled. This value only takes effect if the **WRdsDisableCdmStatus** member is set to enabled.

### `WRdsDisableCpmStatus`

The printer mapping state (not applicable, disabled, enabled, or not configured). For more information, see the group policy node topic for [Printer Redirection](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/ee791784(v=ws.10)).

### `WRdsDisableCpmValue`

The printer mapping value. A value of 1 indicates that printer mapping is enabled; any other value means printer mapping is disabled. This value only takes effect if the **WRdsDisableCpmStatus** member is set to enabled.

### `WRdsDisablePnpStatus`

The state of the setting that controls Plug and Play (PNP) redirection (not applicable, disabled, enabled, or not configured). For more information, see the group policy node topic for [Device and Resource Redirection](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/ee791794(v=ws.10)).

### `WRdsDisablePnpValue`

The PNP redirection value. A value of 1 indicates that PNP redirection is enabled; any other value means PNP redirection is disabled. This value only takes effect if the **WRdsDisablePnpStatus** member is set to enabled.

### `WRdsEncryptionLevelStatus`

The encryption level state (not applicable, disabled, enabled, or not configured). For more information, see the group policy node topic for [Security](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/ee791904(v=ws.10)).

### `WRdsEncryptionValue`

The encryption level value. This value only takes effect if the **WRdsEncryptionLevelStatus** member is set to enabled.

### `WRdsColorDepthStatus`

The color depth state (not applicable, disabled, enabled, or not configured). For more information, see the group policy node topic for [Remote Session Environment](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/ee791847(v=ws.10)).

### `WRdsColorDepthValue`

The color depth value. For possible values, see the **ColorDepth** member of the [WTS_CLIENT_DISPLAY](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_client_display) structure. This value only takes effect if the **WRdsColorDepthStatus** member is set to enabled.

### `WRdsDisableAutoReconnecetStatus`

The automatic client reconnection state (not applicable, disabled, enabled, or not configured). For more information, see the group policy node topic for [Connections](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/ee791922(v=ws.10)).

### `WRdsDisableAutoReconnecetValue`

The automatic client reconnection value. A value of 1 indicates that automatic client reconnection is disabled; any other value means automatic client reconnection is enabled. This value only takes effect if the **WRdsDisableAutoReconnecetStatus** member is set to enabled.

### `WRdsDisableEncryptionStatus`

The state (not applicable, disabled, enabled, or not configured) of the setting that controls whether to disable encryption for communication between the client and the server. For more information, see the group policy node topic for [Security](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/ee791904(v=ws.10)).

### `WRdsDisableEncryptionValue`

The encryption disabling value. A value of 1 indicates that encryption is disabled; any other value means encryption is required. This value only takes effect if the **WRdsDisableEncryptionStatus** member is set to enabled.

### `WRdsResetBrokenStatus`

The state (not applicable, disabled, enabled, or not configured) of the setting that controls how the server reacts when the connection or idle timers expire, or when a connection is lost due to a connection error. For more information, see the group policy node topic for [Session Time Limits](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/ee791741(v=ws.10)).

### `WRdsResetBrokenValue`

The value of the setting that controls the server reaction. A value of 1 indicates that the session is terminated whenever the time-out limit is reached; any other value means the session is disconnected but remains on the server. This value only takes effect if the **WRdsResetBrokenStatus** member is set to enabled.

### `WRdsMaxIdleTimeStatus`

The maximum idle time state (not applicable, disabled, enabled, or not configured). For more information, see the group policy node topic for [Session Time Limits](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/ee791741(v=ws.10)).

### `WRdsMaxIdleTimeValue`

The maximum amount of time, in minutes, that the Remote Desktop Services session can remain idle. This value only takes effect if the **WRdsMaxIdleTimeStatus** member is set to enabled.

### `WRdsMaxDisconnectTimeStatus`

The maximum disconnection time state (not applicable, disabled, enabled, or not configured). For more information, see the group policy node topic for [Session Time Limits](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/ee791741(v=ws.10)).

### `WRdsMaxDisconnectTimeValue`

The maximum amount of time, in minutes, that a disconnected Remote Desktop Services session remains active on the RD Session Host server.

This value only takes effect if the **WRdsMaxDisconnectTimeStatus** member is set to enabled.

### `WRdsMaxConnectTimeStatus`

The maximum connection time state (not applicable, disabled, enabled, or not configured). For more information, see the group policy node topic for [Session Time Limits](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/ee791741(v=ws.10)).

### `WRdsMaxConnectTimeValue`

The maximum duration of the Remote Desktop Services session, in minutes. This value only takes effect if the **WRdsMaxConnectTimeStatus** member is set to enabled.

### `WRdsKeepAliveStatus`

The state (not applicable, disabled, enabled, or not configured) of the *keep alive* setting. The keep alive setting controls whether to check to keep a Remote Desktop Services session active. For more information, see the group policy node topic for [Connections](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/ee791922(v=ws.10)).

### `WRdsKeepAliveStartValue`

Specifies whether or not the keep alive setting is enabled.

#### TRUE

The keep alive setting is enabled.

#### FALSE

The keep alive setting is disabled.

### `WRdsKeepAliveIntervalValue`

The amount of time, in minutes, of idle time before the state of the Remote Desktop Services session is checked. This value only takes effect if the **WRdsKeepAliveStatus** member is set to enabled.

## See also

[Remote Desktop Session Host](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/ee791760(v=ws.10))