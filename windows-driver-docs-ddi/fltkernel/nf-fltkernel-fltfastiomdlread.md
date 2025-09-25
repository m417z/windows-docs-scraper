# FltFastIoMdlRead function

## Description

The **FltFastIoMdlRead** routine returns a memory descriptor list (MDL) that points directly to the specified byte range in the file cache.

## Parameters

### `InitiatingInstance`

Opaque instance pointer for the caller. This parameter is required and cannot be **NULL**.

### `FileObject` [in]

A pointer to a file object for the cached file.

### `FileOffset` [in]

A pointer to a variable that specifies the starting byte offset within the cached file that holds the data.

### `Length` [in]

The length in bytes of the data to read from the cache.

### `LockKey` [in]

A value that is associated with the byte range to lock. If the range to lock overlaps another range that is already locked with a nonexclusive lock, or if the range to read is a subrange of another range that is already locked non-exclusively, the value in this parameter must be the key for that nonexclusive lock The lock must be held by the parent process of the calling thread. Otherwise, this parameter has no effect.

### `MdlChain` [out]

On output, a pointer to a linked list of memory descriptor lists (MDLs).

### `IoStatus` [out]

A pointer to an [IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure that, on output, contains the status of the transfer. If the operation succeeds, *IoStatus.Status* is set to STATUS_SUCCESS. Otherwise, it is set to an appropriate NTSTATUS error code. *IoStatus.Information* is set to the actual number of bytes that the routine successfully locked.

## Return value

The **FltFastIoMdlRead** routine returns **TRUE** if the operation succeeds and **FALSE** if the operation fails.

## Remarks

The **FltFastIoMdlRead** routine bypasses the usual IRP mechanism and returns a linked list of memory descriptor lists (MDL) that the caller can use to directly access the cached file data. This operation does not copy or buffer data and therefore is much faster than a normal read.

The routine is similar to [CcMdlRead](https://learn.microsoft.com/previous-versions/ff539159(v=vs.85)) and [FsRtlMdlReadDev](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlmdlreaddev). **FltFastIoMdlRead**, **CcMdlRead**, and **FsRtlMdlReadDev** lock the pages that contain the cached file data to prevent the system from swapping these pages to the page file. The pages remain locked in memory until the caller invokes the [FltFastIoMdlReadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfastiomdlreadcomplete) routine.

## See also

[CcMdlRead](https://learn.microsoft.com/previous-versions/ff539159(v=vs.85))

[FltFastIoMdlReadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfastiomdlreadcomplete)

[FsRtlMdlReadDev](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlmdlreaddev)