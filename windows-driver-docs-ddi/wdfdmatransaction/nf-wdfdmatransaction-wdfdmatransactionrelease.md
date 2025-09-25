# WdfDmaTransactionRelease function

## Description

[Applies to KMDF only]

The **WdfDmaTransactionRelease** method terminates a specified DMA transaction without deleting the associated DMA transaction object.

## Parameters

### `DmaTransaction` [in]

A handle to a DMA transaction object that the driver obtained from a previous call to [WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate).

## Return value

**WdfDmaTransactionRelease** returns STATUS_SUCCESS if the operation succeeds. Otherwise, the method might return the following value:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_STATE** | The driver has already released or deleted the transaction object that the *DmaTransaction* parameter specified. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The **WdfDmaTransactionRelease** method flushes transfer buffers and releases all of the system resources that are associated with the DMA transaction. The transaction object is not deleted and can be reused. For more information about reusing transaction objects, see [Reusing DMA Transaction Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/reusing-dma-transaction-objects).

If **WdfDmaTransactionInitialize*Xxx*** returns success but [WdfDmaTransactionExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionexecute) returns an error value, your driver must call **WdfDmaTransactionRelease**.

#### Examples

The following code example terminates the DMA transaction that the specified DMA transaction object represents, but it does not delete the DMA transaction object.

```cpp
NTSTATUS  status;

status = WdfDmaTransactionRelease(dmaTransaction);
```

## See also

[WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate)