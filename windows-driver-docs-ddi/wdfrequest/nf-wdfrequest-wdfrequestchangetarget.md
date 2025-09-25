# WdfRequestChangeTarget function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestChangeTarget** method verifies that a specified I/O request can be sent to a specified I/O target.

## Parameters

### `Request` [in]

A handle to a framework request object.

### `IoTarget` [in]

A handle to a framework I/O target object.

## Return value

**WdfRequestChangeTarget** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An input parameter is invalid. |
| **STATUS_INSUFFICIENT_RESOURCES** | There are insufficient system resources to complete the operation. |
| **STATUS_REQUEST_NOT_ACCEPTED** | The request's array of I/O stack locations is not large enough to allow the driver to send the request to the I/O target. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Your driver should call the **WdfRequestChangeTarget** method before it calls [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend), if the driver sends a single I/O request to multiple I/O targets. **WdfRequestChangeTarget** verifies that the request can be sent to the specified I/O target.

Most drivers send each request to only one device and thus to only one I/O target. A driver either [receives the request](https://learn.microsoft.com/windows-hardware/drivers/wdf/receiving-i-o-requests) or it creates a new request by calling [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate).

If the driver is sending the request to one device, it calls [WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget) to determine the device's I/O target and then calls [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend) to send the request to the target.

If the driver is sending the request to multiple devices, it calls [WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget) for each device to determine the device's I/O target. Before calling [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend), the driver must call **WdfRequestChangeTarget** to ensure that each I/O target is accessible.

For more information about **WdfRequestChangeTarget**, see [Forwarding I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/forwarding-i-o-requests).

#### Examples

The following code example verifies that an I/O request can be sent to a specified device's local I/O target.

```cpp
NTSTATUS  status;

status = WdfRequestChangeTarget(
                                request,
                                WdfDeviceGetIoTarget(Device)
                                );
```

## See also

[WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget)

[WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate)

[WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend)