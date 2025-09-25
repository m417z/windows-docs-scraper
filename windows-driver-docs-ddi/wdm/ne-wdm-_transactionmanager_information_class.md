# _TRANSACTIONMANAGER_INFORMATION_CLASS enumeration

## Description

The **TRANSACTIONMANAGER_INFORMATION_CLASS** enumeration specifies the type of information that the [ZwQueryInformationTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransactionmanager) routine can retrieve for a [transaction manager object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-manager-objects).

## Constants

### `TransactionManagerBasicInformation`

Information about a transaction manager object is stored in a [TRANSACTIONMANAGER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transactionmanager_basic_information) structure.

### `TransactionManagerLogInformation`

Information about a transaction manager object is stored in a [TRANSACTIONMANAGER_LOG_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transactionmanager_log_information) structure.

### `TransactionManagerLogPathInformation`

Information about a transaction manager object is stored in a [TRANSACTIONMANAGER_LOGPATH_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transactionmanager_logpath_information) structure.

### `TransactionManagerRecoveryInformation`

Information about a transaction manager object is stored in a [TRANSACTIONMANAGER_RECOVERY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transactionmanager_recovery_information) structure.

## See also

[TRANSACTIONMANAGER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transactionmanager_basic_information)

[TRANSACTIONMANAGER_LOGPATH_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transactionmanager_logpath_information)

[TRANSACTIONMANAGER_LOG_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transactionmanager_log_information)

[ZwQueryInformationTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransactionmanager)