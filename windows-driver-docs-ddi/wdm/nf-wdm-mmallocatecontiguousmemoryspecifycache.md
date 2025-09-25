## Description

The **MmAllocateContiguousMemorySpecifyCache** routine allocates a range of contiguous, nonpaged physical memory and maps it to the system address space.

## Parameters

### `NumberOfBytes` [in]

The size, in bytes, of the block of contiguous memory to allocate. For more information, see Remarks.

### `LowestAcceptableAddress` [in]

The lowest valid physical address the caller can use. For example, if a device can address only locations above the first 8 megabytes of the processor's physical memory address range, the driver for this device should set *LowestAcceptableAddress* to 0x0000000000800000.

### `HighestAcceptableAddress` [in]

The highest valid physical address the caller can use. For example, if a device can address only locations in the first 16 megabytes of the processor's physical memory address range, the driver for this device should set *HighestAcceptableAddress* to 0x0000000000FFFFFF.

### `BoundaryAddressMultiple` [in, optional]

The physical address multiple that the allocated buffer must not cross. A physical address multiple must always be a power of two. This parameter is optional and can be specified as zero to indicate that the device has no special memory boundary restrictions. For more information, see Remarks.

### `CacheType` [in]

Specifies a [MEMORY_CACHING_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_memory_caching_type) value, which indicates the type of caching allowed for the requested memory.

## Return value

**MmAllocateContiguousMemorySpecifyCache** returns the base virtual address for the allocated memory. If the system is unable to allocate the requested buffer, the routine returns **NULL**.

## Remarks

**MmAllocateContiguousMemorySpecifyCache** allocates a block of nonpaged memory that is contiguous in physical address space. The routine maps this block to a contiguous block of virtual memory in the system address space and returns the virtual address of the base of this block. The routine aligns the starting address of a contiguous memory allocation to a memory page boundary.

Drivers must not access memory beyond the requested allocation size. For example, developers should not assume that their drivers can safely use memory between the end of their requested allocation and the next page boundary.

Because contiguous physical memory is usually in short supply, it should be used sparingly and only when necessary. A driver that must use contiguous memory should allocate this memory during driver initialization because physical memory is likely to become fragmented over time as the operating system allocates and frees memory. Typically, a driver calls **MmAllocateContiguousMemorySpecifyCache** from its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine to allocate an internal buffer for long-term use, and frees the buffer just before the driver is unloaded.

Memory allocated by **MmAllocateContiguousMemorySpecifyCache** must be freed when the memory is no longer needed. Call the [MmFreeContiguousMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmfreecontiguousmemory) routine to free memory that is allocated by **MmAllocateContiguousMemorySpecifyCache**.

If you specify a nonzero value for the *BoundaryAddressMultiple* parameter, the physical address range of the allocated memory block will not cross an address boundary that is an integer multiple of this value. A driver should set this parameter to zero unless a nonzero value is required to work around a hardware limitation. For example, if a device cannot transfer data across 16-megabyte physical boundaries, the driver should specify a value of 0x1000000 for this parameter to ensure that the addresses that the device sees do not wrap around at a 16-megabyte boundary.

If you use the **MmAllocateContiguousMemorySpecifyCache** routine on computers with large amounts of memory, the operating system's performance might severely degrade when the system tries to create a contiguous chunk of memory. This degradation is greatly reduced starting with Windows Vista SP1 and Windows Server 2008, but contiguous memory can still be expensive to allocate. For this reason, drivers should avoid repeated calls to **MmAllocateContiguousMemorySpecifyCache**. Instead, drivers should allocate all required contiguous buffers in their **DriverEntry** routines and reuse these buffers.

Memory that **MmAllocateContiguousMemorySpecifyCache** allocates is uninitialized. A kernel-mode driver must first zero this memory if it is going to make it visible to user-mode software (to avoid leaking potentially privileged contents).

## See also

[MmAllocateContiguousMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatecontiguousmemory)

[MmFreeContiguousMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmfreecontiguousmemory)