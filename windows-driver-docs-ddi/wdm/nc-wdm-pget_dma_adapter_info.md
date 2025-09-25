# PGET_DMA_ADAPTER_INFO callback function

## Description

The **GetDmaAdapterInfo** routine retrieves information about the hardware capabilities of a system DMA channel.

## Parameters

### `DmaAdapter` [in]

A pointer to a [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure. This structure is the adapter object that represents the driver's system DMA channel. The caller obtained this pointer from a previous call to the [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) routine.

### `AdapterInfo` [in, out]

A pointer to a caller-allocated [DMA_ADAPTER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter_info) structure. The routine writes information about the system DMA controller into this structure. The caller must set the
**Version** member of this structure to DMA_ADAPTER_INFO_VERSION1 before calling **GetDmaAdapterInfo**.

## Return value

**GetDmaAdapterInfo** returns STATUS_SUCCESS if the call is successful. Possible error return values include the following status code.

| Return code | Description |
| --- | --- |
| **STATUS_NOT_SUPPORTED** | The routine does not support the specified version of the **DMA_ADAPTER_INFO_*XXX*** structure. |

## Remarks

**GetDmaAdapterInfo** *is not a system routine that can be called directly by name. This routine can be called only by pointer from the address returned in a* [DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations) *structure.* Drivers obtain the address of this routine by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) with the **Version** member of the *DeviceDescription* parameter set to DEVICE_DESCRIPTION_VERSION3. If **IoGetDmaAdapter** returns **NULL**, the routine is not available on your platform.

**GetDmaAdapterInfo** retrieves the following information:

* The maximum number of elements in a scatter/gather list that the DMA controller can process in a single scatter/gather DMA operation.
* The width, in bits, of a DMA address.

For information about the DMA adapter information that is provided by version 1 of the **DMA_ADAPTER_INFO_*XXX*** structure, see [DMA_ADAPTER_INFO_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter_info_v1).

## See also

[DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[DMA_ADAPTER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter_info)

[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)