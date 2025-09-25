## Description

Basic placeholder information.

## Members

### `PinState`

The [CF_PIN_STATE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_pin_state) of the placeholder, which is used to represent a user’s intent. See [CfSetPinState](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfsetpinstate) for more details.

### `InSyncState`

The [CF_IN_SYNC_STATE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_in_sync_state) of the placeholder. See [CfSetInSyncState](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfsetinsyncstate) for more details.

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