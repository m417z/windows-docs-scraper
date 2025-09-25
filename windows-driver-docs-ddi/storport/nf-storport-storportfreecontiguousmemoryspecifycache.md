# StorPortFreeContiguousMemorySpecifyCache function

## Description

The **StorPortFreeContiguousMemorySpecifyCache** routine deallocates a range of noncached memory in the nonpaged portion of the system address space.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `BaseAddress` [in]

The base virtual address to free.

### `NumberOfBytes` [in]

The number of bytes that are allocated to the request. This must be the same number that was supplied as a parameter when the [StorPortAllocateContiguousMemorySpecifyCacheNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportallocatecontiguousmemoryspecifycachenode) routine was previously called.

### `CacheType` [in]

The cache type that is used in the call to the [StorPortAllocateContiguousMemorySpecifyCacheNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportallocatecontiguousmemoryspecifycachenode) routine.

## Return value

The **StorPortFreeContiguousMemorySpecifyCache** routine returns one of the following status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | The operation was successful. |

## See also

[StorPortAllocateContiguousMemorySpecifyCacheNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportallocatecontiguousmemoryspecifycachenode)