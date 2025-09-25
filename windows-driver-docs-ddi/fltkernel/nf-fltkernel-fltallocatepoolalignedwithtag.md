# FltAllocatePoolAlignedWithTag function

## Description

**FltAllocatePoolAlignedWithTag** allocates a device-aligned buffer for use in a noncached I/O operation.

## Parameters

### `Instance` [in]

Opaque instance pointer for a caller-owned minifilter driver instance that is attached to the volume. This parameter is required and cannot be **NULL**.

### `PoolType` [in]

Type of pool to allocate. One of the following:

**NonPagedPool**

**PagedPool**

**NonPagedPoolCacheAligned**

**PagedPoolCacheAligned**

See [POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type) for a description of the available pool memory types.

### `NumberOfBytes` [in]

Number of bytes to allocate. This parameter is required and can be zero.

### `Tag` [in]

Specifies the pool tag for the allocated memory. Drivers normally specify the pool tag as a string of one to four 7-bit ASCII characters, delimited by single quotation marks (for example, 'abcd'). This parameter is required and cannot be zero.

## Return value

If not enough free pool is available to satisfy the request, **FltAllocatePoolAlignedWithTag** returns a **NULL** pointer. Otherwise, **FltAllocatePoolAlignedWithTag** returns a pointer to the newly allocated buffer.

## Remarks

**FltAllocatePoolAlignedWithTag** allocates a buffer that is aligned in accordance with the underlying device for the given volume. Such device-aligned buffers are required for noncached I/O. (They can also be used for cached I/O.) Thus when calling routines that perform noncached I/O, such as [FltReadFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreadfile) and [FltWriteFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltwritefile), minifilter drivers should call **FltAllocatePoolAlignedWithTag** instead of [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag).

If the caller specifies a value of zero for the *NumberOfBytes* parameter, **FltAllocatePoolAlignedWithTag** allocates the smallest amount of memory that meets the alignment requirement.

The system associates the pool tag specified by the *Tag* parameter with the allocated buffer. Programming tools, such as the Windows Debugger (WinDbg), can display the pool tag associated with each allocated buffer. The value of the pool tag is normally displayed in reversed order. For example, if a caller passes 'Fred' as the value of the *Tag* parameter, this value would appear as 'derF' if pool is dumped or when tracking pool usage in the debugger.

For more information about memory management, see [Memory Management](https://learn.microsoft.com/windows-hardware/drivers/kernel/managing-memory-for-drivers).

When the buffer that **FltAllocatePoolAlignedWithTag** allocates is no longer needed, the caller is responsible for freeing it by calling [FltFreePoolAlignedWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreepoolalignedwithtag).

Callers of **FltAllocatePoolAlignedWithTag** can be running at IRQL DISPATCH_LEVEL only if a NonPaged*XxxPoolType* is specified. Otherwise, callers must be running at IRQL <= APC_LEVEL.

## See also

[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag)

[FltFreePoolAlignedWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreepoolalignedwithtag)

[FltReadFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreadfile)

[FltWriteFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltwritefile)