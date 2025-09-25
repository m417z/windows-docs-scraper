## Description

The CreateCommonBufferFromMdl routine will attempt to create a common buffer from an MDL by testing for device access compatibility and potentially mapping the memory to a contiguous logical range depending on the translation type. Like all other common buffer allocation functions, this function does not provide a forward progress guarantee.

## Parameters

### `DmaAdapter` [in]

Provides a pointer to the DMA Adapter that is performing the operation.

### `Mdl` [in]

Provides the MDL that will be mapped to a common buffer.

For an MDL to be able to back a common buffer, the following conditions must be met:

- The MDL must have pages that are always resident for the lifetime of the common buffer and that are mapped into the system address space. This can be accomplished by the following approaches:

- The MDL is created from a buffer in the non-paged pool via [*MmBuildMdlForNonPagedPool*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmbuildmdlfornonpagedpool).

- The MDL has been locked via [*MmProbeAndLockPages*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockselectedpages) and mapped to system space via [*MmGetSystemAddressForMdlSafe*](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer#mmgetsystemaddressformdlsafe).

- The physical pages for the MDL have been allocated via [*MmAllocatePagesForMdlEx*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdl) and mapped to system space via [*MmGetSystemAddressForMdlSafe*](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer#mmgetsystemaddressformdlsafe).

- The MDL must represent a page-aligned region and be a multiple of PAGE_SIZE.

  - If the SubSection extended configuration is being used, then the portion of the MDL being used must be page-aligned and be a multiple of PAGE_SIZE.

- The MDL must not be a chained MDL.

  - If the SubSection extended configuration is being used, then a chained MDL can be provided, but the portion of the MDL being used must be contained in a single MDL in the chain.

- If DMA Remapping is not being used, the MDL must represent physically contiguous memory and be accessible to the device.

### `ExtendedConfigs` [in]

Provides an optional array of [DMA_COMMON_BUFFER_EXTENDED_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_common_buffer_extended_configuration) structures to further configure the creation of the MDL backed common buffer.

If multiple configurations of the same [DMA_COMMON_BUFFER_EXTENDED_CONFIGURATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_dma_common_buffer_extended_configuration_type) are provided in the array, creation will fail.

### `ExtendedConfigsCount` [in]

Provides the number of extended configurations in the *ExtendedConfigs* array.

### `LogicalAddress` [out]

On success provides the logical address of the resulting common buffer.

## Return value

**CreateCommonBufferFromMdl** return **STATUS_SUCCESS** if the call is successful. Possible error return values include the following status codes.

| Return code | Description |
|---|---|
| **STATUS_INVALID_PARAMETER** | The caller has provided an incompatible MDL or extended configuration. |
| **STATUS_NOT_SUPPORTED** | The caller has provided an extended configuration that is not supported on the current system. |
| **STATUS_INSUFFICIENT_RESOURCES** | The system does not have enough memory to create book-keeping and mapping metadata. |

## Remarks

**CreateCommonBufferFromMdl** is not a system routine that can be called directly by name. This routine can be called only by pointer from the address returned in a [*DMA_OPERATIONS*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations) structure. Drivers obtain the address of this routine by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) with the **Version** member of the *DeviceDescription* parameter set to DEVICE_DESCRIPTION_VERSION3. If **IoGetDmaAdapter** returns **NULL**, the routine is not available on your platform.

A common buffer created by **CreateCommonBufferFromMdl** will be removed via [FreeCommonBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_common_buffer). The caller must provide the system virtual address as the virtual address to ensure the common buffer is correctly removed from the Adapter's common buffer bookkeeping structures. The driver is still responsible for unlocking and freeing the MDL and its backing pages.

To create a common buffer where the HAL is responsible for maintaining the backing memory, use [AllocateCommonBufferWithBounds](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_common_buffer_with_bounds).

## See also

[**DMA_ADAPTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[**DMA_COMMON_BUFFER_EXTENDED_CONFIGURATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_common_buffer_extended_configuration)

[DMA_COMMON_BUFFER_EXTENDED_CONFIGURATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_dma_common_buffer_extended_configuration_type)

[**DMA_OPERATIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[FreeCommonBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_common_buffer)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)

[PALLOCATE_COMMON_BUFFER_WITH_BOUNDS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_common_buffer_with_bounds)