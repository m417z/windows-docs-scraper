# _ENLISTMENT_INFORMATION_CLASS enumeration

## Description

The **ENLISTMENT_INFORMATION_CLASS** enumeration identifies the type of information that the [ZwSetInformationEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntsetinformationenlistment) routine can set and that the [ZwQueryInformationEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationenlistment) routine can retrieve for an [enlistment object](https://learn.microsoft.com/windows-hardware/drivers/kernel/enlistment-objects).

## Constants

### `EnlistmentBasicInformation`

Information about an enlistment object is stored in an [ENLISTMENT_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_enlistment_basic_information) structure.

### `EnlistmentRecoveryInformation`

A resource manager is setting or obtaining customized recovery information for an enlistment. To learn more about recovery information, see [ZwSetInformationEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntsetinformationenlistment).

### `EnlistmentCrmInformation`

Information about an enlistment object is stored in an **ENLISTMENT_CRM_INFORMATION** structure.

## See also

[ENLISTMENT_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_enlistment_basic_information)

[ZwQueryInformationEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationenlistment)

[ZwSetInformationEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntsetinformationenlistment)