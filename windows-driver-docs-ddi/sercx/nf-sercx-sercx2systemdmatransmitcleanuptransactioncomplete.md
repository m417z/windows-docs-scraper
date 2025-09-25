# SerCx2SystemDmaTransmitCleanupTransactionComplete function

## Description

The **SerCx2SystemDmaTransmitCleanupTransactionComplete** method notifies version 2 of the serial framework extension (SerCx2) that the serial controller driver has finished cleaning up the serial controller's hardware state after a system-DMA-transmit transaction.

## Parameters

### `SystemDmaTransmit` [in]

A [SERCX2SYSTEMDMATRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a system-DMA-transmit object. The serial controller driver previously called the [SerCx2SystemDmaTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmatransmitcreate) method to create this object.

## Remarks

After a system-DMA-transmit transaction ends, SerCx2 calls the [EvtSerCx2SystemDmaTransmitCleanupTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_transmit_cleanup_transaction) event callback function, if it is implemented, to clean up the serial controller state. In response to this call, the driver should do any clean-up work that is needed; then the driver must call **SerCx2SystemDmaTransmitCleanupTransactionComplete** to notify SerCx2. SerCx2 expects this notification and does not start the next transaction until it is notified.

The serial controller driver must call **SerCx2SystemDmaTransmitCleanupTransactionComplete** only in response to a call to the *EvtSerCx2SystemDmaTransmitCleanupTransaction* function.

For more information, see [SerCx2 System-DMA-Transmit Transaction](https://learn.microsoft.com/previous-versions/dn265338(v=vs.85)).

## See also

[EvtSerCx2SystemDmaTransmitCleanupTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_transmit_cleanup_transaction)

[SERCX2SYSTEMDMATRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2SystemDmaTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmatransmitcreate)