# IWRdsProtocolSettings::MergeSettings

## Description

Adds (merges) the specified policy-related settings into the larger group of connection settings.

## Parameters

### `pWRdsSettings` [in]

A pointer to a [WRDS_SETTINGS](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wrds_settings) structure that contains the policy-related settings to add.

### `WRdsConnectionSettingLevel` [in]

A value of the [WRDS_CONNECTION_SETTING_LEVEL](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ne-wtsdefs-wrds_connection_setting_level) enumeration that specifies the type of structure contained in the **WRdsConnectionSetting** member of the [WRDS_CONNECTION_SETTINGS](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wrds_connection_settings) structure.

### `pWRdsConnectionSettings` [in, out]

A pointer to a [WRDS_CONNECTION_SETTINGS](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wrds_connection_settings) structure that contains the existing connection settings. When the method returns, this structure is updated to include the merged settings.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails, return an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IWRdsProtocolSettings](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolsettings)