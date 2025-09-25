# IOCTL_UCMTCPCI_PORT_CONTROLLER_GET_STATUS IOCTL

## Description

Gets values of all status registers as per the Universal Serial Bus Type-C Port Controller Interface Specification. The client driver must retrieve the values of the CC_STATUS, POWER_STATUS, and FAULT_STATUS registers.

## Parameters

### Major code

### Input buffer

A pointer to a [UCMTCPCI_PORT_CONTROLLER_GET_STATUS_IN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ns-ucmtcpciportcontrollerrequests-_ucmtcpci_port_controller_get_status_in_params) structure that contains all control register values. To get the structure, call [WdfRequestRetrieveInputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputbuffer) by passing the received framework request object.

### Input buffer length

The size of the [UCMTCPCI_PORT_CONTROLLER_GET_STATUS_IN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ns-ucmtcpciportcontrollerrequests-_ucmtcpci_port_controller_get_status_in_params) structure.

### Output buffer

A pointer to the [UCMTCPCI_PORT_CONTROLLER_GET_STATUS_OUT_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ns-ucmtcpciportcontrollerrequests-_ucmtcpci_port_controller_get_status_out_params) structure. To get the structure, call [WdfRequestRetrieveOutputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputbuffer) by passing the received framework request object.

### Output buffer length

The size of the [UCMTCPCI_PORT_CONTROLLER_GET_STATUS_OUT_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ns-ucmtcpciportcontrollerrequests-_ucmtcpci_port_controller_get_status_out_params) structure.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## Remarks

The UcmTcpciCx class extension sends this IOCTL request to retrieve the values of the status registers. The client driver must communicate with the port controller to retrieve the register values and populate the received [UCMTCPCI_PORT_CONTROLLER_GET_STATUS_OUT_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ns-ucmtcpciportcontrollerrequests-_ucmtcpci_port_controller_get_status_out_params) structure with those values. To complete the request, the driver must set the populated structure on the framework request object by calling [WdfRequestSetInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsetinformation) and then call [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete) to complete the request.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)