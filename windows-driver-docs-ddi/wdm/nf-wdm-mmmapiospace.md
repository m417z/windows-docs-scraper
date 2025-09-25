## Description

The **MmMapIoSpace** routine maps the given physical address range to nonpaged system space.

## Parameters

### `PhysicalAddress` [in]

Specifies the starting physical address of the I/O range to be mapped.

### `NumberOfBytes` [in]

Specifies a value greater than zero, indicating the number of bytes to be mapped.

### `CacheType` [in]

Specifies a [MEMORY_CACHING_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_memory_caching_type) value, which indicates the cache attribute to use to map the physical address range.

## Return value

**MmMapIoSpace** returns the base virtual address that maps the base physical address for the range. If space for mapping the range is insufficient, it returns **NULL**.

## Remarks

A driver must call this routine during device start-up if it receives translated resources of type **CmResourceTypeMemory** in a [**CM_PARTIAL_RESOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structure. **MmMapIoSpace** maps the physical address returned in the resource list to a logical address through which the driver can access device registers.

**MmMapIoSpace** should only be used with pages that are locked down (belong to the locked pages of an MDL or I/O space), otherwise the owner of the memory could free it (or the memory could be paged in/out, etc.).

For example, drivers of PIO devices that allocate long-term I/O buffers can call this routine to make such buffers accessible or to make device memory accessible.

For more information about using this routine, see [Mapping Bus-Relative Addresses to Virtual Addresses](https://learn.microsoft.com/windows-hardware/drivers/kernel/mapping-bus-relative-addresses-to-virtual-addresses).

## See also

[MmAllocateContiguousMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatecontiguousmemory)

[MmAllocateNonCachedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmallocatenoncachedmemory)

[MmMapLockedPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpages)

[MmUnmapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunmapiospace)