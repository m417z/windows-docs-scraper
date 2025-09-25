# IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_CONFIG_STANDARD_OUTPUT IOCTL

## Description

Sets the CONFIG_STANDARD_OUTPUT Register defined as per the Universal Serial Bus Type-C Port Controller Interface Specification.

## Parameters

### Major code

### Input buffer

A pointer to a [UCMTCPCI_PORT_CONTROLLER_SET_CONFIG_STANDARD_OUTPUT_IN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ns-ucmtcpciportcontrollerrequests-_ucmtcpci_port_controller_set_config_standard_output_in_params) structure that contains the values to set in the CONFIG_STANDARD_OUTPUT Register. To get the structure, call [WdfRequestRetrieveInputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputbuffer) by passing the received framework request object. This structure is declared in UcmTcpciSpec.h.

### Input buffer length

The size of the [UCMTCPCI_PORT_CONTROLLER_SET_CONFIG_STANDARD_OUTPUT_IN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ns-ucmtcpciportcontrollerrequests-_ucmtcpci_port_controller_set_config_standard_output_in_params) structure.

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## Remarks

The UcmTcpciCx class extension sends this IOCTL request to set the CONFIG_STANDARD_OUTPUT Register. The value to set is provided in the supplied structure. After setting the value in the register, client driver must call [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete) to complete the request.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)