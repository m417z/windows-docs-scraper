## Description

The **MmAllocateContiguousNodeMemory** routine allocates a range of contiguous, nonpaged physical memory and maps it to the system address space.

## Parameters

### `NumberOfBytes` [in]

The size, in bytes, of the block of contiguous memory to allocate. For more information, see Remarks.

### `LowestAcceptableAddress` [in]

The lowest valid physical address the caller can use. For example, if a device can address only locations above the first 8 megabytes of the processor's physical memory address range, the driver for this device should set *LowestAcceptableAddress* to 0x0000000000800000.

### `HighestAcceptableAddress` [in]

The highest valid physical address the caller can use. For example, if a device can address only locations in the first 16 megabytes of the processor's physical memory address range, the driver for this device should set *HighestAcceptableAddress* to 0x0000000000FFFFFF.

### `BoundaryAddressMultiple` [in, optional]

The physical address multiple that the allocated buffer must not cross. A physical address multiple must always be a power of two. This parameter is optional and can be specified as zero to indicate that the device has no special memory boundary restrictions. For more information, see Remarks.

### `Protect` [in]

Flag bits that specify the protection to use for the allocated memory. The caller must set one (but not both) of the following flag bits in the *Protect* parameter.

| Flag bit | Meaning |
|---|---|
| PAGE_READWRITE | Allocate read/write, no-execute (NX) memory. Most callers should set this flag bit. For more information, see Remarks. |
| PAGE_EXECUTE_READWRITE | Allocate read/write memory that is executable. This flag bit should be set only if the caller requires the ability to execute instructions in the allocated memory. |

In addition, the caller can set one (but not both) of the following optional flag bits in the *Protect* parameter.

| Flag bit | Meaning |
|---|---|
| PAGE_NOCACHE | Allocate non-cached memory. This flag bit is similar in effect to calling [MmAllocateContiguousMemorySpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatecontiguousmemoryspecifycache) with *CacheType* set to **MmNonCached**. |
| PAGE_WRITECOMBINE | Allocate write-combined memory. This flag bit is similar in effect to calling **MmAllocateContiguousMemorySpecifyCache** with *CacheType* set to **MmWriteCombined**. |

If neither PAGE_NOCACHE nor PAGE_WRITECOMBINE is specified, the allocated memory is fully cached. In this case, the effect is similar to calling **MmAllocateContiguousMemorySpecifyCache** with *CacheType* set to **MmCached**.

### `PreferredNode` [in]

The preferred node number. If a multiprocessor system contains N nodes, the nodes are numbered from 0 to N-1. If the caller sets *PreferredNode* to MM_ANY_NODE_OK, the routine chooses which node to allocate memory from. Otherwise, if memory in the specified address range cannot be allocated from the preferred node, the routine returns **NULL**.

## Return value

**MmAllocateContiguousNodeMemory** returns the base virtual address for the allocated memory. If the request cannot be satisfied, the routine returns **NULL**.

## Remarks

A kernel-mode device driver calls this routine to allocate a contiguous block of physical memory. The calling driver can specify whether to use no-execute (NX) memory for the allocation. In a non-uniform memory access (NUMA) multiprocessor system, the caller can specify a preferred node from which to allocate the memory. A node is a collection of processors that share fast access to a region of memory. In a non-NUMA multiprocessor or a single-processor system, **MmAllocateContiguousNodeMemory** treats all memory as belonging to a single node and allocates memory from this node.

**MmAllocateContiguousNodeMemory** allocates a block of nonpaged memory that is contiguous in physical address space. The routine maps this block to a contiguous block of virtual memory in the system address space and returns the virtual address of the base of this block. The routine aligns the starting address of a contiguous memory allocation to a memory page boundary.

Drivers must not access memory beyond the requested allocation size. For example, developers should not assume that their drivers can safely use memory between the end of their requested allocation and the next page boundary.

Because contiguous physical memory is usually in short supply, it should be used sparingly and only when necessary. A driver that must use contiguous memory should allocate this memory during driver initialization because physical memory is likely to become fragmented over time as the operating system allocates and frees memory. Typically, a driver calls **MmAllocateContiguousNodeMemory** from its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine to allocate an internal buffer for long-term use, and frees the buffer just before the driver is unloaded.

Memory allocated by **MmAllocateContiguousNodeMemory** must be freed when the memory is no longer needed. Call the [MmFreeContiguousMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmfreecontiguousmemory) routine to free memory that is allocated by **MmAllocateContiguousNodeMemory**.

**MmAllocateContiguousNodeMemory** is similar to the [MmAllocateContiguousMemorySpecifyCacheNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatecontiguousmemoryspecifycachenode) routine. Unlike **MmAllocateContiguousMemorySpecifyCacheNode**, **MmAllocateContiguousNodeMemory** can be used to allocate no-execute (NX) memory. As a best practice, a driver should allocate NX memory unless the driver explicitly requires the ability to execute instructions in the allocated memory. By allocating NX memory, a driver improves security by preventing malicious software from executing instructions in this memory. Memory allocated by the [MmAllocateContiguousMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatecontiguousmemory), [MmAllocateContiguousMemorySpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatecontiguousmemoryspecifycache), and **MmAllocateContiguousMemorySpecifyCacheNode** routines is always executable.

If you specify a nonzero value for the *BoundaryAddressMultiple* parameter, the physical address range of the allocated memory block will not cross an address boundary that is an integer multiple of this value. A driver should set this parameter to zero unless a nonzero value is required to work around a hardware limitation. For example, if a device cannot transfer data across 16-megabyte physical boundaries, the driver should specify a value of 0x1000000 for this parameter to ensure that the addresses that the device sees do not wrap around at a 16-megabyte boundary.

Memory that **MmAllocateContiguousNodeMemory** allocates is uninitialized. A kernel-mode driver must first zero this memory if it is going to make it visible to user-mode software (to avoid leaking potentially privileged contents).

## See also

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[MmAllocateContiguousMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatecontiguousmemory)

[MmAllocateContiguousMemorySpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatecontiguousmemoryspecifycache)

[MmAllocateContiguousMemorySpecifyCacheNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatecontiguousmemoryspecifycachenode)

[MmFreeContiguousMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmfreecontiguousmemory)