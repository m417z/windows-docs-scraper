# _TRANSACTIONMANAGER_BASIC_INFORMATION structure

## Description

The **TRANSACTIONMANAGER_BASIC_INFORMATION** structure contains information about a [transaction manager object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-manager-objects).

## Members

### `TmIdentity`

A GUID that KTM has assigned to a transaction manager object.

### `VirtualClock`

The [virtual clock value](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-virtual-clock-values) that is currently associated with a transaction manager object.

## Remarks

The **TRANSACTIONMANAGER_BASIC_INFORMATION** structure is used with the [ZwQueryInformationTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransactionmanager) routine.

## See also

[TRANSACTIONMANAGER_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_transactionmanager_information_class)

[ZwQueryInformationTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransactionmanager)