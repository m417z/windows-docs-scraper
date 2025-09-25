# WdfDmaTransactionDmaCompletedWithLength function

## Description

[Applies to KMDF only]

The **WdfDmaTransactionDmaCompletedWithLength** method notifies the framework that a device's DMA transfer operation is complete and supplies the length of the completed transfer.

## Parameters

### `DmaTransaction` [in]

A handle to a DMA transaction object that the driver obtained from a previous call to [WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate).

### `TransferredLength` [in]

The number of bytes that the device transferred in the current DMA transfer.

### `Status` [out]

A pointer to a location that receives the status of the DMA transfer. For more information, see the Remarks section for [WdfDmaTransactionDmaCompleted](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompleted).

## Return value

**WdfDmaTransactionDmaCompletedWithLength** returns **FALSE** and *Status* receives STATUS_MORE_PROCESSING_REQUIRED if additional transfers are needed to complete the DMA transaction. The method returns **TRUE** if no additional transfers are required.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

When your driver calls the **WdfDmaTransactionDmaCompletedWithLength** method, the framework ends the current transfer and, if necessary, starts a new one.

The **WdfDmaTransactionDmaCompletedWithLength** method behaves the same as [WdfDmaTransactionDmaCompleted](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompleted), except that drivers call **WdfDmaTransactionDmaCompletedWithLength** for devices that report the number of bytes that were transferred. The framework uses the reported byte count to determine the beginning of the next DMA transfer for the specified DMA transaction, if multiple transfers are needed to complete the transaction.

For more information about completing DMA transfers, see [Completing a DMA Transfer](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-a-dma-transfer).

#### Examples

The following code example is from the [PLX9x5x](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample driver. This example calls [WdfDmaTransactionGetCurrentDmaTransferLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiongetcurrentdmatransferlength) to determine the current transfer's original length, and then it calculates the actual transfer length. Next, the example calls **WdfDmaTransactionDmaCompletedWithLength** to report the actual transfer length to the framework. If the current transfer is the last one for the transaction, the example calls a private routine that completes the I/O request.

```cpp
BOOLEAN  hasTransitioned;
PDMA_TRANSFER_ELEMENT  dteVA;
ULONG  length;
//
// Use "DMA Clear-Count Mode" to get the complementary
// transferred byte count.
//
length = WdfDmaTransactionGetCurrentDmaTransferLength(dmaTransaction);
dteVA = (PDMA_TRANSFER_ELEMENT) devExt->ReadCommonBufferBase;
while(dteVA->DescPtr.LastElement == FALSE) {
    length -= dteVA->TransferSize;
    dteVA++;
}
length -= dteVA->TransferSize;
//
// Indicate that this DMA operation has completed.
//
hasTransitioned =
    WdfDmaTransactionDmaCompletedWithLength(
                                            dmaTransaction,
                                            length,
                                            &status
                                            );
if (hasTransitioned) {
    //
    // Complete this DMA transaction.
    //
    devExt->CurrentReadDmaTransaction = NULL;
    PLxReadRequestComplete(
                           dmaTransaction,
                           status
                           );
}
```

## See also

[WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate)

[WdfDmaTransactionDmaCompleted](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompleted)

[WdfDmaTransactionGetCurrentDmaTransferLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiongetcurrentdmatransferlength)