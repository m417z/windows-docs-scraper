# _TRANSACTION_ENLISTMENT_PAIR structure

## Description

The **TRANSACTION_ENLISTMENT_PAIR** structure contains information about an enlistment that is associated with a [transaction object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-objects).

## Members

### `EnlistmentId`

A GUID that KTM has assigned to the enlistment.

### `ResourceManagerId`

A GUID that KTM has assigned to the resource manager that created the enlistment.

## Remarks

The **TRANSACTION_ENLISTMENT_PAIR** structure is used as a member of the [TRANSACTION_ENLISTMENTS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transaction_enlistments_information) structure.

## See also

[TRANSACTION_ENLISTMENTS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transaction_enlistments_information)

[ZwQueryInformationTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransaction)