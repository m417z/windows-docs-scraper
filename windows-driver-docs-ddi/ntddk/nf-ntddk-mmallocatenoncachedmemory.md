## Description

The **MmAllocateNonCachedMemory** routine allocates a virtual address range of non-cached and cache-aligned memory.

## Parameters

### `NumberOfBytes` [in]

Specifies the size in bytes of the range to be allocated.

## Return value

If the requested memory cannot be allocated, the return value is **NULL**. Otherwise, it is the base virtual address of the allocated range.

## Remarks

**MmAllocateNonCachedMemory** can be called from a [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine to allocate a non-cached block of virtual memory for various device-specific buffers. The function always returns a full multiple of the virtual memory page size, of nonpaged system-address-space memory, regardless of the requested allocation size.

Non-cached allocations are aligned on an integral multiple of the processor's data-cache-line size to prevent cache and coherency problems.

The physical memory pages that **MmAllocateNonCachedMemory** returns are typically not contiguous pages.

Memory that **MmAllocateNonCachedMemory** allocates is uninitialized. A kernel-mode driver must first zero this memory if it is going to make it visible to user-mode software (to avoid leaking potentially privileged contents).

## See also

[AllocateCommonBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_common_buffer)

[KeGetDcacheFillSize](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl)

[MmAllocateContiguousMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatecontiguousmemory)

[MmAllocateContiguousMemorySpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatecontiguousmemoryspecifycache)

[MmFreeNonCachedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmfreenoncachedmemory)