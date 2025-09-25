# WdfDmaTransactionSetChannelConfigurationCallback function

## Description

[Applies to KMDF only]

 The **WdfDmaTransactionSetChannelConfigurationCallback** method registers a channel configuration event callback function for a system-mode DMA transaction.

## Parameters

### `DmaTransaction` [in]

A handle to an initialized DMA transaction object for which to set or clear the channel configuration callback.

### `ConfigureRoutine` [in, optional]

A pointer to the driver's [EvtDmaTransactionConfigureDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_dma_transaction_configure_dma_channel) event callback function, or NULL to clear it.

### `ConfigureContext` [in, optional]

A pointer to a buffer containing the context to be provided to the driver's [EvtDmaTransactionConfigureDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_dma_transaction_configure_dma_channel) event callback function, or NULL.

## Remarks

This method allows the driver to customize the adapter configuration before programming the system DMA controller.

Typically from within an [I/O queue event callback function](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-handlers), a driver performs the following steps, in this order:

1. Calls [WdfDmaTransactionInitializeUsingRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitializeusingrequest), [WdfDmaTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitialize), or [WdfDmaTransactionInitializeUsingOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitializeusingoffset) to initialize the transaction object.
2. Calls **WdfDmaTransactionSetChannelConfigurationCallback** on the transaction object.
3. Calls [WdfDmaTransactionExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionexecute).

If the driver has specified an [EvtDmaTransactionConfigureDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_dma_transaction_configure_dma_channel) event callback function by calling **WdfDmaTransactionSetChannelConfigurationCallback** and the driver subsequently calls [WdfDmaTransactionRelease](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionrelease), the callback is cleared.

**WdfDmaTransactionSetChannelConfigurationCallback** must be used with a DMA enabler that specifies a system-mode DMA profile.

If your driver calls this method on an operating system earlier than Windows 8, [the framework's verifier](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-kmdf-verifier) reports an error.

## See also

[EvtDmaTransactionConfigureDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_dma_transaction_configure_dma_channel)

[WdfDmaTransactionRelease](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionrelease)