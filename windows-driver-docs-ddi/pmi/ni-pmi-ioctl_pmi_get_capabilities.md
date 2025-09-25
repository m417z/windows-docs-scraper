# IOCTL_PMI_GET_CAPABILITIES IOCTL

## Description

The **IOCTL_PMI_GET_CAPABILITIES** request obtains the capability and asset information about a power meter.

## Parameters

### Major code

### Input buffer

The **AssociatedIrp.SystemBuffer** member of the I/O request packet (IRP) points to an initiator-allocated buffer that is used both as the input buffer and the output buffer for the request. On input, this buffer contains a [PMI_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_capabilities) structure in which the **Version** and **CapabilityType** members are set to valid values. The **CapabilitiesType** member contains a [PMI_CAPABILITIES_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_capabilities_type) enumeration value that specifies the type of PMI capability information to be retrieved from the power meter. This value also determines the size of the output buffer required to contain this information.

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** member of the IRP's current I/O stack location ([IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)) is set to the size in bytes of the buffer that is pointed to by the **AssociatedIrp.SystemBuffer** member. This size must be greater than or equal to **sizeof**(**PMI_CAPABILITIES**) or the request will fail with an error status of STATUS_INVALID_PARAMETER.

### Output buffer

If the request completes successfully, the buffer pointed to by the **AssociatedIrp.SystemBuffer** member contains the requested PMI capability information. Located at the start of this buffer is a [PMI_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_capabilities) structure that indicates the type and size of the information in the buffer.

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member of the IRP's current I/O stack location is set to the size in bytes of the buffer that is pointed to by the **AssociatedIrp.SystemBuffer** member. For the request to succeed, this size must be large enough to contain the PMI capability information specified by the **PMI_CAPABILITIES_TYPE** input parameter value. Otherwise, the request will fail with error status STATUS_BUFFER_TOO_SMALL.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to the size, in bytes, of a [PMI_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_capabilities) structure and its variable-length data.

The **Status** member is set to one of the following values:

**STATUS_BUFFER_TOO_SMALL**

The **Parameters.DeviceIoControl.OutputBufferLength** member of the [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) is less than the size, in bytes, of a [PMI_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_capabilities) structure and its variable-length data.

**STATUS_INVALID_PARAMETER**

The initiator-allocated input buffer contains an invalid [PMI_CAPABILITIES_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_capabilities_type) value.

**STATUS_SUCCESS**

The WDM driver that supports the PMI interface has completed the IOCTL request successfully.

## Remarks

The **IOCTL_PMI_GET_CAPABILITIES** request queries the PMI capabilities or asset information of the power meter. The input [PMI_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_capabilities) enumeration value specifies the type of capability information to be returned. The data type and contents of the output buffer vary based on the data requested.

The following table describes the type of data that is returned for the specified [PMI_CAPABILITIES_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_capabilities_type) enumeration value.

| PMI_CAPABILITIES_TYPE value | Description |
| --- | --- |
| **PmiMeteredHardware** | A [PMI_METERED_HARDWARE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_metered_hardware_information) structure that specifies the hardware devices that the power meter monitors. |
| **PmiReportedCapabilities** | A [PMI_REPORTED_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_reported_capabilities) structure that specifies the types of PMI capabilities the power meter supports.<br><br>**Note** The **PMI_REPORTED_CAPABILITIES** structure is variable-length. The driver must fail this IOCTL request if the output buffer (referenced by the **MdlAddress** member of the IRP) is too small. |

## See also

[IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[PMI_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_capabilities)

[PMI_CAPABILITIES_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ne-pmi-pmi_capabilities_type)

[PMI_METERED_HARDWARE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_metered_hardware_information)

[PMI_REPORTED_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_reported_capabilities)