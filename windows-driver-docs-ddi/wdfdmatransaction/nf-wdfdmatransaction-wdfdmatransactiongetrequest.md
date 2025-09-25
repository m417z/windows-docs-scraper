# WdfDmaTransactionGetRequest function

## Description

[Applies to KMDF only]

The **WdfDmaTransactionGetRequest** method retrieves a handle to the framework request object that is associated with a specified DMA transaction.

## Parameters

### `DmaTransaction` [in]

A handle to a DMA transaction object that the driver obtained from a previous call to [WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate).

## Return value

**WdfDmaTransactionGetRequest** returns a handle to the framework request object that is associated with the DMA transaction that the *DmaTransaction* parameter specified.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

A driver can call **WdfDmaTransactionGetRequest** only for DMA transactions that the driver created by calling [WdfDmaTransactionInitializeUsingRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitializeusingrequest). If a driver calls **WdfDmaTransactionGetRequest** for a DMA transaction that it created by calling [WdfDmaTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitialize), **WdfDmaTransactionGetRequest** returns **NULL**.

For more information about completing DMA transfers, see [Completing a DMA Transfer](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-a-dma-transfer).

#### Examples

The following code example obtains a handle to the framework request object that is associated with a specified DMA transaction.

```cpp
WDFREQUEST  request;

request = WdfDmaTransactionGetRequest(dmaTransaction);
```

## See also

[WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate)

[WdfDmaTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitialize)

[WdfDmaTransactionInitializeUsingRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitializeusingrequest)