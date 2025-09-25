# _TRANSACTIONMANAGER_LOG_INFORMATION structure

## Description

The **TRANSACTIONMANAGER_LOG_INFORMATION** structure contains information about a [transaction manager object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-manager-objects).

## Members

### `LogIdentity`

A GUID that KTM uses to identify restart records in a transaction manager object's log stream. For more information about restart records, see [Writing Restart Records to a CLFS Stream](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-restart-records-to-a-clfs-stream).

## Remarks

The **TRANSACTIONMANAGER_LOG_INFORMATION** structure is used with the [ZwQueryInformationTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransactionmanager) routine.

## See also

[TRANSACTIONMANAGER_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_transactionmanager_information_class)

[ZwQueryInformationTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransactionmanager)