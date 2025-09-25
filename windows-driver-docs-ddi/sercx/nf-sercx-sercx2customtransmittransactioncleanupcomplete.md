# SerCx2CustomTransmitTransactionCleanupComplete function

## Description

The **SerCx2CustomTransmitTransactionCleanupComplete** method notifies version 2 of the serial framework extension (SerCx2) that the serial controller driver has finished cleaning up the serial controller's hardware state after a custom-transmit transaction.

## Parameters

### `CustomTransmitTransaction` [in]

A [SERCX2CUSTOMTRANSMITTRANSACTION](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a custom-transmit object. The serial controller driver previously called the [SerCx2CustomTransmitTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customtransmittransactioncreate) method to create this object.

## Remarks

After a custom-transmit transaction ends, SerCx2 calls the [EvtSerCx2CustomTransmitTransactionCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_custom_transmit_transaction_cleanup) event callback function, if it is implemented, to clean up the serial controller state. In response to this call, the driver should first do any clean-up work that is needed; then the driver must call **SerCx2CustomTransmitTransactionCleanupComplete** to notify SerCx2. SerCx2 expects this notification and does not start the next transaction until it is notified.

A serial controller driver must call **SerCx2CustomTransmitTransactionCleanupComplete** only in response to a call to the *EvtSerCx2CustomTransmitTransactionCleanup* function.

For more information, see [SerCx2 Custom-Transmit Transactions](https://learn.microsoft.com/previous-versions/dn265320(v=vs.85)).

## See also

[EvtSerCx2CustomTransmitTransactionCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_custom_transmit_transaction_cleanup)

[SERCX2CUSTOMTRANSMITTRANSACTION](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2CustomTransmitTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customtransmittransactioncreate)