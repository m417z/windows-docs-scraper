# EVT_WDF_DMA_TRANSACTION_CONFIGURE_DMA_CHANNEL callback function

## Description

[Applies to KMDF only]

 A driver's *EvtDmaTransactionConfigureDmaChannel* event callback function configures the DMA adapter for a system-mode DMA enabler.

## Parameters

### `DmaTransaction` [in]

A handle to a DMA transaction object representing the transaction that is being executed.

### `Device` [in]

A handle to the framework device object that the driver specified when it called [WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate).

### `Context` [in]

The context pointer that the driver specified in a previous call to [WdfDmaTransactionSetChannelConfigurationCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionsetchannelconfigurationcallback).

### `Mdl` [in, optional]

A pointer to a single memory descriptor list (MDL) or MDL chain that describes the buffer associated with the current transfer, or NULL if the last transfer has been completed and the adapter is being freed.

### `Offset` [in]

A byte offset into the buffer specified in the *Mdl* parameter where the current transfer starts.

### `Length` [in]

The number of bytes being transferred in the current transfer.

## Return value

The *EvtDmaTransactionConfigureDmaChannel* callback function returns TRUE if it successfully configures the DMA channel. If this callback function returns FALSE, the framework stops the transaction and does not call [EvtProgramDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_program_dma).

## Remarks

Drivers register an *EvtDmaTransactionConfigureDmaChannel* event callback function by calling [WdfDmaTransactionSetChannelConfigurationCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionsetchannelconfigurationcallback).

The framework calls *EvtDmaTransactionConfigureDmaChannel* once for each system-profile DMA transfer in the transaction, after allocating the adapter channel but before mapping the transfer and calling [EvtProgramDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_program_dma).

The driver can use the *EvtDmaTransactionConfigureDmaChannel* callback to set any custom programming for the DMA adapter before mapping a transfer.

If the driver experiences an error while configuring the channel, it can stop the DMA transfer by calling [WdfDmaTransactionDmaCompletedFinal](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompletedfinal) and, if necessary, completing the request. The driver should then return FALSE from this callback function.

## See also

[WdfDmaTransactionDmaCompletedFinal](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompletedfinal)

[WdfDmaTransactionSetChannelConfigurationCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionsetchannelconfigurationcallback)