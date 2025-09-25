# WdfDmaTransactionSetSingleTransferRequirement function

## Description

[Applies to KMDF only]

The **WdfDmaTransactionSetSingleTransferRequirement** method specifies that a DMA transaction must complete in a single transfer.

## Parameters

### `DmaTransaction` [in]

A handle to a DMA transaction object that the driver obtained from a previous call to [WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate).

### `RequireSingleTransfer` [in]

A Boolean value that, if **TRUE**, specifies that the DMA transaction requires a single transfer.

## Remarks

This method requests a single transfer for a single transaction only. When the transaction object is recycled with [WdfDmaTransactionRelease](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionrelease) and reinitialized, this setting resets, similar to other transaction-level properties such as immediate execution and maximum transfer length.

To request single transfer for all DMA transactions created with a given DMA enabler, specify **WDF_DMA_ENABLER_CONFIG_REQUIRE_SINGLE_TRANSFER** in [WDF_DMA_ENABLER_CONFIG_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ne-wdfdmaenabler-_wdf_dma_enabler_config_flags) when calling [WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate). This is equivalent to calling **WdfDmaTransactionSetSingleTransferRequirement** for each transaction object created with the DMA enabler.

The driver calls **WdfDmaTransactionSetSingleTransferRequirement** after creating or recycling the transaction object, but before initializing or executing it. For more info, see [Using Single Transfer DMA](https://learn.microsoft.com/windows-hardware/drivers/wdf/).

**WdfDmaTransactionSetSingleTransferRequirement** requires DMA version 3.
To select DMA version 3, set the **WdmDmaVersionOverride** member of [WDF_DMA_ENABLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config) to 3.

## See also

[WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate)

[WdfDmaTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitialize)

[WdfDmaTransactionInitializeUsingRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitializeusingrequest)