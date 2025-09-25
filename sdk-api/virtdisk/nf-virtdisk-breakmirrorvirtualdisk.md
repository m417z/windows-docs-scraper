# BreakMirrorVirtualDisk function

## Description

Breaks a previously initiated mirror operation and sets the mirror to be the active virtual
disk.

## Parameters

### `VirtualDiskHandle` [in]

A handle to the open mirrored virtual disk. For information on how to open a virtual disk, see the
[OpenVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-openvirtualdisk) function. For information on how to
mirror a virtual disk, see the [MirrorVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-breakmirrorvirtualdisk)
function.

## Return value

Status of the request.

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is an error code. For more information, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[MirrorVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-breakmirrorvirtualdisk)

[OpenVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-openvirtualdisk)

[VHD Functions](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323699(v=vs.85))