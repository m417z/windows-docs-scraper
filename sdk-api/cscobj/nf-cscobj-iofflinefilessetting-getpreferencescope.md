# IOfflineFilesSetting::GetPreferenceScope

## Description

Indicates the scope of the preference associated with this setting.

## Parameters

### `pdwScope` [out]

Receives the supported scope of the policy for this setting. This scope can be one or both of the following values.

#### OFFLINEFILES_SETTING_SCOPE_USER (0x00000001)

The setting supports per-user preference.

#### OFFLINEFILES_SETTING_SCOPE_COMPUTER (0x00000002)

The setting supports per-machine preference.

## Return value

S_OK if the scope is returned successfully or an error value otherwise.

## Remarks

Note that this is an indication of the supported scopes, not of the applied scopes. For example, a setting may recognize both per-user and per-machine preference yet only the per-user preference has been applied. In this scenario, this method would return both OFFLINEFILES_SETTING_SCOPE_USER and OFFLINEFILES_SETTING_SCOPE_COMPUTER.

## See also

[IOfflineFilesSetting](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessetting)