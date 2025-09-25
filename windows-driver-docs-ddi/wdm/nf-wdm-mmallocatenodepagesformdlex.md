## Description

The **MmAllocateNodePagesForMdlEx** routine allocates nonpaged physical memory from an ideal node, and allocates an [**MDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) structure to describe this memory.

## Parameters

### `LowAddress` [in]

The physical address of the start of the first address range from which the allocated pages can come. If **MmAllocateNodePagesForMdlEx** cannot allocate the requested number of bytes in the first address range, the routine iterates through additional address ranges to get more pages. At each iteration, **MmAllocateNodePagesForMdlEx** adds the value of *SkipBytes* to the previous start address to calculate the start of the next address range.

### `HighAddress` [in]

The physical address of the end of the first address range that the allocated pages can come from.

### `SkipBytes` [in]

The number of bytes to skip from the start of the previous address range that the allocated pages can come from. *SkipBytes* must be an integer multiple of the virtual memory page size, in bytes.

### `TotalBytes` [in]

The total number of bytes to allocate for the MDL.

### `CacheType` [in]

A [MEMORY_CACHING_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_memory_caching_type) value, which indicates the type of caching that is allowed for the requested memory.

### `IdealNode` [in]

The ideal node number. If a multiprocessor system contains N nodes, valid node numbers are in the range 0 to N-1. Your driver can call the [KeQueryHighestNodeNumber](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryhighestnodenumber) routine to get the highest node number. A single-processor or non-NUMA multiprocessor system has only one node, node 0, from which to allocate memory. For a NUMA multiprocessor system, the allocation is made from the ideal node, if possible. If insufficient memory is available in the ideal node to satisfy the allocation request, and the caller does not set the MM_ALLOCATE_FROM_LOCAL_NODE_ONLY flag, **MmAllocateNodePagesForMdlEx** will try to allocate memory from other nodes.

### `Flags` [in]

Flags for this operation. Set this parameter to zero or to the bitwise-OR of one or more of the following flag bits:

- MM_DONT_ZERO_ALLOCATION

- MM_ALLOCATE_FROM_LOCAL_NODE_ONLY

- MM_ALLOCATE_FULLY_REQUIRED

- MM_ALLOCATE_NO_WAIT

- MM_ALLOCATE_PREFER_CONTIGUOUS

- MM_ALLOCATE_REQUIRE_CONTIGUOUS_CHUNKS

- MM_ALLOCATE_AND_HOT_REMOVE

For more information about these flags, see [MM_ALLOCATE_XXX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdlex).

## Return value

**MmAllocateNodePagesForMdlEx** returns a pointer to an MDL structure if it is successful. Otherwise, if the routine fails to allocate any memory, the routine returns **NULL**.

A return value of **NULL** indicates that no physical memory pages are available in the specified address ranges, or that there is not enough memory pool available to allocate the MDL structure.

If the routine successfully allocates some, but not all, of the requested memory, the MDL describes as much physical memory as the routine was able to allocate.

## Remarks

In a non-uniform memory access (NUMA) multiprocessor system, the caller can specify an ideal node from which to allocate the memory. A node is a collection of processors that share fast access to a region of memory. In a non-NUMA multiprocessor or a single-processor system, **MmAllocateNodePagesForMdlEx** treats all memory as belonging to a single node and allocates memory from this node.

By default, the physical memory pages that **MmAllocateNodePagesForMdlEx** returns are not contiguous pages. Callers can override the default behavior of this routine by setting the MM_ALLOCATE_PREFER_CONTIGUOUS or MM_ALLOCATE_REQUIRE_CONTIGUOUS_CHUNKS flag bit in the *Flags* parameter.

**MmAllocateNodePagesForMdlEx** does not map the allocated physical memory into virtual memory. If necessary, the caller can call a routine such as [MmMapLockedPagesSpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpagesspecifycache) to map the physical memory pages described by the MDL.

**MmAllocateNodePagesForMdlEx** is designed for kernel-mode drivers that do not need corresponding virtual addresses (that is, they need physical pages and do not need them to be physically contiguous), and for kernel-mode drivers that can achieve substantial performance gains if physical memory for a device is allocated in a specific physical address range (for example, an AGP graphics card).

Depending on how much physical memory is currently available in the requested ranges, **MmAllocateNodePagesForMdlEx** might return an MDL that describes less memory than was requested. The routine also might return **NULL** if no memory was allocated. The caller should check the amount of memory that is actually allocated, as described by the MDL.

The caller must use [MmFreePagesFromMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmfreepagesfrommdl) to release the memory pages that are described by an MDL that was created by **MmAllocateNodePagesForMdlEx**. After calling **MmFreePagesFromMdl**, the caller must also call [ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool) to release the memory allocated for the MDL structure.

By default, **MmAllocateNodePagesForMdlEx** fills the pages that it allocates with zeros. The caller can specify the MM_DONT_ZERO_ALLOCATION flag to override this default and to possibly improve performance.

Memory that **MmAllocateNodePagesForMdlEx** allocates is uninitialized if you specify the MM_DONT_ZERO_ALLOCATION flag. A kernel-mode driver must first zero this memory if the driver is going to make the memory visible to user-mode software (to avoid leaking potentially privileged contents). For more information about this flag, see [MM_ALLOCATE_XXX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdlex).

The maximum amount of memory that **MmAllocateNodePagesForMdlEx** can allocate in a single call is (4 gigabytes - PAGE_SIZE). The routine can satisfy an allocation request for this amount only if enough pages are available.

**MmAllocateNodePagesForMdlEx** runs at IRQL <= APC_LEVEL. If necessary, your driver can call **MmAllocateNodePagesForMdlEx** at DISPATCH_LEVEL. However, you can improve driver performance by calling at APC_LEVEL or below.

## See also

[ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool)

[KeQueryHighestNodeNumber](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryhighestnodenumber)

[**MDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)

[MEMORY_CACHING_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_memory_caching_type)

[MM_ALLOCATE_XXX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdlex)

[MmFreePagesFromMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmfreepagesfrommdl)

[MmMapLockedPagesSpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpagesspecifycache)