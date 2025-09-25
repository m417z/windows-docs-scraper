# _DMA_TRANSFER_INFO_V2 structure

## Description

Contains the allocation requirements for a scatter/gather list that describes the I/O data buffer for a DMA transfer.

## Members

### `MapRegisterCount`

The number of map registers required to translate all the physical addresses in the scatter/gather list to logical addresses.

### `ScatterGatherElementCount`

The number of scatter/gather elements in the scatter/gather list. Each element is a structure of type **SCATTER_GATHER_ELEMENT**.

### `ScatterGatherListSize`

The required size, in bytes, of the scatter/gather buffer. This buffer contains the scatter/gather list that describes the memory that is used to buffer I/O data during the DMA transfer. The scatter/gather buffer must be large enough to contain a [SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_scatter_gather_list) structure and an array of **SCATTER_GATHER_ELEMENT** structures, plus additional data that is used internally by the operating system.

### `LogicalPageCount`

The number of logical pages.

## Remarks

The **V2** member of the [DMA_TRANSFER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_transfer_info) structure is a structure of type **DMA_TRANSFER_INFO_V2**.

The *Mdl*, *Offset*, and *Length* parameters to the [GetDmaTransferInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_dma_transfer_info) routine together describe the I/O data buffer for a DMA transfer. For the purpose of programming a DMA controller, this buffer can more conveniently be described by a scatter/gather list. (A scatter/gather list describes the memory in an I/O data buffer but does not contain this memory.) A driver calls **GetDmaTransferInfo** to obtain the allocation requirements for this scatter/gather list. **GetDmaTransferInfo** writes the allocation requirements into the **V1** member of a caller-supplied **DMA_TRANSFER_INFO** structure.

## See also