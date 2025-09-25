# CrmTransactionState enumeration

## Description

Represents the current transaction state of the transaction.

## Constants

### `TxState_Active:0`

The transaction is active.

### `TxState_Committed`

The transaction is committed.

### `TxState_Aborted`

The transaction was aborted.

### `TxState_Indoubt`

The transaction is in doubt.

## See also

[ICrmMonitorLogRecords::get_TransactionState](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-icrmmonitorlogrecords-get_transactionstate)