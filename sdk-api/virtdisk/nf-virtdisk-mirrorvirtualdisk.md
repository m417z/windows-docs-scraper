# MirrorVirtualDisk function

## Description

Initiates a mirror operation for a virtual disk. Once the mirroring operation is initiated
it will not complete until either [CancelIo](https://learn.microsoft.com/windows/desktop/FileIO/cancelio) or
[CancelIoEx](https://learn.microsoft.com/windows/desktop/FileIO/cancelioex-func) is called to cancel all I/O on the
*VirtualDiskHandle*, leaving the original file as the current or
[BreakMirrorVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-breakmirrorvirtualdisk) is called to stop using
the original file and only use the mirror.
[GetVirtualDiskOperationProgress](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-getvirtualdiskoperationprogress) can be
used to determine if the disks are fully mirrored and writes go to both virtual disks.

## Parameters

### `VirtualDiskHandle` [in]

A handle to the open virtual disk. For information on how to open a virtual disk, see the
[OpenVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-openvirtualdisk) function.

### `Flags` [in]

A valid combination of values from the
[MIRROR_VIRTUAL_DISK_FLAG](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-mirror_virtual_disk_flag) enumeration.

| Value | Meaning |
| --- | --- |
| **MIRROR_VIRTUAL_DISK_FLAG_NONE**<br><br>0x00000000 | The mirror virtual disk file does not exist, and needs to be created. |
| **MIRROR_VIRTUAL_DISK_FLAG_EXISTING_FILE**<br><br>0x00000001 | Create the mirror using an existing file. |

### `Parameters` [in]

Address of a
[MIRROR_VIRTUAL_DISK_PARAMETERS](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-mirror_virtual_disk_parameters) structure
containing mirror parameter data.

### `Overlapped` [in]

Address of an
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure. This parameter is required.

## Return value

Status of the request.

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is an error code. For more information, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[MIRROR_VIRTUAL_DISK_FLAG](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-mirror_virtual_disk_flag)

[MIRROR_VIRTUAL_DISK_PARAMETERS](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-mirror_virtual_disk_parameters)

[VHD Functions](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323699(v=vs.85))