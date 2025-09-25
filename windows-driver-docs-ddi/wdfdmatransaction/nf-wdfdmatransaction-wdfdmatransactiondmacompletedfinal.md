# WdfDmaTransactionDmaCompletedFinal function

## Description

[Applies to KMDF only]

The **WdfDmaTransactionDmaCompletedFinal** method notifies the framework that a device's DMA transfer operation has completed with an underrun condition and supplies the length of the completed transfer.

## Parameters

### `DmaTransaction` [in]

A handle to a DMA transaction object that the driver obtained from a previous call to [WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate).

### `FinalTransferredLength` [in]

The number of bytes that the device transferred.

### `Status` [out]

A pointer to a location that receives the status of the DMA transfer. For more information, see the Remarks section for [WdfDmaTransactionDmaCompleted](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompleted).

## Return value

**WdfDmaTransactionDmaCompletedFinal** returns **FALSE** if the driver supplies an invalid input parameter. Otherwise, **WdfDmaTransactionDmaCompletedFinal** always returns **TRUE**, which indicates that the framework will not attempt to transfer any more bytes for the DMA transaction that the *DmaTransaction* parameter specified.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

A driver typically calls **WdfDmaTransactionDmaCompletedFinal** from within its [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc) callback. A driver for a system-mode DMA device might call **WdfDmaTransactionDmaCompletedFinal** from within an [EvtDmaTransactionDmaTransferComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_dma_transaction_dma_transfer_complete) event callback function.

In the [PLX9x5x](https://learn.microsoft.com/samples/browse/?redirectedfrom=MSDN-samples) sample, the driver calls **WdfDmaTransactionDmaCompletedFinal** from its [EvtProgramDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_program_dma) callback function.

The **WdfDmaTransactionDmaCompletedFinal** method behaves the same as [WdfDmaTransactionDmaCompleted](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompleted), except that drivers typically call **WdfDmaTransactionDmaCompletedFinal** if the hardware reports an underrun condition. An underrun condition means that the hardware could not transfer all of the bytes that were specified for the last DMA transfer. A call to **WdfDmaTransactionDmaCompletedFinal** stops the framework from starting any more DMA transfers for the specified DMA transaction.

When your driver calls **WdfDmaTransactionDmaCompletedFinal**, the driver supplies the number of bytes that were transferred. The return value is always **TRUE**, because the framework will not attempt to transfer any more bytes for the specified transaction.

For more information about completing DMA transfers, see [Completing a DMA Transfer](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-a-dma-transfer).

#### Examples

The following code example notifies the framework that a device's DMA transfer operation has completed with an underrun condition.

```cpp
BOOLEAN  success;
NTSTATUS  status;

success = WdfDmaTransactionDmaCompletedFinal(
                                             DmaTransaction,
                                             transferLength,
                                             &status
                                             );
```

## See also

[WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate)

[WdfDmaTransactionDmaCompleted](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompleted)

[WdfDmaTransactionDmaCompletedWithLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompletedwithlength)