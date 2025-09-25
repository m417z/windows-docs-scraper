# SerCx2CustomReceiveTransactionReportProgress function

## Description

The **SerCx2CustomReceiveTransactionReportProgress** method reports whether progress is being made toward completing the current custom-receive transaction.

## Parameters

### `CustomReceiveTransaction`

A [**SERCX2CUSTOMRECEIVETRANSACTION**](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a custom-receive object. The serial controller driver previously called the [**SerCx2CustomReceiveTransactionCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivetransactioncreate) method to create this object.

### `Progress` [in]

Whether progress is being made toward completing the custom-receive transaction. Set this parameter to one of the following enumeration constants:

* SERCX2_CUSTOM_RECEIVE_NO_PROGRESS
* SERCX2_CUSTOM_RECEIVE_BYTES_TRANSFERRED

For more information about these enumeration constants, see [SERCX2_CUSTOM_RECEIVE_TRANSACTION_PROGRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ne-sercx-_sercx2_custom_receive_transaction_progress).

## Remarks

To determine whether the serial controller is making progress toward completing the current custom-receive transaction, SerCx2 periodically calls the [EvtSerCx2CustomReceiveTransactionQueryProgress](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn265203(v=vs.85)) event callback function. In response to this call, the serial controller driver calls **SerCx2CustomReceiveTransactionReportProgress** to provide a progress report.

Each **SerCx2CustomReceiveTransactionReportProgress** call reports whether any data bytes have been transferred in the current custom-receive transaction since either the previous call to this method or the start of the transaction, whichever is more recent. If one or more bytes have been transferred, the call reports that the serial controller is making progress. If no bytes have been transferred, the call reports that there is no progress.

The serial controller driver must call this method only in response to a call from SerCx2 to the *EvtSerCx2CustomReceiveTransactionQueryProgress* function.

For more information, see [SerCx2 Custom-Receive Transactions](https://learn.microsoft.com/previous-versions/dn265314(v=vs.85)).

## See also

[EvtSerCx2CustomReceiveTransactionQueryProgress](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn265203(v=vs.85))

[SERCX2CUSTOMRECEIVETRANSACTION](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SERCX2_CUSTOM_RECEIVE_TRANSACTION_PROGRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ne-sercx-_sercx2_custom_receive_transaction_progress)

[SerCx2CustomReceiveTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivetransactioncreate)