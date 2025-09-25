# IWRdsProtocolSettings::GetSettings

## Description

Retrieves the settings for a particular policy.

## Parameters

### `WRdsSettingType` [in]

A value of the [WRDS_SETTING_TYPE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ne-wtsdefs-wrds_setting_type) enumeration that specifies the area in which to retrieve the settings (machine group policy, user group policy, or user security accounts manager).

### `WRdsSettingLevel` [in]

A value of the [WRDS_SETTING_LEVEL](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ne-wtsdefs-wrds_setting_level) enumeration that specifies the type of structure contained in the **WRdsSetting** member of the [WRDS_SETTINGS](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wrds_settings) structure.

### `pWRdsSettings` [out]

A pointer to a [WRDS_SETTINGS](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wrds_settings) structure that contains the returned settings.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails, return an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IWRdsProtocolSettings](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolsettings)