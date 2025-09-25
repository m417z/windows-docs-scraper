# _TRANSACTION_OUTCOME enumeration

## Description

The **TRANSACTION_OUTCOME** enumeration defines the outcomes (results) that KTM can assign to a transaction.

## Constants

### `TransactionOutcomeUndetermined`

The transaction has not yet been committed or rolled back.

### `TransactionOutcomeCommitted`

The transaction has been committed.

### `TransactionOutcomeAborted`

The transaction has been rolled back.

## Remarks

The **TRANSACTION_OUTCOME** enumeration is used in the [TRANSACTION_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transaction_basic_information) structure.

## See also

[TRANSACTION_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transaction_basic_information)