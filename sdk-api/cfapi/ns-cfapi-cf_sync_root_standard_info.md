## Description

Standard sync root information.

## Members

### `SyncRootFileId`

File ID of the sync root.

### `HydrationPolicy`

Hydration policy of the sync root. See [CF_HYDRATION_POLICY_PRIMARY](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_hydration_policy_primary) for more information.

### `PopulationPolicy`

Population policy of the sync root. See [CF_POPULATION_POLICY_PRIMARY](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_population_policy_primary) for more information.

### `InSyncPolicy`

In-sync policy of the sync root. See [CF_INSYNC_POLICY](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_insync_policy) for possible values.

### `HardLinkPolicy`

Sync root hard linking policy. See [CF_HARDLINK_POLICY](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_hardlink_policy) for possible values.

### `ProviderStatus`

Status of the sync root provider. See [CF_SYNC_PROVIDER_STATUS](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_sync_provider_status) for possible values.

### `ProviderName`

Name of the sync root. *ProviderName* is an end-user facing string with a maximum length of **CF_MAX_PROVIDER_NAME_LENGTH** (255 characters).

### `ProviderVersion`

Version of the sync root. *ProviderVersion* is an end-user facing string with a maximum length of **CF_MAX_PROVIDER_VERSION_LENGTH** (255 characters).

### `SyncRootIdentityLength`

Length, in bytes, of the *SyncRootIdentity*.

### `SyncRootIdentity`

The identity of the sync root directory.

## Remarks

## See also

[CF_HYDRATION_POLICY_PRIMARY](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_hydration_policy_primary)

[CF_POPULATION_POLICY_PRIMARY](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_population_policy_primary)

[CF_INSYNC_POLICY](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_insync_policy)

[CF_HARDLINK_POLICY](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_hardlink_policy)

[CF_SYNC_PROVIDER_STATUS](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_sync_provider_status)

[CfGetSyncRootInfoByPath](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfgetsyncrootinfobypath)