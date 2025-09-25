# _DMA_ADAPTER_INFO_V1 structure

## Description

The **DMA_ADAPTER_INFO_V1** structure describes the capabilities of the system DMA controller that is represented by an adapter object.

## Members

### `ReadDmaCounterAvailable`

Whether the counter value in each DMA channel can be read. This member is **TRUE** if the counter can be read, and is **FALSE** if it cannot be read.

### `ScatterGatherLimit`

The maximum number of elements in a scatter/gather list that the DMA controller can process in a single scatter/gather DMA transfer.

### `DmaAddressWidth`

The memory address width, in bits, of the DMA controller. The width is expressed as the number of bits in a DMA address. If the DMA address width is less than the memory address width, the platform hardware drives the remaining, high-order memory address bits to zero during a DMA transfer.

### `Flags`

A set of flags that describe the capabilities of the DMA adapter. No flags are currently defined for this member.

### `MinimumTransferUnit`

The size, in bytes, of the minimum transfer unit. The number of bytes specified by an element in a scatter/gather list must be an integer multiple of the minimum transfer unit.

## Remarks

The **V1** member of the [DMA_ADAPTER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter_info) structure is a structure of type **DMA_ADAPTER_INFO_V1**.

A driver calls [GetDmaAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_dma_adapter_info) to obtain information about the hardware capabilities of a system DMA channel. **GetDmaAdapterInfo** writes this information into the **V1** member of a caller-supplied **DMA_ADAPTER_INFO** structure.

## See also

[DMA_ADAPTER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter_info)

[GetDmaAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_dma_adapter_info)