## Description

The **MmAllocatePagesForMdl** routine allocates zero-filled, non-paged, physical memory pages to an MDL.

## Parameters

### `LowAddress` [in]

Specifies the physical address of the start of the first address range from which the allocated pages can come. If **MmAllocatePagesForMdl** cannot allocate the requested number of bytes in the first address range, it iterates through additional address ranges to get more pages. At each iteration, **MmAllocatePagesForMdl** adds the value of *SkipBytes* to the previous start address to obtain the start of the next address range.

### `HighAddress` [in]

Specifies the physical address of the end of the first address range from which the allocated pages can come.

### `SkipBytes` [in]

Specifies the number of bytes to skip from the start of the previous address range from which the allocated pages can come. *SkipBytes* must be an integer multiple of the virtual memory page size, in bytes.

### `TotalBytes` [in]

Specifies the total number of bytes to allocate for the MDL.

## Return value

**MmAllocatePagesForMdl** returns one of the following:

| Return code | Description |
|---|---|
| **MDL pointer** | The MDL pointer describes a set of physical pages in the specified address range. If the requested number of bytes is not available, the MDL describes as much physical memory as is available. |
| **NULL** | There are no physical memory pages in the specified address ranges, or there is not enough memory pool for the MDL itself. |

## Remarks

Drivers that are running in Windows Server 2003 Service Pack 1 (SP1) and later versions of Windows should use the [MmAllocatePagesForMdlEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdlex) routine instead of **MmAllocatePagesForMdl**. **MmAllocatePagesForMdlEx** provides better performance than **MmAllocatePagesForMdl** by avoiding unnecessary flushes of the translation lookaside buffer (TLB) and cache memory.

The physical memory pages that are returned by **MmAllocatePagesForMdl** are typically not contiguous pages. **MmAllocatePagesForMdl** always fills the allocated pages in the returned MDL with zeros.

**MmAllocatePagesForMdl** is designed to be used by kernel-mode drivers that do not need corresponding virtual addresses (that is, they need physical pages and do not need the pages to be physically contiguous) or by kernel-mode drivers that can achieve substantial performance gains if physical memory for a device is allocated in a specific physical address range. A driver for an AGP graphics card is an example of such a driver.

Depending on how much physical memory is currently available in the requested ranges, **MmAllocatePagesForMdl** might return an MDL that describes less memory than was requested. The routine returns **NULL** if no memory was allocated. The caller should check the amount of memory that is actually allocated to the MDL.

The caller must use [MmFreePagesFromMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmfreepagesfrommdl) to release the memory pages that are described by an MDL that was created by **MmAllocatePagesForMdl**. After calling **MmFreePagesFromMdl**, the caller must also call [ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool) to release the memory that is allocated for the MDL structure itself.

In Windows 2000 and later versions of Windows, the maximum amount of memory that **MmAllocatePagesForMdl** can allocate in a single call is (4 gigabytes - PAGE_SIZE). The routine can satisfy an allocation request for this amount only if enough pages are available.

**MmAllocatePagesForMdl** runs at IRQL <= APC_LEVEL. Windows Server 2008 and later versions of the Windows operating system enable **MmAllocatePagesForMdl** callers to call at DISPATCH_LEVEL. However, you can improve driver performance by calling at APC_LEVEL or below.

Calling **MmAllocatePagesForMdl** from a special kernel asynchronous procedure call (APC) can lead to a recursive acquisition of an exclusive lock, which is only in a critical region (user or normal kernel APCs disabled) but not in a guarded region (all APCs disabled).

## See also

[ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool)

[MmAllocatePagesForMdlEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdlex)

[MmFreePagesFromMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmfreepagesfrommdl)

[MmMapLockedPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpages)