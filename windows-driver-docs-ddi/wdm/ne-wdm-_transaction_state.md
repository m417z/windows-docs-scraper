# _TRANSACTION_STATE enumeration

## Description

The **TRANSACTION_STATE** enumeration defines the states that KTM can assign to a transaction.

## Constants

### `TransactionStateNormal`

The transaction's state is neither in doubt nor committed.

### `TransactionStateIndoubt`

The transaction's state is in doubt (that is, KTM cannot determine whether the transaction should be committed or rolled back). A transaction that has been prepared enters the "in doubt" state if its [superior transaction manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-superior-transaction-manager) becomes unavailable.

### `TransactionStateCommittedNotify`

The transaction has been committed. Commit notifications might (or might not) have been delivered to all enlistments.

## Remarks

The **TRANSACTION_STATE** enumeration is used in the [TRANSACTION_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transaction_basic_information) structure.

## See also

[TRANSACTION_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transaction_basic_information)