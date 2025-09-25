# _TRANSACTIONMANAGER_LOGPATH_INFORMATION structure

## Description

The **TRANSACTIONMANAGER_LOGPATH_INFORMATION** structure contains information about a [transaction manager object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-manager-objects).

## Members

### `LogPathLength`

The number of elements in the **LogPath** member's character array.

### `LogPath`

A caller-allocated character array that receives the path and file name of the [log file stream](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-log-streams-with-ktm) that is associated with a transaction manager.

## Remarks

The **TRANSACTIONMANAGER_LOGPATH_INFORMATION** structure is used with the [ZwQueryInformationTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransactionmanager) routine.

## See also

[TRANSACTIONMANAGER_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_transactionmanager_information_class)

[ZwQueryInformationTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransactionmanager)