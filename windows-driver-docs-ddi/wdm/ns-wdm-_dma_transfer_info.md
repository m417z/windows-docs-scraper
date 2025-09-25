# _DMA_TRANSFER_INFO structure

## Description

The **DMA_TRANSFER_INFO** structure is a container for a **DMA_TRANSFER_INFO_*XXX*** structure that describes the allocation requirements for a scatter/gather list.

## Members

### `Version`

The version number of the **DMA_TRANSFER_INFO_*XXX*** structure that follows this member. For a [DMA_TRANSFER_INFO_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_transfer_info_v1) structure, set this member to DMA_TRANSFER_INFO_VERSION1 before calling the [GetDmaTransferInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_dma_transfer_info) routine.

### `V1`

The allocation requirements for a scatter/gather list. For more information, see [DMA_TRANSFER_INFO_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_transfer_info_v1).

### `V2`

The allocation requirements for a scatter/gather list. For more information, see [**DMA_TRANSFER_INFO_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_transfer_info_v2).

## Remarks

A device driver calls the [GetDmaTransferInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_dma_transfer_info) routine to obtain a **DMA_TRANSFER_INFO** structure that describes the allocation requirements for the scatter/gather list to use in a DMA transfer.

The unnamed union in this structure contains a **DMA_TRANSFER_INFO_*XXX*** structure. The **Version** member indicates which version of the **DMA_TRANSFER_INFO_*XXX*** structure is contained in the union.

## See also

[DMA_TRANSFER_INFO_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_transfer_info_v1)

[GetDmaTransferInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_dma_transfer_info)