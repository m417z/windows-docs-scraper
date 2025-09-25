# SerCx2PioTransmitCleanupTransactionComplete function

## Description

The **SerCx2PioTransmitCleanupTransactionComplete** method notifies version 2 of the serial framework extension (SerCx2) that serial controller driver has finished cleaning up the serial controller's hardware state after a PIO-transmit transaction.

## Parameters

### `PioTransmit` [in]

A [SERCX2PIOTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a PIO-transmit object. The serial controller driver previously called the [SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate) method to create this object.

## Remarks

After a PIO-transmit transaction ends, SerCx2 calls the [EvtSerCx2PioTransmitCleanupTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_cleanup_transaction) event callback function, if it is implemented, to clean up the serial controller state. In response to this call, the driver should first do any clean-up work that is needed; then the driver must call **SerCx2PioTransmitCleanupTransactionComplete** to notify SerCx2. SerCx2 waits for this notification to start the next transaction.

The serial must call **SerCx2PioTransmitCleanupTransactionComplete** only in response to a call to the *EvtSerCx2PioTransmitCleanupTransaction* function.

For more information, see [SerCx2 PIO-Transmit Transactions](https://learn.microsoft.com/previous-versions/dn265336(v=vs.85)).

## See also

[EvtSerCx2PioTransmitCleanupTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_cleanup_transaction)

[SERCX2PIOTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate)