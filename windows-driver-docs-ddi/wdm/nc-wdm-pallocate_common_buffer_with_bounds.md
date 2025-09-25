## Description

This callback function allocates the memory for a common buffer and maps it so that it can be accessed by a master device and the CPU. The common buffer can be bound by an optional minimum and maximum logical address.

## Parameters

### `DmaAdapter` [in]

A pointer to a DMA_ADAPTER structure. This structure is the adapter object that represents the driver's bus-master DMA device or system DMA channel. The caller obtained this pointer from a previous call to the [**IoGetDmaAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) routine.

### `MinimumAddress` [in, optional]

A pointer to a variable that contains the minimum logical address for the common buffer. This parameter indicates that the buffer should be allocated from memory at and above this address. This parameter is optional and can be specified as NULL to indicate that there is no minimum address.

### `MaximumAddress` [in, optional]

A pointer to a variable that contains the maximum logical address for the common buffer. This parameter indicates that the buffer should be allocated from memory below this address. This parameter is optional and can be specified as NULL to indicate that there is no maximum address.

### `Length` [in]

The size, in bytes, of the common buffer that is to be allocated for the DMA operation.

### `Flags` [in]

The size, in bytes, of the common buffer that is to be allocated for the DMA operation.

| Flag | Meaning |
|---|---|
| **DOMAIN_COMMON_BUFFER_LARGE_PAGE** | The common buffer will be allocated using a larger page granularity of PAGE_SIZE * 512. Note that this can increase the chance of the allocation being unsuccessful. |

### `CacheType` [in, optional]

A pointer to a [**MEMORY_CACHING_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_memory_caching_type) enumeration indicating whether the routine must enable or disable cached memory in the common buffer that is to be allocated. Only values of **MmNonCached** and **MmCached** are supported. The parameter is optional and can be specified as NULL to specify the caching will be dependent upon the hardware platform default.

### `PreferredNode` [in]

The preferred NUMA node from which the memory is to be allocated. If N is the number of NUMA nodes in a multiprocessor system, *PreferredNode* is a number in the range 0 to N–1. For a one-processor system or a non-NUMA multiprocessor system, set *PreferredNode* to zero.

### `LogicalAddress` [out]

A pointer to a variable into which this routine writes the logical address that the device can use to access the common buffer. The DMA device should use this logical address instead of the physical address that is returned by a routine such as [**MmGetPhysicalAddress**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmgetphysicaladdress).

## Return value

Returns PVOID that is the virtual address of the memory allocated for the common buffer. If the buffer cannot be allocated, then returns NULL.

## Remarks

This callback function is an extended version of the [*PALLOCATE_COMMON_BUFFER_EX*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_common_buffer_ex) routine. The following list summarizes the features that are available only in the extended version:

- The caller can specify a minimum logical address for the common buffer that is to be allocated.

- The caller can provide a caching type override that will be followed regardless of the hardware platform.

- The caller can specify the use of a larger granularity for their common buffer allocation.

## See also

[**DMA_OPERATIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[*PALLOCATE_COMMON_BUFFER_EX*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_common_buffer_ex)