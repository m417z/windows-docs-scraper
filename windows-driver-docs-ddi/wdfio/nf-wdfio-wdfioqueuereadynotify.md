# WdfIoQueueReadyNotify function

## Description

[Applies to KMDF and UMDF]

The **WdfIoQueueReadyNotify** method registers (or deregisters) an event callback function that the framework calls each time a specified I/O queue that was previously empty receives one or more I/O requests.

## Parameters

### `Queue` [in]

A handle to a framework queue object.

### `QueueReady` [in, optional]

A pointer to a driver-supplied [EvtIoQueueState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state) callback function, if the driver is registering for ready notification, or **NULL** if the driver is deregistering.

### `Context` [in, optional]

An untyped pointer to driver-supplied context information that the framework passes to the [EvtIoQueueState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state) callback function, if the driver is registering for ready notification, or **NULL** if the driver is deregistering.

## Return value

**WdfIoQueueReadyNotify** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The driver supplied an invalid handle. |
| **STATUS_INVALID_DEVICE_REQUEST** | This value is returned if one of the following occurs:<br><br>* The **DispatchType** member of the specified I/O queue's [WDF_IO_QUEUE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_config) structure is not **WdfIoQueueDispatchManual**.<br>* The driver had previously called [WdfIoQueueReadyNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuereadynotify) and registered an [EvtIoQueueState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state) callback function.<br>* The driver is attempting to deregister its notification callback function, but a callback function is not registered or the driver has not called [WdfIoQueueStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestop) or [WdfIoQueueStopSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestopsynchronously). |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

After a driver has called **WdfIoQueueReadyNotify** to register a [EvtIoQueueState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state) callback function, the framework calls the callback function each time the specified queue's state changes from empty to non-empty. Specifically, the framework calls *EvtIoQueueState* when a request arrives on an empty queue, even if the driver still owns previously delivered requests from the queue that it has not yet completed. You can modify the IRQL at which the callback runs by specifying **ExecutionLevel** in [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) at queue creation time. For more info, see the Remarks section of[*EVT_WDF_IO_QUEUE_STATE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state).

The framework does not call [EvtIoQueueState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state) while the specified queue is stopped. When the queue starts, the framework calls *EvtIoQueueState* if the queue is non-empty.

Your driver can call **WdfIoQueueReadyNotify** only for I/O queues that use the [manual dispatching](https://learn.microsoft.com/windows-hardware/drivers/wdf/dispatching-methods-for-i-o-requests) method.

The [EvtIoQueueState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state) callback function typically calls [WdfIoQueueRetrieveNextRequest](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-wdfioqueueretrievenextrequest) or [WdfIoQueueRetrieveRequestByFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueueretrieverequestbyfileobject) in a loop to retrieve all of the requests that have arrived since the last time the callback function executed.

To stop the framework from calling the [EvtIoQueueState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state) callback function, the driver must call **WdfIoQueueReadyNotify** again with the *QueueReady* parameter set to **NULL**. However, the driver must first call [WdfIoQueueStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestop) or [WdfIoQueueStopSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestopsynchronously) to stop the I/O queue. The driver can subsequently call [WdfIoQueueStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestart) to restart the queue.

When a driver calls **WdfIoQueueReadyNotify** to register a [EvtIoQueueState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state) callback function, it is possible for the framework to call the callback function before **WdfIoQueueReadyNotify** returns.

For more information about the **WdfIoQueueReadyNotify** method, see [Dispatching Methods for I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/dispatching-methods-for-i-o-requests).

#### Examples

The following code example registers a driver's **EvtIoQueueReady** function, so that this function will be called when the specified I/O queue receives an I/O request.

```cpp
Status = WdfIoQueueReadyNotify(
                               ReadQueue,
                               EvtIoQueueReady,
                               myQueueContext
                               );
```

## See also

[EvtIoQueueState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state)

[WDF_IO_QUEUE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_config)

[WdfIoQueueRetrieveNextRequest](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-wdfioqueueretrievenextrequest)

[WdfIoQueueRetrieveRequestByFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueueretrieverequestbyfileobject)