# MmMapIoSpaceEx function

## Description

The **MmMapIoSpaceEx** routine maps the given physical address range to non-paged system space using the specified page protection.

## Parameters

### `PhysicalAddress` [in]

Specifies the starting physical address of the I/O range to be mapped.

### `NumberOfBytes` [in]

Specifies a value greater than zero, indicating the number of bytes to be mapped.

### `Protect` [in]

Flag bits that specify the protection to use for the mapped range. The caller must set one of the following flag bits in the *Protect* parameter.

| Flag bit | Meaning |
| --- | --- |
| PAGE_READONLY | The mapped range can only be read, not written. |
| PAGE_READWRITE | The mapped range can be read or written. |
| PAGE_EXECUTE | The mapped range can be executed, but not read or written. |
| PAGE_EXECUTE_READ | The mapped range can be executed or read, but not written. |
| PAGE_EXECUTE_READWRITE | The mapped range can be executed, read, or written. |

In addition, the caller can set one (but not both) of the following optional flag bits in the *Protect* parameter.

| Flag bit | Meaning |
| --- | --- |
| PAGE_NOCACHE | Specifies non-cached memory. |
| PAGE_WRITECOMBINE | Specifies write-combined memory (the memory should not be cached by the processor, but writes to the memory can be combined by the processor). |

## Return value

**MmMapIoSpaceEx** returns the base virtual address that maps the base physical address for the range. If space for mapping the range is insufficient, it returns **NULL**.

## Remarks

A driver must call this routine during device start-up if it receives translated resources of type **CmResourceTypeMemory** in a [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structure. **MmMapIoSpaceEx** maps the physical address returned in the resource list to a virtual address through which the driver can access device registers.

For example, drivers of PIO devices that allocate long-term I/O buffers can call this routine to make such buffers accessible or to make device memory accessible.

For more information about using this routine, see [Mapping Bus-Relative Addresses to Virtual Addresses](https://learn.microsoft.com/windows-hardware/drivers/kernel/mapping-bus-relative-addresses-to-virtual-addresses).

## See also

[MmAllocateContiguousMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatecontiguousmemory)

[MmAllocateNonCachedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmallocatenoncachedmemory)

[MmMapLockedPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpages)

[MmUnmapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunmapiospace)