# SerCx2PioReceiveInitializeTransactionComplete function

## Description

The **SerCx2PioReceiveInitializeTransactionComplete** method notifies version 2 of the serial framework extension (SerCx2) that the serial driver has finished initializing the serial controller hardware in preparation for a new PIO-receive transaction.

## Parameters

### `PioReceive` [in]

A [SERCX2PIORECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a PIO-receive object. The serial controller driver previously called the [SerCx2PioReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2pioreceivecreate) method to create this object.

### `InitSuccess` [in]

Whether the initialization was successful. If **TRUE**, the initialization succeeded. If **FALSE**, the initialization failed.

## Remarks

Before SerCx2 starts a PIO-receive transaction, SerCx2 calls the [EvtSerCx2PioReceiveInitializeTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_initialize_transaction) event callback function, if it is implemented, to initialize the serial controller hardware. In response to this call, the driver should first do any initialization that is needed; then the driver must call **SerCx2PioReceiveInitializeTransactionComplete** to notify SerCx2. SerCx2 expects this notification and does not start the transaction until it is notified.

The serial controller driver must call **SerCx2PioReceiveInitializeTransactionComplete** only in response to a call to the *EvtSerCx2PioReceiveInitializeTransaction* function.

For more information, see [SerCx2 PIO-Receive Transactions](https://learn.microsoft.com/previous-versions/dn265332(v=vs.85)).

## See also

[EvtSerCx2PioReceiveInitializeTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_initialize_transaction)

[SERCX2PIORECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2PioReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2pioreceivecreate)