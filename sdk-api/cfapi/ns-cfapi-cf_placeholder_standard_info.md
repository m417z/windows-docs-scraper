## Description

Standard placeholder information.

## Members

### `OnDiskDataSize`

Total number of bytes on disk.

### `ValidatedDataSize`

Total number of bytes that are in sync with the cloud.

### `ModifiedDataSize`

Total number of bytes that have been overwritten/appended locally and are not in sync with the cloud.

### `PropertiesSize`

Total number of bytes on disk that are used by all the property blobs.

### `PinState`

The [CF_PIN_STATE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_pin_state) of the placeholder. See [CfSetPinState](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfsetpinstate) for more details.

### `InSyncState`

The [CF_IN_SYNC_STATE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_in_sync_state) of the placeholder. see [CfSetInSyncState](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfsetinsyncstate) for more details.

### `FileId`

A 64-bit volume wide non-volatile number that uniquely identifies a file or directory.

### `SyncRootFileId`

The file ID of the sync root directory that contains the file whose placeholder information is to be queried.

### `FileIdentityLength`

Length, in bytes, of the *FileIdentity*.

### `FileIdentity`

An opaque blob supplied by the sync provider to the platform when the placeholder was created. File identity is provided for all sync provider callbacks.

## See also

[CF_PIN_STATE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_pin_state)

[CfSetPinState](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfsetpinstate)

[CF_IN_SYNC_STATE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_in_sync_state)

[CfSetInSyncState](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfsetinsyncstate)