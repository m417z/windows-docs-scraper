# _WDF_USB_REQUEST_COMPLETION_PARAMS structure

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_REQUEST_COMPLETION_PARAMS** structure contains parameters that are associated with the completion of an I/O request for a USB device.

## Members

### `UsbdStatus`

The [USBD_STATUS](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff539136(v=vs.85))-typed status value that the I/O target returned.

### `Type`

A [WDF_USB_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdf_usb_request_type)-typed values that identifies the request type.

### `Parameters`

### `Parameters.DeviceString`

### `Parameters.DeviceString.Buffer`

If the driver has called [WdfUsbTargetDeviceFormatRequestForString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceformatrequestforstring), this member contains the driver-supplied handle to the memory object that receives the Unicode string.

### `Parameters.DeviceString.LangID`

If the driver has called [WdfUsbTargetDeviceFormatRequestForString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceformatrequestforstring), this member contains the driver-supplied language identifier.

### `Parameters.DeviceString.StringIndex`

If the driver has called [WdfUsbTargetDeviceFormatRequestForString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceformatrequestforstring), this member contains the driver-supplied string index.

### `Parameters.DeviceString.RequiredSize`

If the driver has called any method that [obtains a device's Unicode strings](https://learn.microsoft.com/windows-hardware/drivers/wdf/working-with-usb-devices) (except [WdfUsbTargetDeviceFormatRequestForUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceformatrequestforurb)), this member contains the required size of the buffer that **Parameters.DeviceString.Buffer** specifies.

If the driver called [WdfUsbTargetDeviceFormatRequestForUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceformatrequestforurb), it can obtain the required size value from the URB whose handle is in **Parameters.DeviceUrb.Buffer**.

### `Parameters.DeviceControlTransfer`

### `Parameters.DeviceControlTransfer.Buffer`

If the driver has called [WdfUsbTargetDeviceFormatRequestForControlTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceformatrequestforcontroltransfer), this member contains the driver-supplied handle to the memory object that receives input or output data.

### `Parameters.DeviceControlTransfer.SetupPacket`

If the driver has called [WdfUsbTargetDeviceFormatRequestForControlTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceformatrequestforcontroltransfer), this member contains the address of the [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure that the driver supplied.

### `Parameters.DeviceControlTransfer.Length`

If the driver has called any method that [sends a control transfer](https://learn.microsoft.com/windows-hardware/drivers/wdf/working-with-usb-devices) (except [WdfUsbTargetDeviceFormatRequestForUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceformatrequestforurb)), this member contains the number of bytes that were sent or received.

If the driver called [WdfUsbTargetDeviceFormatRequestForUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceformatrequestforurb), it can obtain the length value from the URB whose handle is in **Parameters.DeviceUrb.Buffer**.

### `Parameters.DeviceUrb`

### `Parameters.DeviceUrb.Buffer`

If the driver has called [WdfUsbTargetDeviceFormatRequestForUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceformatrequestforurb), this member contains the driver-supplied handle to the memory object that contains a [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure.

### `Parameters.PipeWrite`

### `Parameters.PipeWrite.Buffer`

If the driver has called [WdfUsbTargetPipeFormatRequestForWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipeformatrequestforwrite), this member contains the driver-supplied handle to the memory object that was written to the pipe.

### `Parameters.PipeWrite.Length`

If the driver has called any method [that writes to a pipe](https://learn.microsoft.com/windows-hardware/drivers/wdf/working-with-usb-pipes) (except [WdfUsbTargetDeviceFormatRequestForUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceformatrequestforurb)), this member contains the number of bytes that were sent.

If the driver called [WdfUsbTargetDeviceFormatRequestForUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceformatrequestforurb), it can obtain the length value from the URB whose handle is in **Parameters.PipeUrb.Buffer**.

### `Parameters.PipeWrite.Offset`

If the driver has called [WdfUsbTargetPipeFormatRequestForWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipeformatrequestforwrite), this member contains the driver-supplied buffer offset.

### `Parameters.PipeRead`

### `Parameters.PipeRead.Buffer`

If the driver has called [WdfUsbTargetPipeFormatRequestForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipeformatrequestforread), this member contains the driver-supplied handle to the memory object that contains data that was read from the pipe.

### `Parameters.PipeRead.Length`

If the driver has called any method that [reads from a pipe](https://learn.microsoft.com/windows-hardware/drivers/wdf/working-with-usb-pipes) sends a control transfer (except [WdfUsbTargetDeviceFormatRequestForUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceformatrequestforurb)), this member contains the number of bytes that were received.

If the driver called [WdfUsbTargetDeviceFormatRequestForUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceformatrequestforurb), it can obtain the length value from the URB whose handle is in **Parameters.PipeUrb.Buffer**.

### `Parameters.PipeRead.Offset`

If the driver has called [WdfUsbTargetPipeFormatRequestForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipeformatrequestforread), this member contains the driver-supplied buffer offset.

### `Parameters.PipeUrb`

### `Parameters.PipeUrb.Buffer`

If the driver has called [WdfUsbTargetPipeFormatRequestForUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipeformatrequestforurb), this member contains the driver-supplied handle to the memory object that contains a [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure.

## Remarks

The **WDF_USB_REQUEST_COMPLETION_PARAMS** structure is a member of the [WDF_REQUEST_COMPLETION_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_completion_params) structure.

## See also

[CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine)

[WDF_REQUEST_COMPLETION_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_completion_params)

[WdfRequestGetCompletionParams](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetcompletionparams)