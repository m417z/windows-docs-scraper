# DMA_COMPLETION_STATUS enumeration

## Description

The **DMA_COMPLETION_STATUS** enumeration describes the completion status of a DMA transfer.

## Constants

### `DmaComplete`

The DMA transfer completed successfully.

### `DmaAborted`

Not used.

### `DmaError`

The DMA transfer did not complete successfully because an error occurred.

### `DmaCancelled`

The DMA transfer did not complete successfully because the client canceled the transfer.

## Remarks

The *Status* parameter of the [DmaCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-dma_completion_routine) routine is a **DMA_COMPLETION_STATUS** enumeration value.

## See also

[DmaCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-dma_completion_routine)