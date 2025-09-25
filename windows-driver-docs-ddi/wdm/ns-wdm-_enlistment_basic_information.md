# _ENLISTMENT_BASIC_INFORMATION structure

## Description

The **ENLISTMENT_BASIC_INFORMATION** structure contains information about an [enlistment object](https://learn.microsoft.com/windows-hardware/drivers/kernel/enlistment-objects).

## Members

### `EnlistmentId`

A GUID that KTM has assigned to the enlistment object.

### `TransactionId`

A GUID that KTM has assigned to the transaction object that is associated with the enlistment object that the **EnlistmentId** member identifies.

### `ResourceManagerId`

A GUID that KTM has assigned to the resource manager that created the enlistment.

## Remarks

The **ENLISTMENT_BASIC INFORMATION** structure is used with the [ZwQueryInformationEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationenlistment) routine.

## See also

[ENLISTMENT_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_enlistment_information_class)

[ZwQueryInformationEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationenlistment)