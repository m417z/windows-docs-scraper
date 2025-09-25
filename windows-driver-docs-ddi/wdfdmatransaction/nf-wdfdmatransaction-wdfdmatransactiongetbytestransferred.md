# WdfDmaTransactionGetBytesTransferred function

## Description

[Applies to KMDF only]

The **WdfDmaTransactionGetBytesTransferred** method returns the total number of bytes that have been transferred for a specified DMA transaction.

## Parameters

### `DmaTransaction` [in]

A handle to a DMA transaction object that the driver obtained from a previous call to [WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate).

## Return value

**WdfDmaTransactionGetBytesTransferred** returns the total number of bytes that have been transferred for the DMA transaction that the *DmaTransaction* parameter specified.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Framework-based drivers typically call **WdfDmaTransactionGetBytesTransferred** from within an [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc) event callback function, after all DMA transfers are complete, to obtain the final transferred byte count. Drivers typically use the final byte count as input to the [WdfRequestCompleteWithInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcompletewithinformation) method. For more information about this method, see [Completing a DMA Transaction](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-a-dma-transaction).

#### Examples

For a code example that uses **WdfDmaTransactionGetBytesTransferred**, see [WdfDmaTransactionDmaCompleted](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompleted).

## See also

[EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc)

[WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate)

[WdfDmaTransactionDmaCompleted](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompleted)

[WdfRequestCompleteWithInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcompletewithinformation)