# MmAllocateMappingAddress function

## Description

The **MmAllocateMappingAddress** routine reserves a range of system virtual address space of the specified size.

## Parameters

### `NumberOfBytes` [in]

Specifies the number of bytes to reserve.

### `PoolTag` [in]

Specifies a four-character tag used to identify the buffer. Use a distinct **PoolTag** tag for each allocation code path. For a description of pool tags, see [**ExAllocatePoolWithTag**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag).

## Return value

**MmAllocateMappingAddress** returns a pointer to the beginning of the reserved memory buffer if the operation is successful; otherwise, it returns NULL.

## Remarks

**MmAllocateMappingAddress** reserves a system virtual address range for the caller to use. No physical memory is allocated for the virtual address range and the virtual memory can't be accessed until it is mapped by the [**MmMapLockedPagesWithReservedMapping**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpageswithreservedmapping) routine. The caller unmaps the reserved memory range by calling the [**MmUnmapReservedMapping**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunmapreservedmapping) routine. Finally, the caller can free the reserved range by calling [**MmFreeMappingAddress**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmfreemappingaddress).

## See also

[**MmAllocateMappingAddressEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatemappingaddressex)

[**MmFreeMappingAddress**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmfreemappingaddress)

[**MmMapLockedPagesWithReservedMapping**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpageswithreservedmapping)

[**MmUnmapReservedMapping**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunmapreservedmapping)