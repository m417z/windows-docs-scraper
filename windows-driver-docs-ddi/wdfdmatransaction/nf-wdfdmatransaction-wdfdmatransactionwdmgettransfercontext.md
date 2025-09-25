# WdfDmaTransactionWdmGetTransferContext function

## Description

[Applies to KMDF only]

 The **WdfDmaTransactionWdmGetTransferContext** method retrieves the WDM transfer context that is associated with a DMA transaction.

## Parameters

### `DmaTransaction` [in]

A handle to an initialized DMA transaction object from which to retrieve the transfer context.

## Return value

A pointer to the DMA transfer context (PTRANSFER_CONTEXT) associated with the transaction.

## Remarks

The DMA transfer context for a transaction is allocated when the driver creates the transaction.

**WdfDmaTransactionWdmGetTransferContext** must be used with a DMA enabler that uses DMA version 3. To select version 3, set the **WdmDmaVersionOverride** member of [WDF_DMA_ENABLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config) to 3.

Your driver can use the DMA transfer context to call the following WDM DMA library routines directly:

* [AllocateAdapterChannelEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel_ex)
* [CancelAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcancel_adapter_channel)
* [CancelMappedTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcancel_mapped_transfer)
* [GetScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list_ex)
* [BuildScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_scatter_gather_list_ex)

You must initialize the DMA transaction before calling **WdfDmaTransactionWdmGetTransferContext**.

## See also

[WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate)