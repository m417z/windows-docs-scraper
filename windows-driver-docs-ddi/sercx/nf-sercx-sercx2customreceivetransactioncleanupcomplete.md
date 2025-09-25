# SerCx2CustomReceiveTransactionCleanupComplete function

## Description

The **SerCx2CustomReceiveTransactionCleanupComplete** method informs version 2 of the serial framework extension (SerCx2) that the serial controller driver has finished cleaning up the serial controller's hardware state after a custom-receive transaction.

## Parameters

### `CustomReceiveTransaction` [in]

A [SERCX2CUSTOMRECEIVETRANSACTION](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a custom-receive object. The serial controller driver previously called the [SerCx2CustomReceiveTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivetransactioncreate) method to create this object.

## Remarks

After a custom-receive transaction ends, SerCx2 calls the [EvtSerCx2CustomReceiveTransactionCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_custom_receive_transaction_cleanup) event callback function, if it is implemented, to clean up the serial controller state. In response to this call, the driver should first do any clean-up work that is needed; then the driver must call **SerCx2CustomReceiveTransactionCleanupComplete** to notify SerCx2. SerCx2 expects this notification and does not start the next transaction until it is notified.

The serial controller driver must call **SerCx2CustomReceiveTransactionCleanupComplete** only in response to a call to the *EvtSerCx2CustomReceiveTransactionCleanup* function.

For more information, see [SerCx2 Custom-Receive Transactions](https://learn.microsoft.com/previous-versions/dn265314(v=vs.85)).

## See also

[EvtSerCx2CustomReceiveTransactionCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_custom_receive_transaction_cleanup)

[SERCX2CUSTOMRECEIVETRANSACTION](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2CustomReceiveTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivetransactioncreate)