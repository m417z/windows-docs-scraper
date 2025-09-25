# SerCx2CustomTransmitTransactionInitializeComplete function

## Description

The **SerCx2CustomTransmitTransactionInitializeComplete** method informs version 2 of the serial framework extension (SerCx2) that the serial driver has finished initializing the serial controller and associated hardware in preparation for a new custom-transmit transaction.

## Parameters

### `CustomTransmitTransaction` [in]

A [SERCX2CUSTOMTRANSMITTRANSACTION](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a custom-transmit object. The serial controller driver previously called the [SerCx2CustomTransmitTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customtransmittransactioncreate) method to create this object.

### `InitSuccess` [in]

Whether the initialization was successful. If **TRUE**, the initialization succeeded. If **FALSE**, the initialization failed.

## Remarks

Before SerCx2 starts a custom-transmit transaction, SerCx2 calls the [EvtSerCx2CustomTransmitTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_custom_transmit_transaction_initialize) event callback function, if it is implemented, to initialize the serial controller to perform the transaction. In response to this call, the driver should first do any initialization that is needed; then the driver must call **SerCx2CustomTransmitTransactionInitializeComplete** to notify SerCx2. SerCx2 expects this notification and does not start the transaction until it is notified.

The serial controller driver must call **SerCx2CustomTransmitTransactionInitializeComplete** only in response to a call to the *EvtSerCx2CustomTransmitTransactionInitialize* function.

For more information, see [SerCx2 Custom-Transmit Transactions](https://learn.microsoft.com/previous-versions/dn265320(v=vs.85)).

## See also

[EvtSerCx2CustomTransmitTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_custom_transmit_transaction_initialize)

[SERCX2CUSTOMTRANSMITTRANSACTION](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2CustomTransmitTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customtransmittransactioncreate)