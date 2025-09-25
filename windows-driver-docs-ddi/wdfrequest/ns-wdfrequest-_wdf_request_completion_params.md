# _WDF_REQUEST_COMPLETION_PARAMS structure

## Description

[Applies to KMDF and UMDF]

The **WDF_REQUEST_COMPLETION_PARAMS** structure contains parameters that are associated with the completion of an I/O request.

## Members

### `Size`

The size, in bytes, of this structure.

### `Type`

A [WDF_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_type) value that identifies the request type.

### `IoStatus`

An [IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure for the request.

### `Parameters`

Request-specific values for the request.

### `Parameters.Write`

### `Parameters.Write.Buffer`

A handle to a framework memory object. This object identifies the buffer that the driver specified when it formatted the request and sent it to an I/O target.

### `Parameters.Write.Length`

Length, in bytes, of the transfer.

### `Parameters.Write.Offset`

Beginning address within the buffer for the data transfer.

### `Parameters.Read`

### `Parameters.Read.Buffer`

A handle to a framework memory object. This object identifies the buffer that the driver specified when it formatted the request and sent it to an I/O target.

### `Parameters.Read.Length`

Length, in bytes, of the transfer.

### `Parameters.Read.Offset`

Beginning address within the buffer for the data transfer.

### `Parameters.Ioctl`

### `Parameters.Ioctl.IoControlCode`

### `Parameters.Ioctl.Input`

### `Parameters.Ioctl.Input.Buffer`

A handle to a framework memory object. This object identifies the input buffer that the driver specified when it formatted the request and sent it to an I/O target.

### `Parameters.Ioctl.Input.Offset`

Beginning address within the buffer for the data transfer.

### `Parameters.Ioctl.Output`

### `Parameters.Ioctl.Output.Buffer`

A handle to a framework memory object. This object identifies the output buffers that the driver specified when it formatted the request and sent it to an I/O target.

### `Parameters.Ioctl.Output.Offset`

Beginning address within the buffer for the data transfer.

### `Parameters.Ioctl.Output.Length`

Length, in bytes, of the transfer.

### `Parameters.Others`

### `Parameters.Others.Argument1`

Use of this member is defined by the driver stack. See Remarks.

### `Parameters.Others.Argument1.Ptr`

### `Parameters.Others.Argument1.Value`

### `Parameters.Others.Argument2`

Use of this member is defined by the driver stack.

### `Parameters.Others.Argument2.Ptr`

### `Parameters.Others.Argument2.Value`

### `Parameters.Others.Argument3`

Use of this member is defined by the driver stack.

### `Parameters.Others.Argument3.Ptr`

### `Parameters.Others.Argument3.Value`

### `Parameters.Others.Argument4`

Use of this member is defined by the driver stack.

### `Parameters.Others.Argument4.Ptr`

### `Parameters.Others.Argument4.Value`

### `Parameters.Usb`

For USB devices, this member contains a pointer to a [WDF_USB_REQUEST_COMPLETION_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_request_completion_params) structure.

### `Parameters.Usb.Completion`

## Remarks

The **WDF_REQUEST_COMPLETION_PARAMS** structure is used as input to the [WdfRequestGetCompletionParams](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetcompletionparams) method and a driver's [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function.

 In both cases, the completion parameters structure contains valid information only if the driver has formatted the request by calling one of the **WdfIoTargetFormat***Xxx* methods. For example, see [WdfIoTargetFormatRequestForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetformatrequestforread).

Before calling [WdfRequestGetCompletionParams](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetcompletionparams) to retrieve the I/O completion information for a request, the driver must first call [WDF_REQUEST_COMPLETION_PARAMS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdf_request_completion_params_init) to initialize the **WDF_REQUEST_COMPLETION_PARAMS** structure.

The **Parameters.Others.Argument** members are custom arguments that a driver typically passes down the stack (and can arrive back after the request is completed). They are used for non-standard, driver stack dependent data. For example, a USB driver specifies a pointer to a URB in **Parameters.Others.Argument1** when it sends a [IOCTL_INTERNAL_USB_SUBMIT_URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_submit_urb) request to the USB stack. Similarly, a Bluetooth driver specifies a pointer to a BRB (Bluetooth Request Block) in **Parameters.Others.Argument1** when it receives an [IOCTL_INTERNAL_BTH_SUBMIT_BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_internal_bth_submit_brb).

## See also

[CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine)

[IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block)

[WDF_REQUEST_COMPLETION_PARAMS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdf_request_completion_params_init)

[WDF_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_type)

[WdfRequestGetCompletionParams](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetcompletionparams)