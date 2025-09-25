# CfSetInSyncState function

## Description

Sets the in-sync state for a placeholder file or folder.

## Parameters

### `FileHandle` [in]

A handle to the placeholder. The platform properly synchronizes the operation with other active requests. An attribute or no-access handle is sufficient. The caller must have **WRITE_DATA** or **WRITE_DAC** access to the placeholder.

### `InSyncState` [in]

The in-sync state. *InSyncState* can be set to one of the following values:

- If **CF_IN_SYNC_STATE_NOT_IN_SYNC** is specified, the platform clears the placeholder’s in-sync state upon a successful return from the API call.
- If **CF_IN_SYNC_STATE_IN_SYNC** is specified, the platform sets the placeholder’s in-sync state upon a successful return from the API call.

### `InSyncFlags` [in]

The in-sync state flags. See [CF_SET_IN_SYNC_FLAGS](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_set_in_sync_flags) for more details.

### `InSyncUsn` [in, out, optional]

When specified, on input, *InSyncUsn* instructs the platform to only perform in-sync setting if the file still has the same USN value as the one passed in. This is to close a race where the sync provider has just sync’d placeholder changes up to the cloud, but before the call to **CfSetInSyncState**, the placeholder changed in some way. Passing a pointer to a USN value of `0` on input is the same as passing a `NULL` pointer. On return, *InSYncUsn* receives the final USN value after setting the in-sync state.

## Return value

If this function succeeds, it returns `S_OK`. Otherwise, it returns an **HRESULT** error code.

## See also

[CF_IN_SYNC_STATE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_in_sync_state)

[CF_SET_IN_SYNC_FLAGS](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_set_in_sync_flags)