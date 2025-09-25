# TakeSnapshotVhdSet function

## Description

Creates a snapshot of the current virtual disk for VHD Set files.

## Parameters

### `VirtualDiskHandle` [in]

A handle to the open virtual disk. This must be a VHD Set file.

### `Parameters` [in]

A pointer to a valid [TAKE_SNAPSHOT_VHDSET_PARAMETERS](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-take_snapshot_vhdset_parameters) structure that contains snapshot data.

### `Flags` [in]

Snapshot flags, which must be a valid combination of the [TAKE_SNAPSHOT_VHDSET_FLAG](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-take_snapshot_vhdset_flag) enumeration

## Return value

Status of the request.

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is an error code. For more information, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).