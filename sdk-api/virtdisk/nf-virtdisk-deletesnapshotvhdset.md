# DeleteSnapshotVhdSet function

## Description

Deletes a snapshot from a VHD Set file.

## Parameters

### `VirtualDiskHandle` [in]

A handle to the open virtual disk. This must be a VHD Set file.

### `Parameters` [in]

A pointer to a valid [DELETE_SNAPSHOT_VHDSET_PARAMETERS](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-delete_snapshot_vhdset_parameters) structure that contains snapshot deletion data.

### `Flags` [in]

Snapshot deletion flags, which must be a valid combination of the [DELETE_SNAPSHOT_VHDSET_FLAG](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-delete_snapshot_vhdset_flag) enumeration.

## Return value

Status of the request.

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is an error code. For more information, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).