# EVT_WDF_PROGRAM_DMA callback function

## Description

[Applies to KMDF only]

A framework-based driver's *EvtProgramDma* event callback function programs a specified device to perform a DMA transfer operation.

## Parameters

### `Transaction` [in]

A handle to the DMA transaction object that represents the current DMA transaction.

### `Device` [in]

A handle to a framework device object.

### `Context` [in]

The context pointer that the driver specified in a previous call to [WdfDmaTransactionExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionexecute).

### `Direction` [in]

A [WDF_DMA_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ne-wdfdmaenabler-_wdf_dma_direction)-typed value that specifies the direction of the DMA transfer operation.

### `SgList` [in]

A pointer to a [SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_scatter_gather_list) structure.

## Return value

The *EvtProgramDma* callback function must return **TRUE** if it successfully starts the DMA transfer operation. Otherwise, this callback function must return **FALSE**. However, the framework currently ignores the return value.

## Remarks

Drivers register an *EvtProgramDma* event callback function by calling [WdfDmaTransactionInitializeUsingRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitializeusingrequest) or [WdfDmaTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitialize).

The framework calls a driver's *EvtProgramDma* event callback function when a [DMA transfer](https://learn.microsoft.com/windows-hardware/drivers/wdf/dma-transactions-and-dma-transfers) is available. The callback function must program the hardware to start the transfer.

The driver must not manipulate the data buffers associated with the transaction until after **WdfDmaTransactionDmaCompleted***Xxx* has returned TRUE.

For single packet transfers, the scatter/gather list that the *SgList* parameter points to contains a single element.

For more information about this callback function, see [Programming DMA Hardware](https://learn.microsoft.com/windows-hardware/drivers/wdf/programming-dma-hardware).

## See also

[WdfDmaTransactionExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionexecute)

[WdfDmaTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitialize)

[WdfDmaTransactionInitializeUsingRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitializeusingrequest)