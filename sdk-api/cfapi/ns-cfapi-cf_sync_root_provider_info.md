## Description

Contains sync root provider information.

## Members

### `ProviderStatus`

Status of the sync root provider. See [CF_SYNC_PROVIDER_STATUS](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_sync_provider_status) for possible values.

### `ProviderName`

Name of the sync root provider. *ProviderName* is an end-user facing string with a maximum length of **CF_MAX_PROVIDER_NAME_LENGTH** (255 characters).

### `ProviderVersion`

Version of the sync root provider. *ProviderVersion* is an end-user facing string with a maximum length of **CF_MAX_PROVIDER_VERSION_LENGTH** (255 characters).

## See also

[CfGetSyncRootInfoByPath](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfgetsyncrootinfobypath)

[CF_SYNC_PROVIDER_STATUS](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_sync_provider_status)