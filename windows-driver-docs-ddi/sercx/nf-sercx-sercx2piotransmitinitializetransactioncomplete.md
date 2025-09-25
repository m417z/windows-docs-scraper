# SerCx2PioTransmitInitializeTransactionComplete function

## Description

The **SerCx2PioTransmitInitializeTransactionComplete** method notifies version 2 of the serial framework extension (SerCx2) that the serial controller driver has finished initializing the serial controller hardware in preparation for a new PIO-transmit transaction.

## Parameters

### `PioTransmit` [in]

A [SERCX2PIOTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a PIO-transmit object. The serial controller driver previously called the [SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate) method to create this object.

### `InitSuccess` [in]

Whether the initialization was successful. If **TRUE**, the initialization succeeded. If **FALSE**, the initialization failed.

## Remarks

Before SerCx2 initiates a PIO-transmit transaction, SerCx2 calls the [EvtSerCx2PioTransmitInitializeTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_initialize_transaction) event callback function, if it is implemented, to initialize the serial controller to perform the transaction. In response to this call, the driver should first do any initialization that is needed; then the driver must call **SerCx2PioTransmitInitializeTransactionComplete** to notify SerCx2. SerCx2 expects this notification and does not start the transaction until it is notified.

The serial controller driver must call **SerCx2PioTransmitInitializeTransactionComplete** only in response to a call to the *EvtSerCx2PioTransmitInitializeTransaction* function.

For more information, see [SerCx2 PIO-Transmit Transactions](https://learn.microsoft.com/previous-versions/dn265336(v=vs.85)).

## See also

[EvtSerCx2PioTransmitInitializeTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_initialize_transaction)

[SERCX2PIOTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate)