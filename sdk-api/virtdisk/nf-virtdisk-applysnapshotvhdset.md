# ApplySnapshotVhdSet function

## Description

Applies a snapshot of the current virtual disk for VHD Set files.

## Parameters

### `VirtualDiskHandle` [in]

A handle to an open virtual disk. For information on how to open a virtual disk, see the
[OpenVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-openvirtualdisk) function.

### `Parameters` [in]

A pointer to a valid [APPLY_SNAPSHOT_VHDSET_PARAMETERS](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-apply_snapshot_vhdset_parameters) structure that contains snapshot data.

### `Flags` [in]

A valid combination of values of the
[APPLY_SNAPSHOT_VHDSET_FLAG](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-apply_snapshot_vhdset_flag) enumeration.

## Return value

Status of the request.

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is an error code. For more information, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[VHD Functions](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323699(v=vs.85))