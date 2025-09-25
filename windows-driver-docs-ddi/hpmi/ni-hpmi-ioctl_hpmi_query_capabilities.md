# IOCTL_HPMI_QUERY_CAPABILITIES IOCTL

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The IOCTL_HPMI_QUERY_CAPABILITIES command is sent to query features supported by HPMI and Windows services requested by HPMI. Windows will issue this IOCL to HPMI once after a new HPMI driver instance is discovered.

**Important** Preliminary Information

## Parameters

### Major code

### Input buffer

The AssociatedIrp.SystemBuffer member of the I/O request packet (IRP) points to an initiator-allocated buffer that is used both as the input buffer and the output buffer for the request. On input, this buffer contains a [HPMI_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/hpmi/ns-hpmi-_hpmi_query_capabilities) structure in which the version is set to a valid value.

### Input buffer length

The Parameters.DeviceIoControl.InputBufferLength member of the IRP's current I/O stack location (IO_STACK_LOCATION) is set to the size in bytes of the buffer that is pointed to by the AssociatedIrp.SystemBuffer member. This size must be greater than or equal to sizeof [HPMI_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/hpmi/ns-hpmi-_hpmi_query_capabilities) structure or the request will fail with an error status of STATUS_INVALID_PARAMETER.

### Output buffer

If the request completes successfully, the buffer pointed to by the AssociatedIrp.SystemBuffer member contains the requested HPMI capability information. Located at the start of this buffer is a [HPMI_QUERY_CAPABILITIES_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hpmi/ns-hpmi-_hpmi_query_capabilities_response) structure that indicates the type and size of the information in the buffer.

### Output buffer length

The Parameters.DeviceIoControl.OutputBufferLength member of the IRP's current I/O stack location is set to the size in bytes of the buffer that is pointed to by the AssociatedIrp.SystemBuffer member. For the request to succeed, this size must be large enough to contain the HPMI capability described in [HPMI_QUERY_CAPABILITIES_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hpmi/ns-hpmi-_hpmi_query_capabilities_response). Otherwise, the request will fail with error status STATUS_BUFFER_TOO_SMALL.

### Input/output buffer

TBD

### Input/output buffer length

TBD

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code, for example STATUS_INVALID_PARAMETER.

## Remarks

The **IOCTL_HPMI_QUERY_CAPABILITIES** request queries the HPMI capabilities or asset information of the power meter. The input [HPMI_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/hpmi/ns-hpmi-_hpmi_query_capabilities) structure value specifies the type of capability information to be returned. The data type and contents of the output buffer vary based on the data requested.

This IOCTL may be issued multiple times, HPMI must respond with same
information in HPMI_QUERY_CAPABILITIES_RESPONSE, as a response to all
subsequent IOCTL calls.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)