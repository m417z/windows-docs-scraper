# WdfUsbTargetDeviceFormatRequestForCyclePort function

## Description

[Applies to KMDF only]

The **WdfUsbTargetDeviceFormatRequestForCyclePort** method builds a power-cycle request for the port to which a specified device is attached, but it does not send the request.

## Parameters

### `UsbDevice` [in]

A handle to a USB device object that was obtained from a previous call to [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters).

### `Request` [in]

A handle to a framework request object. For more information, see the following Remarks section.

## Return value

**WdfUsbTargetDeviceFormatRequestForCyclePort** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_STATE** | The device's USB device was unavailable. |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient memory was available. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Use **WdfUsbTargetDeviceFormatRequestForCyclePort**, followed by [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend), to send a power-cycle request either synchronously or asynchronously. Alternatively, use the [WdfUsbTargetDeviceCyclePortSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecycleportsynchronously) method to send a request synchronously.

Before the driver calls [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend), it must call [WdfIoTargetStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstop) and it must [complete](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests) or [cancel](https://learn.microsoft.com/windows-hardware/drivers/wdf/canceling-i-o-requests) all I/O requests that it has sent to the I/O target. The driver must not send additional I/O requests to the I/O target until the cycle request completes.

You can forward an I/O request that your driver received in an I/O queue, or you can create and send a new request.

To forward an I/O request that your driver received in an I/O queue, specify the received request's handle for the **WdfUsbTargetDeviceFormatRequestForCyclePort** method's *Request* parameter.

To create a new I/O request, call [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) to preallocate a request object. Supply the request handle for the **WdfUsbTargetDeviceFormatRequestForCyclePort** method's *Request* parameter. You can reuse the request object by calling [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse). Your driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function can preallocate request objects for a device.

After calling **WdfUsbTargetDeviceFormatRequestForCyclePort** to format an I/O request, the driver must call [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend) to send the request (either synchronously or asynchronously) to an I/O target. This call to **WdfRequestSend** must be made at IRQL = PASSIVE_LEVEL.

Multiple calls to **WdfUsbTargetDeviceFormatRequestForCyclePort** that use the same request do not cause additional resource allocations. Therefore, to reduce the chance that [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) will return STATUS_INSUFFICIENT_RESOURCES, your driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function can call **WdfRequestCreate** to preallocate one or more request objects for a device. The driver can subsequently reuse (call [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse)), reformat (call **WdfUsbTargetDeviceFormatRequestForCyclePort**), and resend (call [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend)) each request object without risking a STATUS_INSUFFICIENT_RESOURCES return value from a later call to **WdfRequestCreate**. All subsequent calls to **WdfUsbTargetDeviceFormatRequestForCyclePort** for the reused request object will return STATUS_SUCCESS, if parameter values do not change. (If the driver does not call the same request-formatting method each time, additional resources might be allocated.)

For more information about the **WdfUsbTargetDeviceFormatRequestForCyclePort** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example formats a power-cycle request, registers a [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function, and sends the request to an I/O target.

```cpp
status = WdfUsbTargetDeviceFormatRequestForCyclePort(
                                            UsbDevice,
                                            request
                                            );
if (!NT_SUCCESS(status)){
    return status;
}
WdfRequestSetCompletionRoutine(
                               request,
                               MyCompletionRoutine,
                               NULL
                               );

if (WdfRequestSend(
                   request,
                   WdfUsbTargetDeviceGetIoTarget(UsbDevice),
                   NULL
                   ) == FALSE) {
    status = WdfRequestGetStatus(request);
}
```

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse)

[WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend)

[WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters)

[WdfUsbTargetDeviceCyclePortSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecycleportsynchronously)