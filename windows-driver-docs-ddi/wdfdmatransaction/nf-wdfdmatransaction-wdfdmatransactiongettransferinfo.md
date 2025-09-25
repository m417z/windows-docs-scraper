# WdfDmaTransactionGetTransferInfo function

## Description

[Applies to KMDF only]

The **WdfDmaTransactionGetTransferInfo** method returns the number of map registers and scatter/gather list entries required for an initialized DMA transaction.

## Parameters

### `DmaTransaction` [in]

A handle to an initialized DMA transaction object.

### `MapRegisterCount` [out, optional]

A caller-supplied location that, on return, contains the number of map registers required for the specified transaction. This parameter is optional and can be NULL.

### `ScatterGatherElementCount` [out, optional]

A caller-supplied location that, on return, contains the number of scatter/gather elements required for the specified transaction. This parameter is optional and can be NULL.

## Remarks

The driver might call **WdfDmaTransactionGetTransferInfo** before calling [WdfDmaTransactionAllocateResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionallocateresources) or [WdfDmaTransactionExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionexecute).

When using DMA version 3, this method returns an accurate count of the number of map registers needed. When using earlier DMA versions, this method assumes that each page requires a map register.

## See also

[WdfDmaTransactionAllocateResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionallocateresources)

[WdfDmaTransactionExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionexecute)