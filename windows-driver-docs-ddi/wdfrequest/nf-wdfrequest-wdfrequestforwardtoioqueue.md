# WdfRequestForwardToIoQueue function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestForwardToIoQueue** method requeues an I/O request to one of the calling driver's I/O queues.

## Parameters

### `Request` [in]

A handle to a framework request object.

### `DestinationQueue` [in]

A handle to a framework queue object.

## Return value

**WdfRequestForwardToIoQueue** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | This value is returned if one of the following occurs:<br><br>* The driver did not obtain the request from an I/O queue.<br>* The source and destination queues are the same.<br>* The source and destination queues do not belong to the same device.<br>* The driver does not own the request.<br>* The request is cancelable. |
| **STATUS_WDF_BUSY** | The destination queue is not accepting new requests. |

This method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The driver must [own](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-ownership) the I/O request and must have obtained the request from one of its I/O queues.

The source and destination queues cannot be the same. In other words, the driver cannot call **WdfRequestForwardToIoQueue** to return a request to the queue that it came from. To requeue a request to the same queue, use [WdfRequestRequeue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestrequeue).

Both the source and destination queues must belong to the same device.

The request must not be cancelable. If the driver has called [WdfRequestMarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelable) or [WdfRequestMarkCancelableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelableex) to make the request cancelable, it must call [WdfRequestUnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestunmarkcancelable) before calling **WdfRequestForwardToIoQueue**.

After the driver calls **WdfRequestForwardToIoQueue**, the driver does not own the requeued request until the framework delivers the request from the new queue to the driver. While the request is in the new queue, the framework owns the request and can cancel it without notifying the driver.

Before **WdfRequestForwardToIoQueue** returns, the following events can occur:

* If the destination queue was empty, the framework can deliver the requeued I/O request to one of the destination queue's [request handlers](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-handlers).
* If the source queue's [dispatching method](https://learn.microsoft.com/windows-hardware/drivers/wdf/dispatching-methods-for-i-o-requests) is sequential or parallel, the framework can deliver another request to one of the source queue's request handlers.

For more information about **WdfRequestForwardToIoQueue**, see [Requeuing I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/requeuing-i-o-requests) and [Managing I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/managing-i-o-queues).

#### Examples

The following code example is an [EvtIoDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_device_control) callback function from the [PCIDRV](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample driver. If a received request contains an I/O control code of IOCTL_NDISPROT_INDICATE_STATUS, the driver calls **WdfRequestForwardToIoQueue** to move the request to a different I/O queue.

```cpp
VOID
PciDrvEvtIoDeviceControl(
    IN WDFQUEUE  Queue,
    IN WDFREQUEST  Request,
    IN size_t  OutputBufferLength,
    IN size_t  InputBufferLength,
    IN ULONG  IoControlCode
    )
{
    NTSTATUS  status= STATUS_SUCCESS;
    PFDO_DATA  fdoData = NULL;
    WDFDEVICE  hDevice;
    WDF_REQUEST_PARAMETERS  params;

    UNREFERENCED_PARAMETER(OutputBufferLength);
    UNREFERENCED_PARAMETER(InputBufferLength);

    hDevice = WdfIoQueueGetDevice(Queue);
    fdoData = FdoGetData(hDevice);

    WDF_REQUEST_PARAMETERS_INIT(&params);
    WdfRequestGetParameters(
                            Request,
                            &params
                            );

    switch (IoControlCode)
    {
        case IOCTL_NDISPROT_QUERY_OID_VALUE:
            NICHandleQueryOidRequest(
                                     Queue,
                                     Request,
                                     &params
                                     );
            break;

        case IOCTL_NDISPROT_SET_OID_VALUE:
            NICHandleSetOidRequest(
                                   Queue,
                                   Request,
                                   &params
                                   );
            break;

        case IOCTL_NDISPROT_INDICATE_STATUS:
            status = WdfRequestForwardToIoQueue(
                                                Request,
                                                fdoData->PendingIoctlQueue
                                                );
            if(!NT_SUCCESS(status)){
                WdfRequestComplete(
                                   Request,
                                   status
                                   );
                break;
            }
            break;

        default:
            WdfRequestComplete(
                               Request,
                               STATUS_INVALID_DEVICE_REQUEST
                               );
            break;
    }
    return;
}
```

## See also

[EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy)

[WdfRequestMarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelable)

[WdfRequestMarkCancelableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelableex)

[WdfRequestRequeue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestrequeue)

[WdfRequestUnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestunmarkcancelable)