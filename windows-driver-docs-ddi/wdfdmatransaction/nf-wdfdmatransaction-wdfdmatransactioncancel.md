# WdfDmaTransactionCancel function

## Description

[Applies to KMDF only]

The **WdfDmaTransactionCancel** method attempts to cancel a DMA transaction that is waiting for the allocation of map registers.

## Parameters

### `DmaTransaction` [in]

A handle to the DMA transaction object that represents the transaction that is being canceled. This transaction must have already been initialized by the driver.

## Return value

**WdfDmaTransactionCancel** returns TRUE if the framework successfully cancels map register allocation. In this case, no transfers are completed, and the framework makes no additional DMA callbacks on the transaction until it is reinitiated.

 The method returns FALSE if another thread is already processing this transaction, or if the driver has not yet called [WdfDmaTransactionExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionexecute). In the first case, the framework is currently calling or will call [EvtProgramDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_program_dma) or [EvtReserveDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_reserve_dma). At this point, a driver that specified a system-mode DMA profile might call [WdfDmaTransactionStopSystemTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionstopsystemtransfer).

The method also returns FALSE if called with a transaction that was allocated from a DMA version 2 enabler.

## Remarks

The driver might call **WdfDmaTransactionCancel** from an [EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel) event callback function that it supplies in a call to [WdfRequestMarkCancelableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelableex). For a code example that shows how to do this, see [WdfDmaTransactionStopSystemTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionstopsystemtransfer).

The driver might also call **WdfDmaTransactionCancel** from an [EvtIoCanceledOnQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_canceled_on_queue) event callback function.

Cancellation can only succeed if the call to **WdfDmaTransactionCancel** occurs after the call to [WdfDmaTransactionExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionexecute), but before the **WdfDmaTransactionExecute** method has started the DMA allocation. For more information, see [Canceling DMA Transactions](https://learn.microsoft.com/windows-hardware/drivers/wdf/canceling-dma-transactions).

The driver must call **WdfDmaTransactionCancel** after calling [WdfDmaTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitialize), but before calling [WdfDmaTransactionRelease](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionrelease) or [WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete) to delete the transaction object.

 Do not call **WdfDmaTransactionCancel** after the framework has called [EvtProgramDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_program_dma) or [EvtReserveDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_reserve_dma).

A driver must request use of DMA version 3 prior to calling **WdfDmaTransactionCancel**.
To select DMA version 3, set the **WdmDmaVersionOverride** member of [WDF_DMA_ENABLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config) to 3.

 If a driver calls **WdfDmaTransactionCancel** on a transaction that was allocated from a DMA version 2 enabler, the framework generates a verifier error and **WdfDmaTransactionCancel** returns FALSE. In this case, no attempt is made to cancel the transaction.

## See also

[EvtProgramDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_program_dma)

[EvtReserveDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_reserve_dma)

[WdfDmaTransactionStopSystemTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionstopsystemtransfer)