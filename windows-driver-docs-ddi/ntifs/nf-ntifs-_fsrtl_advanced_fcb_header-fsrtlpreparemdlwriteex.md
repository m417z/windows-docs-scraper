# FsRtlPrepareMdlWriteEx function

## Description

The **FsRtlPrepareMdlWriteEx** routine returns a linked list of memory descriptor lists (MDLs) that point to the specified range of cached file data to write data directly to the cache. If the cache support for the write is not available, the routine reverts to an IRP based MDL write operation.

## Parameters

### `FileObject` [in]

A pointer to the file object.

### `FileOffset` [in]

A pointer to a value that specifies the starting byte offset within the cache that holds the data.

### `Length` [in]

The length in bytes of the data to write to the cache.

### `LockKey` [in]

A value that is associated with the byte range to lock. If the range to lock overlaps another range that is already locked with a nonexclusive lock, or if the range to read is a subrange of another range that is already locked nonexclusively, the value in this parameter must be the key for that nonexclusive lock. The lock must be held by the parent process of the calling thread. Otherwise, this parameter has no effect.

### `MdlChain` [out]

On output, a pointer to a linked list of memory descriptor lists (MDLs) that point to the byte range within the cached data.

### `IoStatus` [out]

A pointer to an [IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure that, on output, contains the status of the transfer. If the operation succeeds, *IoStatus.Status* is set to **STATUS_SUCCESS**. Otherwise, it is set to an appropriate **NTSTATUS** error code. *IoStatus.Information* is set to the actual number of bytes that the routine successfully locked.

## Return value

**FsRtlPrepareMdlWriteEx** returns **STATUS_SUCCESS** or an appropriate **NTSTATUS** value, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | An IRP for the IRP based write could not be allocated. |

## Remarks

If fast I/O is available for the file system, the **FsRtlPrepareMdlWriteEx** routine will bypass the usual IRP write mechanism and return a linked list of memory descriptor lists (MDL) that the caller can use to write data directly to the file cache. Instead of copying data buffered data into the cache, the physical pages that the caller will overwrite are locked in memory and can be written to directly. **FsRtlPrepareMdlWriteEx** returns one or more memory descriptor lists (MDLs) that point to the specified byte range.

 If fast I/O is not enabled, **FsRtlPrepareMdlWriteEx** will generate a synchronous IRP based MDL write prepare and return the MDLs allocated from the request.

The pages that the MDLs point to are locked in memory, but are not mapped in system space. The caller can perform this mapping by calling [MmGetSystemAddressForMdlSafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetsystemaddressformdlsafe).

Each call to **FsRtlPrepareMdlWriteEx** must be followed by a call to [CcMdlWriteComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccmdlwritecomplete).

## See also

[CcMdlWriteComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccmdlwritecomplete)

[CcPrepareMdlWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpreparemdlwrite)

[MmGetSystemAddressForMdlSafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetsystemaddressformdlsafe)