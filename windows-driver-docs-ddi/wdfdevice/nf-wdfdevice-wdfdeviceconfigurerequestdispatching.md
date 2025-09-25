# WdfDeviceConfigureRequestDispatching function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceConfigureRequestDispatching** method causes the framework to queue a specified type of I/O requests to a specified I/O queue.

## Parameters

### `Device` [in]

Supplies a handle to a framework device object.

### `Queue` [in]

Supplies a handle to a framework queue object.

### `RequestType` [in]

Supplies a [WDF_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_type)-typed enumerator that identifies the type of request to be queued. The only valid enumerators are:

**WdfRequestTypeCreate**

**WdfRequestTypeRead**

**WdfRequestTypeWrite**

**WdfRequestTypeDeviceControl**

**WdfRequestTypeDeviceControlInternal**

## Return value

If the operation succeeds, the method returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An input parameter is invalid. |
| **STATUS_INSUFFICIENT_RESOURCES** | The amount of available memory is too low. |
| **STATUS_WDF_BUSY** | The driver has already assigned a queue to the specified request type. |

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Each call to **WdfDeviceConfigureRequestDispatching** specifies one request type. If you want a single I/O queue to receive multiple types of requests (for example, read and write requests), your driver can call **WdfDeviceConfigureRequestDispatching** multiple times for a single I/O queue.

For more information about **WdfDeviceConfigureRequestDispatching**, see [Creating I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-i-o-queues) and [Managing I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/managing-i-o-queues).

#### Examples

The following code example initializes a [WDF_IO_QUEUE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_config) structure, creates an I/O queue, and then configures the queue so that it receives write requests.

```cpp
WDF_IO_QUEUE_CONFIG queueConfig;
WDFQUEUE WriteQueue;

WDF_IO_QUEUE_CONFIG_INIT(
                         &queueConfig,
                         WdfIoQueueDispatchSequential
                         );
queueConfig.EvtIoWrite = MyEvtIoWrite;
status = WdfIoQueueCreate(
                          Device,
                          &queueConfig,
                          WDF_NO_OBJECT_ATTRIBUTES,
                          &WriteQueue
                          );
if(!NT_SUCCESS(status)) {
    return status;
}
status = WdfDeviceConfigureRequestDispatching(
                                              Device,
                                              WriteQueue,
                                              WdfRequestTypeWrite
                                              );
if(!NT_SUCCESS(status)) {
    return status;
}
```

## See also

[WDF_IO_QUEUE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_config_init)

[WdfIoQueueCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuecreate)