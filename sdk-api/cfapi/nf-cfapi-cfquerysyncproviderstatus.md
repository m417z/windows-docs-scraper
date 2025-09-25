# CfQuerySyncProviderStatus function

## Description

Queries a sync provider to get the status of the provider.

## Parameters

### `ConnectionKey` [in]

A connection key representing a communication channel with the sync filter.

### `ProviderStatus` [out]

The current status of the sync provider.

## Return value

If this function succeeds, it returns `S_OK`. Otherwise, it returns an **HRESULT** error code.

## See also

[CF_SYNC_PROVIDER_STATUS](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_sync_provider_status)