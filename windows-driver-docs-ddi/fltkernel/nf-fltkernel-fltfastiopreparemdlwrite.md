# FltFastIoPrepareMdlWrite function

## Description

The **FltFastIoPrepareMdlWrite** routine returns a linked list of memory descriptor lists (MDLs) that point to the specified range of cached file data to write data directly to the cache.

## Parameters

### `InitiatingInstance`

Opaque instance pointer for the caller. This parameter is required and cannot be **NULL**.

### `FileObject` [in]

A pointer to the file object.

### `FileOffset` [in]

A pointer to a value that specifies the starting byte offset within the cache that holds the data.

### `Length` [in]

The length in bytes of the data to read from the cache.

### `LockKey` [in]

A value that is associated with the byte range to lock. If the range to lock overlaps another range that is already locked with a nonexclusive lock, or if the range to read is a subrange of another range that is already locked non-exclusively, the value in this parameter must be the key for that nonexclusive lock. The lock must be held by the parent process of the calling thread. Otherwise, this parameter has no effect.

### `MdlChain` [out]

On output, a pointer to a linked list of memory descriptor lists (MDLs) that point to the byte range within the cached data.

### `IoStatus` [out]

A pointer to an [IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure that, on output, contains the status of the transfer. If the operation succeeds, *IoStatus.Status* is set to STATUS_SUCCESS. Otherwise, it is set to an appropriate NTSTATUS error code. *IoStatus.Information* is set to the actual number of bytes that the routine successfully locked.

## Return value

The **FltFastIoPrepareMdlWrite** routine returns **TRUE** if the operation succeeds and **FALSE** if the operation fails.

## Remarks

**FltFastIoPrepareMdlWrite** is similar to [FsRtlCopyWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlcopywrite), except that **FltFastIoPrepareMdlWrite** does not copy data to the cache. Instead, the physical pages that the caller will overwrite are locked in memory, and **FltFastIoPrepareMdlWrite** returns one or more memory descriptor lists (MDLs) that point to the specified byte range. The locked pages remain locked until the caller calls [FltFastIoMdlWriteComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfastiomdlwritecomplete).

The pages that the MDLs point to are locked in memory, but are not mapped in system space. The caller can perform this mapping by calling [MmGetSystemAddressForMdlSafe](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer#mmgetsystemaddressformdlsafe).

Even if the call to **FltFastIoPrepareMdlWrite** fails, one or more MDLs might have been allocated. The caller can examine the value of *IoStatus.Information* to determine if this has occurred. If it has, the caller must call [FltFastIoMdlWriteComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfastiomdlwritecomplete) to free the allocated MDLs.

## See also

[FltFastIoMdlWriteComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfastiomdlwritecomplete)

[FsRtlCopyWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlcopywrite)

[MmGetSystemAddressForMdlSafe](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer#mmgetsystemaddressformdlsafe)