# CompactVirtualDisk function

## Description

Reduces the size of a virtual hard disk (VHD) backing store file.

## Parameters

### `VirtualDiskHandle` [in]

A handle to the open virtual disk, which must have been opened using the
**VIRTUAL_DISK_ACCESS_METAOPS** flag in the
*VirtualDiskAccessMask* parameter passed to
[OpenVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-openvirtualdisk). For information on how to open a
virtual disk, see the **OpenVirtualDisk** function.

### `Flags` [in]

Must be the **COMPACT_VIRTUAL_DISK_FLAG_NONE** value (0) of the
[COMPACT_VIRTUAL_DISK_FLAG](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-compact_virtual_disk_flag) enumeration.

### `Parameters` [in, optional]

A optional pointer to a valid
[COMPACT_VIRTUAL_DISK_PARAMETERS](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-compact_virtual_disk_parameters)
structure that contains compaction parameter data.

### `Overlapped` [in, optional]

An optional pointer to a valid [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)
structure if [asynchronous](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output)
operation is desired.

## Return value

Status of the request.

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is an error code. For more information, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

Compaction can be run only on a virtual disk that is dynamically expandable or differencing.

There are two different types of compaction.

* The first type, file-system-aware compaction, uses the NTFS file system to determine free space. This is
  done by attaching the VHD as a read-only device by including the
  **VIRTUAL_DISK_ACCESS_METAOPS** and
  **VIRTUAL_DISK_ACCESS_ATTACH_RO** flags in the
  *VirtualDiskAccessMask* parameter passed to
  [OpenVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-openvirtualdisk), attaching the VHD by calling
  [AttachVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-attachvirtualdisk), and while the VHD is attached
  calling **CompactVirtualDisk**. Detaching the VHD
  before compaction is done can cause compaction to return failure before it is done (similar to cancellation of
  compaction).
* The second type, file-system-agnostic compaction, does not involve the file system but only looks for VHD
  blocks filled entirely with zeros (0). This is done by including the
  **VIRTUAL_DISK_ACCESS_METAOPS** flag in the
  *VirtualDiskAccessMask* parameter passed to
  [OpenVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-openvirtualdisk), and calling
  **CompactVirtualDisk**.

File-system-aware compaction is the most efficient compaction type but using first the file-system-aware
compaction followed by the file-system-agnostic compaction will produce the smallest VHD.

A compaction operation on a virtual disk can be safely interrupted and re-run later. Re-opening a virtual disk
file that has been interrupted may result in the reduction of a virtual disk file's size at the time of
opening.

Compaction can be CPU-intensive and/or I/O-intensive, depending on how large the virtual disk is and how many
blocks require movement.

The **CompactVirtualDisk** function runs on the
virtual disk in the same security context as the caller.

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))