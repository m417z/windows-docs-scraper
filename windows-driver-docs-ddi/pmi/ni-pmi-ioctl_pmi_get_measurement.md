# IOCTL_PMI_GET_MEASUREMENT IOCTL

## Description

The **IOCTL_PMI_GET_MEASUREMENT** request returns the current measurement data from a power meter.

## Parameters

### Major code

### Input buffer

The initiator-allocated output buffer that is pointed to by the **AssociatedIrp.SystemBuffer** member of the IRP.

### Input buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member of the IRP's current I/O stack location ([IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)) is set to the size in bytes of the initiator-allocated output buffer that is pointed to by the **AssociatedIrp.SystemBuffer** member of the IRP. This size must be greater than or equal to **sizeof**([PMI_MEASUREMENT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_measurement_data)) or the request fails with an error status of STATUS_BUFFER_TOO_SMALL.

### Output buffer

If the request completes successfully, the output buffer pointed to by the **AssociatedIrp.SystemBuffer** member contains a [PMI_MEASUREMENT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_measurement_data) structure. This structure contains the requested measurement data.

### Output buffer length

The size of a [PMI_MEASUREMENT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_measurement_data) structure.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to the size, in bytes, of a [PMI_MEASUREMENT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_measurement_data) structure.

The **Status** member is set to one of the following values:

**STATUS_BUFFER_TOO_SMALL**

The **Parameters.DeviceIoControl.OutputBufferLength** member of the [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) is less than the size, in bytes, of a [PMI_MEASUREMENT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_measurement_data) structure.

**STATUS_SUCCESS**

The WDM driver that supports the PMI interface has completed the IOCTL request successfully.

## Remarks

The **IOCTL_PMI_GET_MEASUREMENT** request queries the current measurement data from the power meter. This measurement data is sampled and averaged based on the power meter's measurement configuration parameters. The measurement configuration parameters are queried through the [IOCTL_PMI_GET_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_configuration) request with an input [PMI_CONFIGURATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_configuration_type) value of **PmiMeasurementConfiguration**.

## See also

[IOCTL_PMI_GET_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_capabilities)

[IOCTL_PMI_GET_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_configuration)

[IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[PMI_CONFIGURATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_configuration_type)

[PMI_MEASUREMENT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_measurement_data)