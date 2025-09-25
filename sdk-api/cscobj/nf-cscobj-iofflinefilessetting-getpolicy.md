# IOfflineFilesSetting::GetPolicy

## Description

Retrieves a policy associated with a particular Offline Files setting.

## Parameters

### `pvarValue` [out]

If the policy supports one or more values, the returned [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) object contains those values. If the policy does not support values, the type of the returned **VARIANT** is **VT_EMPTY**.

The method initializes the [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) prior to storing the policy value in it.

### `dwScope` [in]

Indicates which policy is to be retrieved. Must be one of the following.

**Note** Note that not all settings have an associated policy and those that do might not support both per-machine and per-user policy.

#### OFFLINEFILES_SETTING_SCOPE_USER (0x00000001)

The per-user policy is to be retrieved.

#### OFFLINEFILES_SETTING_SCOPE_COMPUTER (0x00000002)

The per-machine policy is to be retrieved.

## Return value

**S_OK** if the policy is read successfully or an error value otherwise.

Returns `HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)` if the setting does not support the requested policy.

Returns `HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)` if the requested policy is not currently applied.

## Remarks

It is important to note that policy cannot be set through the Offline Files API. Policy can be set only through the Group Policy mechanism. The Offline Files API only supports querying policy values.

## See also

[IOfflineFilesSetting](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessetting)