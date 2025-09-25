# WdfDeviceEnqueueRequest function

## Description

[Applies to KMDF only]

The **WdfDeviceEnqueueRequest** method delivers a specified I/O request to the framework, so that the framework can subsequently add the request to one of the I/O queues that the driver has created for the specified device.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Request` [in]

A handle to a framework request object.

## Return value

If the operation succeeds, the method returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | The amount of available memory is low. |
| **STATUS_INVALID_DEVICE_REQUEST** | The driver has not created any I/O queues for the device, and the driver is not a filter driver. |
| **STATUS_WDF_BUSY** | The device's I/O queue is not accepting requests. |

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Your driver can call **WdfDeviceEnqueueRequest** only from an [EvtIoInCallerContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_io_in_caller_context) callback function.

The **WdfDeviceEnqueueRequest** method adds the request to the driver's request-type-specific I/O queue for the device, if the driver has created one. Otherwise the method adds the request to the device's default queue, if the driver has created one.

If the driver has not created any I/O queues for the device, **WdfDeviceEnqueueRequest** does the following:

* If the driver is a filter driver, **WdfDeviceEnqueueRequest** sends the request to the driver's I/O target.
* If the driver is not a filter driver, **WdfDeviceEnqueueRequest** returns STATUS_INVALID_DEVICE_REQUEST.

While **WdfDeviceEnqueueRequest** is executing, it is possible for the driver to receive and complete or cancel the request.

As a result, if the driver needs to use the request or its context after calling **WdfDeviceEnqueueRequest**, then it should take a reference on the request before calling **WdfDeviceEnqueueRequest**.

To do so, the driver can call [WdfObjectReference](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectreference) before and then [WdfObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectdereference) after the call to **WdfDeviceEnqueueRequest**. The driver must dereference the request before exiting [EvtIoInCallerContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_io_in_caller_context).

For more information about the **WdfDeviceEnqueueRequest** method, see [Managing I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/managing-i-o-queues).

For versions 1.0 and 1.5 of KMDF, **WdfDeviceEnqueueRequest** must be called at PASSIVE_LEVEL. For versions 1.7 and later, **WdfDeviceEnqueueRequest** can be called at IRQL <= DISPATCH_LEVEL.

#### Examples

The following code example is an [EvtIoInCallerContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_io_in_caller_context) callback function that looks for requests that contain the custom I/O control code, IOCTL_NONPNP_METHOD_NEITHER. If the I/O control code is not found, the callback function just returns the request to the framework. If the callback function finds the I/O control code, it preprocesses the request and then returns it to the framework. If an error is encountered, the callback function completes the request.

```cpp
VOID
MyEvtDeviceIoInCallerContext(
    IN WDFDEVICE  Device,
    IN WDFREQUEST Request
    )
{
    NTSTATUS  status = STATUS_SUCCESS;
    WDF_REQUEST_PARAMETERS  params;

    WDF_REQUEST_PARAMETERS_INIT(&params);
    WdfRequestGetParameters(
                            Request,
                            &params
                            );
    if(!(params.Type == WdfRequestTypeDeviceControl &&
         params.Parameters.DeviceIoControl.IoControlCode == IOCTL_NONPNP_METHOD_NEITHER)) {
        status = WdfDeviceEnqueueRequest(
                                         Device,
                                         Request
                                         );
        if(!NT_SUCCESS(status)) {
            goto End;
        }
        return;
    }
    //
    // Found a match for the control code. Preprocess the request, and then
    // return the request to the framework.
    //

    //...(Preprocess the request here.)

    status = WdfDeviceEnqueueRequest(
                                     Device,
                                     Request
                                     );
    if(!NT_SUCCESS(status)) {
        goto End;
    }
    return;
End:
    WdfRequestComplete(
                       Request,
                       status
                       );
    return;
}
```

## See also

[WDF_REQUEST_PARAMETERS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdf_request_parameters_init)

[WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete)

[WdfRequestGetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetparameters)