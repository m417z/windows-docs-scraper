## Description

The DMA_ADAPTER_INFO structure is a container for a DMA_ADAPTER_INFO_XXX structure that describes the capabilities of a system DMA controller.

## Members

### `Version`

The version number of the **DMA_ADAPTER_INFO_***XXX* structure that follows this member. For a [DMA_ADAPTER_INFO_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter_info_v1) structure, set this member to DMA_ADAPTER_INFO_VERSION1 before calling the [GetDmaAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_dma_adapter_info) routine.

### `V1`

The capabilities of the bus-master DMA device or the system DMA controller. For more information, see [DMA_ADAPTER_INFO_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter_info_v1).

### `Reserved`

Reserved for future use.

### `Crashdump`

Defines the **DMA_ADAPTER_INFO_CRASHDUMP** member **Crashdump**.

## Remarks

A device driver calls the [GetDmaAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_dma_adapter_info) routine to obtain a **DMA_ADAPTER_INFO** structure that describes the capabilities of a DMA controller.

The unnamed union in this structure contains a **DMA_ADAPTER_INFO_***XXX* structure. The **Version** member indicates which version of the **DMA_ADAPTER_INFO_***XXX* structure is contained in the union. Currently, only version 1 is supported.

## See also

[DMA_ADAPTER_INFO_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter_info_v1)

[GetDmaAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_dma_adapter_info)