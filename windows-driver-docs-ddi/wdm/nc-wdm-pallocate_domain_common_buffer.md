## Description

This callback function allocates the memory for a domain common buffer.

## Parameters

### `DmaAdapter` [in]

A pointer to a DMA_ADAPTER structure. This structure is the adapter object that represents the driver's bus-master DMA device or system DMA channel. The caller obtained this pointer from a previous call to the [**IoGetDmaAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) routine.

### `DomainHandle` [in]

The handle to the DMA domain that the caller obtained from a previous call to [*PGET_DMA_DOMAIN*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_dma_domain).

### `MaximumAddress` [in, optional]

A pointer to a variable that contains the maximum logical address for the common buffer. This parameter indicates that the buffer should be allocated from memory below this address. This parameter is optional and can be specified as NULL to indicate that there is no maximum address.

### `Length` [in]

The size, in bytes, of the common buffer that is to be allocated for the DMA operation.

### `Flags` [in]

The size, in bytes, of the common buffer that is to be allocated for the DMA operation.

Possible values include:

- **DOMAIN_COMMON_BUFFER_LARGE_PAGE**

 The common buffer will be allocated using a larger page granularity of PAGE_SIZE * 512. Note that this can increase the chance of the allocation being unsuccessful.

### `CacheType` [in, optional]

A pointer to a [**MEMORY_CACHING_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_memory_caching_type) enumeration indicating whether the routine must enable or disable cached memory in the common buffer that is to be allocated. Only values of **MmNonCached** and **MmCached** are supported. The parameter is optional and can be specified as NULL to specify the caching will be dependent upon the hardware platform default.

If a caller provides an override value of **MmCached** on an adapter that is not cache-coherent, they are responsible for flushing the contents of the cache. If unsure, a caller should always provide NULL.

### `PreferredNode` [in]

The preferred NUMA node from which the memory is to be allocated. If N is the number of NUMA nodes in a multiprocessor system, *PreferredNode* is a number in the range 0 to N–1. For a one-processor system or a non-NUMA multiprocessor system, set *PreferredNode* to zero.

### `LogicalAddress` [out]

A pointer to a variable into which this routine writes the logical address that the device can use to access the common buffer. The DMA device should use this logical address instead of the physical address that is returned by a routine such as [**MmGetPhysicalAddress**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmgetphysicaladdress).

### `VirtualAddress` [out]

A pointer to a variable into which this routine writes the corresponding virtual address of the allocated buffer.

## Return value

Returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate [NTSTATUS value](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

## See also

[**DMA_OPERATIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)