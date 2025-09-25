# _TRANSACTION_ENLISTMENTS_INFORMATION structure

## Description

The **TRANSACTION_ENLISTMENTS_INFORMATION** structure contains information about the enlistments that are associated with a [transaction object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-objects).

## Members

### `NumberOfEnlistments`

The number of enlistments that are associated with a transaction object. This is also the number of elements in the array that the **EnlistmentPair** member specifies.

### `EnlistmentPair`

A caller-allocated array of [TRANSACTION_ENLISTMENT_PAIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transaction_enlistment_pair) structures.

## Remarks

The **TRANSACTION_ENLISTMENTS_INFORMATION** structure is used with the [ZwQueryInformationTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransaction) routine. This routine fills in the structure's members.

## See also

[TRANSACTION_ENLISTMENT_PAIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transaction_enlistment_pair)

[TRANSACTION_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_transaction_information_class)

[ZwQueryInformationTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransaction)