# _WDF_DMA_DIRECTION enumeration

## Description

[Applies to KMDF only]

The **WDF_DMA_DIRECTION** enumeration defines the direction of a DMA transfer.

## Constants

### `WdfDmaDirectionReadFromDevice:FALSE`

The DMA transfer direction is from the device (read).

### `WdfDmaDirectionWriteToDevice:TRUE`

The DMA transfer direction is to the device (write).

## Remarks

The **WDF_DMA_DIRECTION** enumeration is used as input to the [EvtProgramDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_program_dma) callback function and the [WdfDmaTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitialize) and [WdfDmaTransactionInitializeUsingRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitializeusingrequest) methods.

## See also

[EvtProgramDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_program_dma)

[WdfDmaTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitialize)

[WdfDmaTransactionInitializeUsingRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitializeusingrequest)