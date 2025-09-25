# StorPortAllocateDmaMemory function

## Description

This function is the extended version of the [StorPortAllocateContiguousMemorySpecifyCacheNode function](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportallocatecontiguousmemoryspecifycachenode). It allocates a range of physically contiguous noncached, nonpaged memory, and returns the physical address of the allocated buffer.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `NumberOfBytes` [in]

The number of bytes to allocate.

### `LowestAcceptableAddress` [in]

The lowest physical address that is valid for the allocation. For example, if the device can only reference physical memory in the 8 MB to 16 MB range, this value would be set to 0x800000 (8 MB).

### `HighestAcceptableAddress` [in]

The highest physical address that is valid for the allocation. For example, if the device can only reference physical memory below 16 MB, this value would be set to 0xFFFFFF (16 MB - 1).

### `BoundaryAddressMultiple` [in, optional]

The physical address multiple that this allocation must not cross.

### `CacheType` [in]

The desired cache type for the mapping.

### `PreferredNode` [in]

The preferred node from which the allocation should be made if pages are available on that node.

### `BufferPointer` [out]

The variable that receives the starting address of the allocated memory block. Upon return from this routine, if this variable is zero, a contiguous range could not be found to satisfy the request. If this variable is not NULL, it contains a pointer (for example, a virtual address in the nonpaged portion of the system) to the allocated physically contiguous memory.

### `PhysicalAddress` [out]

Physical address of the allocated memory block.

## Return value

This function returns a STOR_STATUS code.

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_NOT_IMPLEMENTED | This function is not implemented on the active operating system. |
| STOR_STATUS_SUCCESS | The operation was successful. |
| STOR_STATUS_INSUFFICIENT_RESOURCES |The operation failed to allocate the requested memory because of insufficient resources. |

## Remarks

If the request fails, BufferPointer will be set to NULL.

## See also

[**StorPortFreeDmaMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportfreedmamemory)