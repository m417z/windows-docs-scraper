# FltFreePoolAlignedWithTag function

## Description

The **FltFreePoolAlignedWithTag** routine frees a cache-aligned buffer that was allocated by a previous call to [FltAllocatePoolAlignedWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatepoolalignedwithtag).

## Parameters

### `Instance` [in]

Opaque instance pointer for a caller-owned minifilter driver instance that is attached to the volume. Must be the same instance pointer as the one used in the call to [FltAllocatePoolAlignedWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatepoolalignedwithtag).

### `Buffer` [in]

Address of the block of pool memory to be freed.

### `Tag` [in]

Tag used to mark the pool block. Must be the same tag as the one used in the call to [FltAllocatePoolAlignedWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatepoolalignedwithtag).

## Return value

None

## Remarks

The memory that the *Buffer* parameter points to must not be accessed after it is freed by **FltFreePoolAlignedWithTag**.

The caller of **FltFreePoolAlignedWithTag** can be running at IRQL DISPATCH_LEVEL if a **NonPaged***XxxPoolType* value was specified when the memory was allocated. Otherwise, the caller must be running at IRQL <= APC_LEVEL.

## See also

[FltAllocatePoolAlignedWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatepoolalignedwithtag)