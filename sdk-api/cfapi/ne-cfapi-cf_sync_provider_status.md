# CF_SYNC_PROVIDER_STATUS enumeration

## Description

Current status of a sync provider.

## Constants

### `CF_PROVIDER_STATUS_DISCONNECTED:0x00000000`

The sync provider is disconnected.

### `CF_PROVIDER_STATUS_IDLE:0x00000001`

The sync provider is idle.

### `CF_PROVIDER_STATUS_POPULATE_NAMESPACE:0x00000002`

The sync provider is populating a namespace.

### `CF_PROVIDER_STATUS_POPULATE_METADATA:0x00000004`

The sync provider is populating placeholder metadata.

### `CF_PROVIDER_STATUS_POPULATE_CONTENT:0x00000008`

The sync provider is populating placeholder content.

### `CF_PROVIDER_STATUS_SYNC_INCREMENTAL:0x00000010`

The sync provider is incrementally syncing placeholder content.

### `CF_PROVIDER_STATUS_SYNC_FULL:0x00000020`

The sync provider has fully synced placeholder file data.

### `CF_PROVIDER_STATUS_CONNECTIVITY_LOST:0x00000040`

The sync provider has lost connectivity.

### `CF_PROVIDER_STATUS_CLEAR_FLAGS:0x80000000`

Clears the flags of the sync provider.

### `CF_PROVIDER_STATUS_TERMINATED:0xC0000001`

The sync provider has been terminated.

### `CF_PROVIDER_STATUS_ERROR:0xC0000002`

There was an error with the sync provider.

## See also

[CfGetSyncRootInfoByPath](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfgetsyncrootinfobypath)