# MmFreeContiguousMemory function (wdm.h)

## Description

The **MmFreeContiguousMemory** routine releases a range of physically contiguous memory that was allocated by an **MmAllocateContiguousMemory*Xxx*** routine.

## Parameters

### `BaseAddress` [in]

Pointer to the virtual address of the memory to be freed.

## Remarks

The **MmFreeContiguousMemory** routine frees a block of physically contiguous memory that was allocated by a previous call to the [MmAllocateContiguousMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatecontiguousmemory), [MmAllocateContiguousMemorySpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatecontiguousmemoryspecifycache), or [MmAllocateContiguousMemorySpecifyCacheNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatecontiguousmemoryspecifycachenode) routine. The *BaseAddress* parameter must be the base address that was obtained from the previous call to the **MmAllocateContiguousMemory*Xxx*** routine.

A device driver that must use contiguous memory should allocate only what it needs during driver initialization because physical memory is likely to become fragmented as the system runs. Such a driver must deallocate the memory when the driver is done using the memory.

Callers of **MmFreeContiguousMemory** must be running at IRQL = APC_LEVEL. For Windows Server 2008 and later versions of the Windows operating system, you can also call **MmFreeContiguousMemory** with IRQL <= DISPATCH_LEVEL. However, you can improve driver performance by calling at APC_LEVEL or below.

## See also

[MmAllocateContiguousMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatecontiguousmemory)

[MmAllocateContiguousMemorySpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatecontiguousmemoryspecifycache)

[MmAllocateContiguousMemorySpecifyCacheNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatecontiguousmemoryspecifycachenode)