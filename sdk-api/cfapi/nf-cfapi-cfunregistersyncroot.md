# CfUnregisterSyncRoot function

## Description

Unregisters a previously registered sync root.

## Parameters

### `SyncRootPath` [in]

The path to the sync root to be unregistered.

## Return value

If this function succeeds, it returns `S_OK`. Otherwise, it returns an **HRESULT** error code.

## Remarks

Unregisters a sync root that was registered with [CfRegisterSyncRoot](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfregistersyncroot). This is typically called at the sync provider uninstall time, when a user account is deleted, or when a user opts to no longer sync a directory tree (if supported by the sync provider). If the sync root to be unregistered has never been registered before, the API fails with **STATUS_CLOUD_FILE_NOT_UNDER_SYNC_ROOT**.

The sync provider should have **WRITE_DATA** or **WRITE_DAC** access to the sync root to be unregistered, or unregistration will fail with **HRESULT(ERROR_CLOUD_FILE_ACCESS_DENIED)**. Unregistration will also fail with **HRESULT(ERROR_CLOUD_FILE_INVALID_REQUEST)** if a sync provider is *connected* to the sync root.

Unregisters a sync root by traversing the directory tree of the sync root.

For placeholder files:

- If a placeholder file is fully hydrated, it is reverted back to a "normal" file.
- If a placeholder file is not hydrated, it is permanently deleted from the local machine.

For placeholder directories:

- If a placeholder directory is fully populated, it is reverted back to a "normal" directory.
- If a placeholder directory is not fully populated, the directory is permanently deleted from the local machine.

>[!NOTE]
>If the placeholder files or directories cannot be reverted or deleted, it will be skipped, and the unregistering process will continue until the full sync root tree has been traversed.

## See also

[CfRegisterSyncRoot](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfregistersyncroot)