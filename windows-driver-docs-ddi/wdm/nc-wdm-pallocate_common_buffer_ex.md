## Description

The **AllocateCommonBufferEx** routine allocates memory for a common buffer and maps this memory so that it can be accessed both by the processor and by a device that performs DMA operations.

## Parameters

### `DmaAdapter` [in]

A pointer to a [**DMA_ADAPTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure. This structure is the adapter object that represents the driver's bus-master DMA device or system DMA channel. The caller obtained this pointer from a previous call to the [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) routine.

### `MaximumAddress` [in, optional]

A pointer to a variable that contains the maximum logical address for the common buffer. This parameter indicates that the buffer should be allocated from memory below this address. This parameter is optional and can be specified as NULL to indicate that there is no maximum address.

### `Length` [in]

The size, in bytes, of the common buffer that is to be allocated for the DMA operation.

### `LogicalAddress` [out]

A pointer to a variable into which this routine writes the logical address that the device can use to access the common buffer. The DMA device should use this logical address instead of the physical address that is returned by a routine such as [MmGetPhysicalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmgetphysicaladdress).

### `CacheEnabled` [in]

Whether the routine must enable or disable cached memory in the common buffer that is to be allocated. If TRUE, caching is enabled. If FALSE, it is disabled. If the hardware platform does not enforce cache coherency for DMA operations, then pass FALSE. For information about this parameter on ARM or ARM 64-based processors target computers, see Remarks.

### `PreferredNode` [in]

The preferred NUMA node from which the memory is to be allocated. If N is the number of NUMA nodes in a multiprocessor system, *PreferredNode* is a number in the range 0 to N–1. For a one-processor system or a non-NUMA multiprocessor system, set *PreferredNode* to zero.

## Return value

**AllocateCommonBufferEx** returns the virtual address of the memory allocated for the common buffer. If the buffer cannot be allocated, NULL is returned.

## Remarks

**AllocateCommonBufferEx** is not a system routine that can be called directly by name. This routine can be called only by pointer from the address returned in a [**DMA_OPERATIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations) structure. Drivers obtain the address of this routine by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) with the Version member of the *DeviceDescription* parameter set to DEVICE_DESCRIPTION_VERSION3. If **IoGetDmaAdapter** returns **NULL**, the routine is not available on your platform.

**AllocateCommonBufferEx** is an extended version of the [AllocateCommonBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_common_buffer) routine. The following list summarizes the features that are available only in the extended version:

- The caller can specify a maximum logical address for the common buffer that is to be allocated.

- The caller can specify a preferred NUMA node in which the common buffer is to be allocated.

On computers with ARM or ARM 64-based processors, cache settings in the system ACPI have a higher precedence than the *CacheEnabled* parameter value passed by the driver. If the **ACPI _CCA** method indicates that the device is not cache coherent, the operating system disables caching even if the driver allocates cached memory with *CacheEnabled* set to TRUE.

On computers with ARM or ARM 64-based processors, the operating system allocates an uncached common buffer as Device Memory. For more information about the buffer, see sections A3.5.1, and A3.5.6 from the [ARMv7 Architecture Reference Manual](https://developer.arm.com/documentation).

The processor does not permit misaligned access to Device Memory. Your driver must always access data from the common buffer by using naturally-aligned operations. Most kernel routines do not accept Device Memory as input parameters. For example, a network driver cannot pass Device Memory into [NdisMIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatereceivenetbufferlists). If your driver needs to pass data from a DMA common buffer to a kernel routine, either allocate the buffer with *CacheEnabled* set to TRUE or copy the data from the uncached common buffer into a temporary pool allocation.

For more information about DMA operations that use a common buffer, see the following topics:

[Using Common Buffers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-common-buffers)

[Using Common-Buffer Bus-Master DMA](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-buffer-bus-master-dma)

[Using Common-Buffer System DMA](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-buffer-system-dma)

## See also

[AllocateCommonBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_common_buffer)

[**DMA_ADAPTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[**DMA_OPERATIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)

[MmGetPhysicalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmgetphysicaladdress)