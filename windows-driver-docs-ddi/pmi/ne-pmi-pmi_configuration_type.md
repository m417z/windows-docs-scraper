# PMI_CONFIGURATION_TYPE enumeration

## Description

The PMI_CONFIGURATION_TYPE enumeration defines the type of PMI configuration data that is referenced by the **Configuration** member of the [PMI_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_configuration) structure. This enumeration is also used to specify the type of [PMI_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_capabilities) structure to return through an [IOCTL_PMI_GET_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_configuration) I/O control (IOCTL) request.

## Constants

### `PmiMeasurementConfiguration`

The PMI configuration data, formatted as a [PMI_MEASUREMENT_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_measurement_configuration) structure, contains information about the measurement configuration of the power meter.

### `PmiBudgetingConfiguration`

The PMI configuration data, formatted as a [PMI_BUDGETING_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_budgeting_configuration) structure, contains information about the budgeting configuration of the power meter.

### `PmiThresholdConfiguration`

The PMI configuration data, formatted as a [PMI_THRESHOLD_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_threshold_configuration) structure, contains information about the budgeting configuration of the power meter.

### `PmiConfigurationMax`

The maximum number of PMI configuration structures.

## Remarks

The **ConfigurationType** member of the [PMI_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_configuration) structure contains information about the type of PMI configuration data that is referenced by the **Configuration** member of that structure. This structure is returned through a successful completion of an [IOCTL_PMI_GET_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_configuration) IOCTL request and is passed in the input buffer for an [IOCTL_PMI_SET_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_set_configuration) IOCTL request.

## See also

[IOCTL_PMI_GET_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_configuration)

[IOCTL_PMI_SET_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_set_configuration)

[PMI_BUDGETING_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_budgeting_configuration)

[PMI_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_configuration)

[PMI_MEASUREMENT_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_measurement_configuration)

[PMI_THRESHOLD_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_threshold_configuration)