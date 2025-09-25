# IOCTL_PMI_GET_CONFIGURATION IOCTL

## Description

The **IOCTL_PMI_GET_CONFIGURATION** request returns information about the current configuration of a power meter.

## Parameters

### Major code

### Input buffer

The **AssociatedIrp.SystemBuffer** member of the I/O request packet (IRP) points to an initiator-allocated buffer that is used both as the input buffer and the output buffer for the request. On input, this buffer contains a [PMI_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_configuration) structure in which the **Version** and **ConfigurationType** members are set to valid values. The **ConfigurationType** member contains a [PMI_CONFIGURATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_configuration_type) enumeration value that specifies the type of configuration information to be retrieved from the power meter. This value also determines the type of configuration information to be written to the output buffer.

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** member of the IRP's current I/O stack location ([IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)) is set to the size in bytes of the buffer pointed to by the **AssociatedIrp.SystemBuffer** member. This size must be greater than or equal to **sizeof**(**PMI_CONFIGURATION**) or the request will fail with an error status of STATUS_INVALID_PARAMETER.

### Output buffer

If the request completes successfully, the buffer pointed to by the **AssociatedIrp.SystemBuffer** member contains a [PMI_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_configuration) structure. This structure contains the requested configuration information.

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member of the IRP's current I/O stack location is set to the size in bytes of the buffer pointed to by the **AssociatedIrp.SystemBuffer** member. For the request to succeed, this size must be greater than or equal to **sizeof**(**PMI_CONFIGURATION**). Otherwise, the request will fail with an error status of STATUS_BUFFER_TOO_SMALL.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to the size, in bytes, of a [PMI_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_configuration) structure.

The **Status** member is set to one of the following values:

**STATUS_BUFFER_TOO_SMALL**

The **Parameters.DeviceIoControl.OutputBufferLength** member of the [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) is less than the size, in bytes, of a [PMI_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_configuration) structure.

**STATUS_INVALID_PARAMETER**

The initiator-allocated input buffer contains an invalid [PMI_CONFIGURATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_configuration_type) value.

**STATUS_SUCCESS**

The WDM driver that supports the PMI interface has completed the IOCTL request successfully.

## Remarks

The **IOCTL_PMI_GET_CONFIGURATION** request queries the current configuration of the power meter. The input [PMI_CONFIGURATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_configuration_type) enumeration value specifies the type of configuration data to be returned. The data type and contents of the output buffer vary based on the data requested.

The following table describes the type of data that is returned for the specified [PMI_CONFIGURATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_configuration_type) enumeration value.

| PMI_CONFIGURATION_TYPE value | Description |
| --- | --- |
| **PmiBudgetingConfiguration** | A [PMI_BUDGETING_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_budgeting_configuration) structure that contains information about the budgeting configuration of the power meter. |
| **PmiMeasurementConfiguration** | A [PMI_MEASUREMENT_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_measurement_configuration) structure that contains information about the measurement configuration of the power meter. |
| **PmiThresholdConfiguration** | A [PMI_THRESHOLD_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_threshold_configuration) structure that contains information about the threshold configuration of the power meter. |

## See also

[IOCTL_PMI_GET_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_capabilities)

[IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[PMI_BUDGETING_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_budgeting_configuration)

[PMI_CAPABILITIES_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_capabilities_type)

[PMI_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_configuration)

[PMI_CONFIGURATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_configuration_type)

[PMI_MEASUREMENT_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_measurement_configuration)

[PMI_THRESHOLD_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_threshold_configuration)