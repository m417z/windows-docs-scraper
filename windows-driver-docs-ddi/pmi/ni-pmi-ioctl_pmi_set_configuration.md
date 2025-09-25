# IOCTL_PMI_SET_CONFIGURATION IOCTL

## Description

The **IOCTL_PMI_SET_CONFIGURATION** request sets the configuration data for a power meter.

## Parameters

### Major code

### Input buffer

The **AssociatedIrp.SystemBuffer** member of the I/O request packet (IRP) points to an initiator-allocated input buffer that contains a [PMI_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_configuration) structure. This structure contains the configuration data.

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** member of the IRP's current I/O stack location ([IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)) is set to the size in bytes of the input buffer that is pointed to by the **AssociatedIrp.SystemBuffer** member. This size must be greater than or equal to **sizeof**(**PMI_CONFIGURATION**) or the request fails with an error status of STATUS_BUFFER_TOO_SMALL.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to the size, in bytes, of a [PMI_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_configuration) structure.

The **Status** member is set to one of the following values:

**STATUS_BUFFER_TOO_SMALL**

The **Parameters.DeviceIoControl.OutputBufferLength** member of the [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) is less than the size, in bytes, of a [PMI_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_configuration) structure.

**STATUS_SUCCESS**

The WDM driver that supports the PMI interface has completed the IOCTL request successfully.

## Remarks

The **IOCTL_PMI_SET_CONFIGURATION** request sets the configuration parameters for the power meter. The **AssociatedIrp.SystemBuffer** member of the IRP references a buffer that contains a [PMI_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_configuration) structure. The **ConfigurationType** member of this structure contains information about the type of PMI configuration data to set in the power meter.

Only PMI configuration data that the power meter supports with read/write permissions can be changed by using a set request of **IOCTL_PMI_SET_CONFIGURATION**. A set request of **IOCTL_PMI_SET_CONFIGURATION** to change read-only PMI configuration data will fail, and the data will not be changed on the power meter.

**Note** Beginning with Windows 7 and Windows Server 2008 R2, the power meter can also support read/write permissions to its budgeting information. For more information, see [PMI_REPORTED_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_reported_capabilities).

## See also

[IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[PMI_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_configuration)

[PMI_REPORTED_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_reported_capabilities)