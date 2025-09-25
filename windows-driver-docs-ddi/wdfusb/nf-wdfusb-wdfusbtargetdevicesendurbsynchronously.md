# WdfUsbTargetDeviceSendUrbSynchronously function

## Description

[Applies to KMDF only]

The **WdfUsbTargetDeviceSendUrbSynchronously** method sends a USB request synchronously to a specified USB device, using request parameters that are described by a [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb).

## Parameters

### `UsbDevice` [in]

A handle to a USB device object that was obtained from a previous call to [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters).

### `Request` [in, optional]

A handle to a framework request object. This parameter is optional and can be **NULL**. For more information, see the following Remarks section.

### `RequestOptions` [in, optional]

A pointer to a caller-allocated [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure that specifies options for the request. This pointer is optional and can be **NULL**. For more information, see the following Remarks section.

### `Urb` [in]

A pointer to a caller-initialized [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure.

If the driver previously called [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters) to create *UsbDevice*, the driver must use [WdfUsbTargetDeviceCreateUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreateurb) or [WdfUsbTargetDeviceCreateIsochUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreateisochurb) to create this URB.

## Return value

**WdfUsbTargetDeviceSendUrbSynchronously** returns the I/O target's completion status value if the operation succeeds. Otherwise, this method can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INVALID_DEVICE_REQUEST** | The caller's IRQL was invalid. |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient memory was available. |
| **STATUS_IO_TIMEOUT** | The driver supplied a time-out value and the request did not complete within the allotted time. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Use the **WdfUsbTargetDeviceSendUrbSynchronously** method to send a USB control transfer request synchronously. To send such requests asynchronously, use [WdfUsbTargetDeviceFormatRequestForUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceformatrequestforurb), followed by [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend).

The **WdfUsbTargetDeviceSendUrbSynchronously** method does not return until the request has completed, unless the driver supplies a time-out value in the *RequestOptions* parameter's [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure, or unless an error is detected.

You can forward an I/O request that your driver received in an I/O queue, or you can create and send a new request.

To forward an I/O request that your driver received in an I/O queue, specify the received request's handle for the **WdfUsbTargetDeviceSendUrbSynchronously** method's *Request* parameter.

To create and send a new request, either supply a **NULL** request handle for the *Request* parameter, or create a new request object and supply its handle:

* If you supply a **NULL** request handle, the framework uses an internal request object. This technique is simple to use, but the driver cannot cancel the request.
* If you call [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) to create one or more request objects, you can reuse these request objects by calling [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse). This technique enables your driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function to preallocate request objects for a device. Additionally, another driver thread can call [WdfRequestCancelSentRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcancelsentrequest) to cancel the request, if necessary.

Your driver can specify a non-**NULL** *RequestOptions* parameter, whether the driver provides a non-**NULL** or a **NULL** *Request* parameter. You can, for example, use the *RequestOptions* parameter to specify a time-out value.

For information about obtaining status information after an I/O request completes, see [Obtaining Completion Information](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

For more information about the **WdfUsbTargetDeviceSendUrbSynchronously** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example initializes a URB structure and calls **WdfUsbTargetDeviceSendUrbSynchronously**.

```cpp
URB Urb;
NTSTATUS status;

Urb.UrbHeader.Function =  URB_FUNCTION_GET_CONFIGURATION;
Urb.UrbHeader.Length = sizeof(struct _URB_CONTROL_GET_CONFIGURATION_REQUEST);
Urb.UrbControlGetConfigurationRequest.TransferBufferLength = 1 ; // Must be 1
Urb.UrbControlGetConfigurationRequest.TransferBufferMDL = NULL;
Urb.UrbControlGetConfigurationRequest.TransferBuffer = outBuffer;
Urb.UrbControlGetConfigurationRequest.UrbLink = NULL;

status = WdfUsbTargetDeviceSendUrbSynchronously(
                                                UsbDevice,
                                                NULL,
                                                NULL,
                                                &Urb
                                                );
```

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options)

[WdfRequestCancelSentRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcancelsentrequest)

[WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate)

[WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse)

[WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend)

[WdfUsbTargetDeviceFormatRequestForUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceformatrequestforurb)