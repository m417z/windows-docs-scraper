# WdfDmaTransactionSetImmediateExecution function

## Description

[Applies to KMDF only]

The **WdfDmaTransactionSetImmediateExecution** method
marks the specified DMA transaction so that calls to [WdfDmaTransactionExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionexecute) and [WdfDmaTransactionAllocateResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionallocateresources) initiate the transaction immediately or fail.

## Parameters

### `DmaTransaction` [in]

A handle to a DMA transaction object to mark for immediate execution.

### `UseImmediateExecution` [in]

A Boolean value which, if TRUE, indicates that the transaction should execute immediately (or fail if resources are not available), and, if FALSE, indicates that the transaction should be queued for execution once DMA resources are available.

## Remarks

Before calling **WdfDmaTransactionSetImmediateExecution**, the driver must initialize the transaction.

If the driver calls [WdfDmaTransactionExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionexecute) or [WdfDmaTransactionAllocateResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionallocateresources) after calling **WdfDmaTransactionSetImmediateExecution** with *UseImmediateExecution* set to TRUE, and the resources needed for the request are unavailable, that method returns STATUS_INSUFFICIENT_RESOURCES. If the required resources are available, the framework claims them and initiates the call synchronously.

After the driver marks a transaction for immediate execution, the transaction remains marked as such until the driver calls [WdfDmaTransactionRelease](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionrelease) or clears the flag by calling **WdfDmaTransactionSetImmediateExecution** with *UseImmediateExecution* set to FALSE.

**WdfDmaTransactionSetImmediateExecution** requires DMA version 3.
To select DMA version 3, set the **WdmDmaVersionOverride** member of [WDF_DMA_ENABLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config) to 3.

If your driver calls this method on an operating system earlier than Windows 8, [the framework's verifier](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-kmdf-verifier) reports an error.

## See also

[WdfDmaTransactionAllocateResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionallocateresources)

[WdfDmaTransactionExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionexecute)

[WdfDmaTransactionRelease](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionrelease)