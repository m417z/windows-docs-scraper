# WdfRequestFormatRequestUsingCurrentType function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestFormatRequestUsingCurrentType** method formats a specified I/O request so that the driver can [forward](https://learn.microsoft.com/windows-hardware/drivers/wdf/forwarding-i-o-requests) it, unmodified, to the driver's local I/O target.

## Parameters

### `Request` [in]

A handle to a framework request object that the driver received from one of its I/O queues.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

When your driver [receives an I/O request](https://learn.microsoft.com/windows-hardware/drivers/wdf/receiving-i-o-requests), sometimes you will want the driver to forward the request, unmodified, to its local I/O target. To forward such a request, the driver must:

1. Call **WdfRequestFormatRequestUsingCurrentType** to format the request object so that the framework can pass the request to the driver's local I/O target.
2. Call [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend) to send the request to the I/O target.

For more information about **WdfRequestFormatRequestUsingCurrentType**, see [Forwarding I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/forwarding-i-o-requests).

#### Examples

The following code example is an [EvtIoDefault](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_default) callback function that forwards every I/O request that it receives, without modification, to the device's local I/O target.

```cpp
VOID
MyEvtIoDefault(
    WDFQUEUE Queue,
    WDFREQUEST Request
    )
{
    WDF_REQUEST_SEND_OPTIONS options;
    NTSTATUS status;

    WdfRequestFormatRequestUsingCurrentType(Request);

    WDF_REQUEST_SEND_OPTIONS_INIT(
                                  &options,
                                  WDF_REQUEST_SEND_OPTION_SEND_AND_FORGET
                                  );

    ret = WdfRequestSend (
                          Request,
                          WdfDeviceGetIoTarget(WdfIoQueueGetDevice(Queue)),
                          &options
                          );
    if (!ret) {
        status = WdfRequestGetStatus(Request);
        WdfRequestComplete(
                           Request,
                           status
                           );
    }
    return;
}
```

## See also

[WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend)

[WdfRequestWdmFormatUsingStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestwdmformatusingstacklocation)