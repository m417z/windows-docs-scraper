## Description

The **MmAllocateContiguousMemory** routine allocates a range of contiguous, nonpaged physical memory and maps it to the system address space.

## Parameters

### `NumberOfBytes` [in]

The size, in bytes, of the block of contiguous memory to allocate. For more information, see Remarks.

### `HighestAcceptableAddress` [in]

The highest valid physical address the caller can use. For example, if a device can address only locations in the first 16 megabytes of the processor's physical memory address range, the driver for this device should set *HighestAcceptableAddress* to 0x0000000000FFFFFF. If you do not have specific requirements for memory allocation, set to MAXULONG64.

## Return value

**MmAllocateContiguousMemory** returns the base virtual address for the allocated memory. If the request cannot be satisfied, the routine returns **NULL**.

## Remarks

**MmAllocateContiguousMemory** allocates a block of nonpaged memory that is contiguous in physical address space. The routine maps this block to a contiguous block of virtual memory in the system address space and returns the virtual address of the base of this block. The routine aligns the starting address of a contiguous memory allocation to a memory page boundary.

Drivers must not access memory beyond the requested allocation size. For example, developers should not assume that their drivers can safely use memory between the end of their requested allocation and the next page boundary.

Because contiguous physical memory is usually in short supply, it should be used sparingly and only when necessary. A driver that must use contiguous memory should allocate this memory during driver initialization because physical memory is likely to become fragmented over time as the operating system allocates and frees memory. Typically, a driver calls **MmAllocateContiguousMemory** from its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine to allocate an internal buffer for long-term use, and frees the buffer just before the driver is unloaded.

Memory allocated by **MmAllocateContiguousMemory** must be freed when the memory is no longer needed. Call the [MmFreeContiguousMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmfreecontiguousmemory) routine to free memory that is allocated by **MmAllocateContiguousMemory**.

When physical memory is fragmented on a computer that has a large amount of RAM, calls to **MmAllocateContiguousMemory**, which require the operating system to search for contiguous blocks of memory, can severely degrade performance. This degradation is greatly reduced starting with Windows Vista SP1 and Windows Server 2008, but contiguous memory can still be expensive to allocate. For this reason, drivers should avoid repeated calls to **MmAllocateContiguousMemory**. Instead, drivers should allocate all required contiguous buffers in their **DriverEntry** routines and reuse these buffers.

Memory that **MmAllocateContiguousMemory** allocates is uninitialized. A kernel-mode driver must first set this memory to zero if it is going to make it visible to user-mode software (to avoid leaking potentially privileged contents).

## See also

[AllocateCommonBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_common_buffer)

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[MmAllocateContiguousMemorySpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatecontiguousmemoryspecifycache)

[MmAllocateNonCachedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmallocatenoncachedmemory)

[MmFreeContiguousMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmfreecontiguousmemory)