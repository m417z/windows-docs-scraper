# CfUpdateSyncProviderStatus function

## Description

Updates the current status of the sync provider.

## Parameters

### `ConnectionKey` [in]

A connection key representing a communication channel with the sync filter.

### `ProviderStatus` [in]

The current status of the sync provider. The status persists for the life of the sync root connection. The sync root connection is torn down either when [CfDisconnectSyncRoot](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfdisconnectsyncroot) is called or if the sync provider process is terminated.

## Return value

If this function succeeds, it returns `S_OK`. Otherwise, it returns an **HRESULT** error code.

## See also

[CfDisconnectSyncRoot](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfdisconnectsyncroot)

[CF_SYNC_PROVIDER_STATUS](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_sync_provider_status)