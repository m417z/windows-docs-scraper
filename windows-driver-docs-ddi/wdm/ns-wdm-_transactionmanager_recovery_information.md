# _TRANSACTIONMANAGER_RECOVERY_INFORMATION structure

## Description

The TRANSACTIONMANAGER_RECOVERY_INFORMATION structure contains information about a [transaction manager object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-manager-objects).

## Members

### `LastRecoveredLsn`

The last [log sequence number](https://learn.microsoft.com/windows-hardware/drivers/kernel/clfs-log-sequence-numbers) of the last log record that KTM obtained from [CLFS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system) during the most recent recovery operation.

## Remarks

The TRANSACTIONMANAGER_RECOVERY_INFORMATION structure is used with the [ZwQueryInformationTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransactionmanager) routine.

## See also

[TRANSACTIONMANAGER_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_transactionmanager_information_class)

[ZwQueryInformationTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransactionmanager)