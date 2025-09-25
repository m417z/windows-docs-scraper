# QueryChangesVirtualDisk function

## Description

Retrieves information about changes to the specified areas of a virtual hard disk (VHD) that are tracked by resilient change tracking (RCT).

## Parameters

### `VirtualDiskHandle` [in]

A handle to the open VHD, which must have been opened using the
**VIRTUAL_DISK_ACCESS_GET_INFO** flag set in the
*VirtualDiskAccessMask* parameter to the
[OpenVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-openvirtualdisk) function. For information on how to
open a VHD, see the **OpenVirtualDisk** function.

### `ChangeTrackingId` [in]

A pointer to a string that specifies the change tracking identifier for the change that identifies the state of the virtual disk that you want to use as the basis of comparison to determine whether the specified area of the VHD has changed.

### `ByteOffset` [in]

An unsigned long integer that specifies the distance from the start of the VHD to the beginning of the area of the VHD that you want to check for changes, in bytes.

### `ByteLength` [in]

An unsigned long integer that specifies the length of the area of the VHD that you want to check for changes, in bytes.

### `Flags` [in]

Reserved. Set to **QUERY_CHANGES_VIRTUAL_DISK_FLAG_NONE**.

### `Ranges` [out]

An array of [QUERY_CHANGES_VIRTUAL_DISK_RANGE](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-query_changes_virtual_disk_range) structures that indicates the areas of the virtual disk within the area that the *ByteOffset* and *ByteLength* parameters specify that have changed since the change tracking identifier that the *ChangeTrackingId* parameter specifies was sealed.

### `RangeCount` [in, out]

An address of an unsigned long integer. On input, the value indicates the number of [QUERY_CHANGES_VIRTUAL_DISK_RANGE](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-query_changes_virtual_disk_range) structures that the array that the *Ranges* parameter points to can hold. On output, the value contains the number of **QUERY_CHANGES_VIRTUAL_DISK_RANGE** structures that the method placed in the array.

### `ProcessedLength` [out]

A pointer to an unsigned long integer that indicates the total number of bytes that the method processed, which indicates for how much of the area that the *BytesLength* parameter specifies that changes were captured in the available space of the array that the *Ranges* parameter specifies.

## Return value

The status of the request.

If the function succeeds, the return value is **ERROR_SUCCESS** and the
*Ranges* parameter contains the requested information.

If the function fails, the return value is an error code. For more information, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[QUERY_CHANGES_VIRTUAL_DISK_RANGE](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-query_changes_virtual_disk_range)

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))