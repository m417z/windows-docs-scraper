# SerCx2CustomReceiveTransactionNewDataNotification function

## Description

The **SerCx2CustomReceiveTransactionNewDataNotification** method notifies version 2 of the serial framework extension (SerCx2) that data is available to be read from the receive FIFO in the serial controller hardware.

## Parameters

### `CustomReceiveTransaction` [in]

A [SERCX2CUSTOMRECEIVETRANSACTION](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a custom-receive object. The serial controller driver previously called the [SerCx2CustomReceiveTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivetransactioncreate) method to create this object.

## Remarks

If the receive FIFO in the serial controller becomes empty before a custom-receive transaction can be completed, SerCx2 calls the [EvtSerCx2CustomReceiveTransactionEnableNewDataNotification](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn265201(v=vs.85)) event callback function, if it is implemented, to enable a new-data notification to occur when new data is available to be read from the receive FIFO.

If new-data notifications are enabled and new data is available to be read, the serial controller driver must call **SerCx2CustomReceiveTransactionNewDataNotification** to notify SerCx2. This notification occurs when the driver detects that one or more new bytes of received data either are ready to be transferred by the custom data-transfer mechanism or have already been transferred by this mechanism.

The serial controller driver must call **SerCx2CustomReceiveTransactionNewDataNotification** only in response to a call to the *EvtSerCx2CustomReceiveTransactionEnableNewDataNotification* function.

If a serial controller driver supports new-data notifications for custom-receive transactions, SerCx uses these notifications to detect interval time-outs during the handling of read ([IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read)) requests. For more information about interval time-outs, see [SERIAL_TIMEOUTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_timeouts). For more information about new-data notifications, see [SerCx2 Custom-Receive Transactions](https://learn.microsoft.com/previous-versions/dn265314(v=vs.85)).

## See also

[EvtSerCx2CustomReceiveTransactionEnableNewDataNotification](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn265201(v=vs.85))

[IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read)

[SERCX2CUSTOMRECEIVETRANSACTION](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SERIAL_TIMEOUTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_timeouts)

[SerCx2CustomReceiveTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivetransactioncreate)