# _PMI_CONFIGURATION structure

## Description

The PMI_CONFIGURATION structure contains information about the current power metering and budgeting configuration of a power meter.

## Members

### `Version`

A value that specifies the version of this structure. For Windows 7, Windows Server 2008 R2, and later versions of Windows, this value must be 1.

### `Size`

A value, in units of bytes, that specifies the size of the structure.

### `ConfigurationType`

A [PMI_CONFIGURATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_configuration_type) enumeration value that specifies the data type of the **Configuration** member.

### `Configuration`

A union of the supported Power Meter Interface (PMI) configuration structures. Based on the value of the **ConfigurationType** member, one of the following **Configuration** submembers is used to reference the following PMI configuration structures:

### `Configuration.MeasurementConfiguration`

A [PMI_BUDGETING_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_budgeting_configuration) structure that contains information about the budgeting configuration of the power meter.

The **Configuration** member contains this structure if the **ConfigurationType** member is set to **PmiBudgetingConfiguration**.

### `Configuration.BudgetingConfiguration`

A [PMI_MEASUREMENT_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_measurement_configuration) structure that contains information about the measurement configuration of the power meter.

The **Configuration** member contains this structure if the **ConfigurationType** member is set to **PmiMeasurementConfiguration**.

### `Configuration.ThresholdConfiguration`

A [PMI_THRESHOLD_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_threshold_configuration) structure that contains information about the threshold configuration of the power meter.

The **Configuration** member contains this structure if the **ConfigurationType** member is set to **PmiThresoldConfiguration**.

## Remarks

The PMI_CONFIGURATION structure is used to query many different PMI configuration settings that are supported by a power meter.

The PMI configuration information is returned through an [IOCTL_PMI_GET_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_configuration) I/O control (IOCTL) query request. The input data of this query request is set to a [PMI_CONFIGURATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_configuration_type) enumerator value that specifies the type of PMI configuration data to return.

If the IOCTL query request completes successfully, the request returns a PMI_CONFIGURATION structure. The **Configuration** member of this structure contains data that is formatted as the requested PMI configuration structure.

For example, if an IOCTL query request of [IOCTL_PMI_GET_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_configuration) is made with the input data set to **PmiBudgetingConfiguration** and the request completes successfully, the request returns a PMI_CONFIGURATION structure with its members set to the following values:

* The **ConfigurationType** member is set to **PmiBudgetingConfiguration**.
* The **Configuration** member contains data that is formatted as a [PMI_BUDGETING_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_budgeting_configuration) structure.

## See also

[IOCTL_PMI_GET_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_configuration)

[PMI_BUDGETING_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_budgeting_configuration)

[PMI_CONFIGURATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_configuration_type)

[PMI_MEASUREMENT_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_measurement_configuration)

[PMI_THRESHOLD_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_threshold_configuration)