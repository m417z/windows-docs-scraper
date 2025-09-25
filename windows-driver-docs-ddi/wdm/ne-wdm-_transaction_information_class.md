# _TRANSACTION_INFORMATION_CLASS enumeration

## Description

The **TRANSACTION_INFORMATION_CLASS** enumeration specifies the type of information that [ZwSetInformationTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntsetinformationtransaction) can set and [ZwQueryInformationTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransaction) can retrieve for a [transaction manager object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-manager-objects).

## Constants

### `TransactionBasicInformation`

Information about a transaction manager object is stored in a [TRANSACTION_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transaction_basic_information) structure.

### `TransactionPropertiesInformation`

Information about a transaction manager object is stored in a [TRANSACTION_PROPERTIES_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transaction_properties_information) structure.

### `TransactionEnlistmentInformation`

Information about a transaction manager object is stored in a [TRANSACTION_ENLISTMENTS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transaction_enlistments_information) structure.

### `TransactionSuperiorEnlistmentInformation`

Information about a transaction manager object is stored in a **TRANSACTION_SUPERIOR_ENLISTMENT_INFORMATION** structure.

## See also

[ZwQueryInformationTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransaction)

[ZwSetInformationTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntsetinformationtransaction)