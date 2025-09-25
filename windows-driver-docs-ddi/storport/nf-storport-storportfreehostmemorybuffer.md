# StorPortFreeHostMemoryBuffer function

## Description

The **StorPortFreeHostMemoryBuffer** routine frees the physically contiguous memory
that was allocated to be used for a Host Memory Buffer (HMB)

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `PhysicalAddressRanges`

The array of physical address ranges that make up
the Host Memory Buffer previously allocated by **StorPortAllocateHostMemoryBuffer**.

### `PhysicalAddressRangeCount` [in]

 The number of entries in **PhysicalAddressRanges**.

## Return value

**StorPortFreeHostMemoryBuffer** returns one of the following status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_SUCCESS** | The host memory buffer was successfully freed. |
| **STOR_STATUS_UNSUCCESSFUL** | The host memory buffer was not valid (likely already freed). |

## See also

[StorPortAllocateHostMemoryBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportallocatehostmemorybuffer)