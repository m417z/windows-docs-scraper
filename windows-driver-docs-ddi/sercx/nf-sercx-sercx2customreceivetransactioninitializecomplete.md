# SerCx2CustomReceiveTransactionInitializeComplete function

## Description

The **SerCx2CustomReceiveTransactionInitializeComplete** method notifies version 2 of the serial framework extension (SerCx2) that the serial controller driver has finished initializing the serial controller and associated hardware in preparation for a new custom-receive transaction.

## Parameters

### `CustomReceiveTransaction` [in]

A [SERCX2CUSTOMRECEIVETRANSACTION](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a custom-receive object. The serial controller driver previously called the [SerCx2CustomReceiveTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivetransactioncreate) method to create this object.

### `InitSuccess` [in]

Whether the initialization was successful. If **TRUE**, the initialization succeeded. If **FALSE**, the initialization failed.

## Remarks

Before SerCx2 starts a custom-receive transaction, SerCx2 calls the [EvtSerCx2CustomReceiveTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_custom_receive_transaction_initialize) event callback function, if it is implemented, to initialize the serial controller to perform the transaction. In response to this call, the driver should first do any initialization that is needed; then the driver must call **SerCx2CustomReceiveTransactionInitializeComplete** to notify SerCx2. SerCx2 expects this notification and does not start the transaction until it is notified.

The serial controller driver must call **SerCx2CustomReceiveTransactionInitializeComplete** only in response to a call to the *EvtSerCx2CustomReceiveTransactionInitialize* function.

For more information, see [SerCx2 Custom-Receive Transactions](https://learn.microsoft.com/previous-versions/dn265314(v=vs.85)).

## See also

[EvtSerCx2CustomReceiveTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_custom_receive_transaction_initialize)

[SERCX2CUSTOMRECEIVETRANSACTION](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2CustomReceiveTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivetransactioncreate)