# WRDS_CONNECTION_SETTINGS structure

## Description

Contains connection setting information for a remote session.

## Members

### `WRdsConnectionSettingLevel`

A value of the [WRDS_CONNECTION_SETTING_LEVEL](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ne-wtsdefs-wrds_connection_setting_level) enumeration that specifies the type of structure that is contained in the **WRdsConnectionSetting** member.

#### WRDS_CONNECTION_SETTING_LEVEL_1

The structure is a [WRDS_CONNECTION_SETTINGS_1](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wrds_connection_settings_1) structure.

### `WRdsConnectionSetting`

A [WRDS_CONNECTION_SETTING](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wrds_connection_setting) structure that specifies the connection settings.

## See also

[IWRdsProtocolConnection::LogonNotify](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolconnection-logonnotify)