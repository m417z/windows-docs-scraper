# WdfRequestSetInformation function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestSetInformation** method sets completion status information for a specified I/O request.

## Parameters

### `Request` [in]

A handle to a framework request object.

### `Information` [in]

Driver-defined completion status information for the request.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

Framework-based drivers use the **WdfRequestSetInformation** method to supply driver-specific information that is associated with the completion of an I/O request, such as the number of bytes transferred. Other drivers can obtain this information by calling [WdfRequestGetInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetinformation).

Drivers can also specify completion status information by calling [WdfRequestCompleteWithInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcompletewithinformation).

For more information about **WdfRequestSetInformation**, see [Completing I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

#### Examples

The following code example sets request completion information that is based on the value of the I/O control code that an [EvtIoDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_device_control) callback function receives.

```cpp
VOID
MyEvtIoDeviceControl(
    IN WDFQUEUE  Queue,
    IN WDFREQUEST  Request,
    IN size_t  OutputBufferLength,
    IN size_t  InputBufferLength,
    IN ULONG  IoControlCode
    )
{
    switch (IoControlCode) {
      case MY_IOCTL_CODE_1:
            WdfRequestSetInformation(
                                     Request,
                                     VALUE_1
                                     );
            status = STATUS_SUCCESS;
            break;

      case MY_IOCTL_CODE_2:
            WdfRequestSetInformation(
                                     Request,
                                     VALUE_2
                                     );
            status = STATUS_SUCCESS;
            break;

      case MY_IOCTL_CODE_3:
            WdfRequestSetInformation(
                                     Request,
                                     VALUE_3
                                     );
            status = STATUS_SUCCESS;
            break;

      default:
            status = STATUS_INVALID_DEVICE_REQUEST;
            break;
    }

    WdfRequestComplete(
                       Request,
                       status
                       );
}
```

## See also

[WdfRequestCompleteWithInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcompletewithinformation)

[WdfRequestGetInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetinformation)