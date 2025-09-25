# SerCx2SystemDmaTransmitInitializeTransactionComplete function

## Description

The **SerCx2SystemDmaTransmitInitializeTransactionComplete** method notifies version 2 of the serial framework extension (SerCx2) that the serial controller driver has finished initializing the serial controller hardware in preparation for a new system-DMA-transmit transaction.

## Parameters

### `SystemDmaTransmit` [in]

A [SERCX2SYSTEMDMATRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a system-DMA-transmit object. The serial controller driver previously called the [SerCx2SystemDmaTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmatransmitcreate) method to create this object.

### `InitSuccess` [in]

Whether the initialization was successful. If **TRUE**, the initialization succeeded. If **FALSE**, the initialization failed.

## Remarks

Before SerCx2 starts a system-DMA-transmit transaction, SerCx2 calls the [EvtSerCx2SystemDmaTransmitInitializeTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_transmit_initialize_transaction) event callback function, if it is implemented, to initialize the serial controller to perform the transaction. In response to this call, the driver should do any initialization that is needed; then the driver must call **SerCx2SystemDmaTransmitInitializeTransactionComplete** to notify SerCx2. SerCx2 expects this notification and does not start the transaction until it is notified.

The serial controller driver must call **SerCx2SystemDmaTransmitInitializeTransactionComplete** only in response to a call to the *EvtSerCx2SystemDmaTransmitInitializeTransaction* function.

For more information, see [SerCx2 System-DMA-Transmit Transaction](https://learn.microsoft.com/previous-versions/dn265338(v=vs.85)).

## See also

[EvtSerCx2SystemDmaTransmitInitializeTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_transmit_initialize_transaction)

[SERCX2SYSTEMDMATRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2SystemDmaTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmatransmitcreate)