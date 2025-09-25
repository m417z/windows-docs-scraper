# _SERCX2_CUSTOM_RECEIVE_TRANSACTION_PROGRESS enumeration

## Description

The **SERCX2_CUSTOM_RECEIVE_TRANSACTION_PROGRESS** enumeration defines constants that indicate whether process is being made toward completing a custom-receive transaction.

## Constants

### `SerCx2CustomReceiveTransactionNoProgress`

No progress is being made. This value indicates that no data bytes have been transferred in the current custom-receive transaction since either the previous progress report or the start of the transaction, whichever is more recent.

### `SerCx2CustomReceiveTransactionBytesTransferred`

Progress is being made. This value indicates that one or more bytes of data have been transferred in the current custom-receive transaction since either the previous progress report or the start of the transaction, whichever is more recent.

## Remarks

The constants in this enumeration are used by the [SerCx2CustomReceiveTransactionReportProgress](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivetransactionreportprogress) method.

## See also

[SerCx2CustomReceiveTransactionReportProgress](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivetransactionreportprogress)