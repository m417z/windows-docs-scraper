# IOfflineFilesSetting::GetPolicyScope

## Description

Retrieves the scope of the policy associated with this setting.

## Parameters

### `pdwScope` [out]

Receives the supported scope of the policy for this setting. This scope can be one or both of the following values.

#### OFFLINEFILES_SETTING_SCOPE_USER (0x00000001)

The setting supports per-user policy.

#### OFFLINEFILES_SETTING_SCOPE_COMPUTER (0x00000002)

The setting supports per-machine policy.

## Return value

S_OK if the scope is returned successfully or an error value otherwise.

## Remarks

Note that this is an indication of the supported scopes, not of the applied scopes. For example, a setting may recognize both per-user and per-machine policy yet only the per-user policy has been applied. In this scenario, this API would return both OFFLINEFILES_SETTING_SCOPE_USER and OFFLINEFILES_SETTING_SCOPE_COMPUTER.

## See also

[IOfflineFilesSetting](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessetting)