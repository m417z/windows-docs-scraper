# _PMI_BUDGETING_CONFIGURATION structure

## Description

The PMI_BUDGETING_CONFIGURATION structure contains information about the current power budget of a power meter. A power budget defines how much power that the system can consume from the set of power supplies monitored by the power meter.

## Members

### `ConfiguredBudget`

A value, in units of milliwatts (mW), that specifies the current power budget. A value of zero indicates that the power budget is not enabled on the power meter.

## Remarks

The PMI_BUDGETING_CONFIGURATION structure is returned through an [IOCTL_PMI_GET_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_configuration) I/O control (IOCTL) query request. This query request has its input data set to a [PMI_CONFIGURATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_configuration_type) enumerator value of **PmiBudgetingConfiguration**.

If the IOCTL query request completes successfully, the request returns a [PMI_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_configuration) structure with its **Capabilities** member formatted as a PM_BUDGETING_CONFIGURATION structure.

Unlike other PMI capability or configuration data, the power meter's current budgeting configuration can be changed. This is only possible if an IOCTL query request of [IOCTL_PMI_GET_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_capabilities) returns a [PMI_REPORTED_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_reported_capabilities) structure with the **Writeable** member set to **TRUE**. In this case, the budgeting configuration for the power meter can be changed through a set request of [IOCTL_PMI_SET_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_set_configuration).

## See also

[IOCTL_PMI_GET_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_capabilities)

[IOCTL_PMI_GET_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_configuration)

[IOCTL_PMI_SET_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_set_configuration)

[PMI_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_configuration)

[PMI_CONFIGURATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_configuration_type)

[PMI_REPORTED_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_reported_capabilities)