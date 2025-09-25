# WdfDmaTransactionGetCurrentDmaTransferLength function

## Description

[Applies to KMDF only]

The **WdfDmaTransactionGetCurrentDmaTransferLength** method returns the size of the current DMA transfer.

## Parameters

### `DmaTransaction` [in]

A handle to a DMA transaction object that the driver obtained from a previous call to [WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate).

## Return value

**WdfDmaTransactionGetCurrentDmaTransferLength** returns the length of the current DMA transfer.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

If a driver calls **WdfDmaTransactionGetCurrentDmaTransferLength**, it must do so before it calls one of the transfer completion routines, such as [WdfDmaTransactionDmaCompleted](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompleted), to complete the current DMA transfer. Typically, drivers call **WdfDmaTransactionGetCurrentDmaTransferLength** from within an [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc) event callback function.

Typically, a driver calls **WdfDmaTransactionGetCurrentDmaTransferLength** for devices that report residual DMA transfer lengths (that is, byte counts of data that was not transferred). By subtracting the residual transfer length from the value that **WdfDmaTransactionGetCurrentDmaTransferLength** returned, the driver can determine the actual transfer length. The driver then calls [WdfDmaTransactionDmaCompletedWithLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompletedwithlength) to let the framework know the number of bytes that the device actually transferred.

For more information about complete DMA transfers, see [Completing a DMA Transfer](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-a-dma-transfer).

#### Examples

For a code example that uses **WdfDmaTransactionGetCurrentDmaTransferLength**, see [WdfDmaTransactionDmaCompletedWithLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompletedwithlength).

## See also

[EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc)

[WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate)

[WdfDmaTransactionDmaCompleted](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompleted)

[WdfDmaTransactionDmaCompletedWithLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompletedwithlength)