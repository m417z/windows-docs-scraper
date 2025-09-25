# WdfIoQueueRetrieveNextRequest function

## Description

[Applies to KMDF and UMDF]

The **WdfIoQueueRetrieveNextRequest** method retrieves the next available I/O request from a specified I/O queue.

## Parameters

### `Queue` [in]

A handle to a framework queue object.

### `OutRequest` [out]

A pointer to a location that receives a handle to a framework request object. If the queue is empty or the last request has been retrieved, this parameter receives **NULL**.

## Return value

**WdfIoQueueRetrieveNextRequest** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The driver supplied an invalid handle. |
| **STATUS_NO_MORE_ENTRIES** | The framework reached the end of the I/O queue. |
| **STATUS_INVALID_DEVICE_STATE** | The specified I/O queue is configured for the parallel dispatching method. |
| **STATUS_WDF_PAUSED** | The specified I/O queue is [power-managed](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-power-managed-i-o-queues) and its device is in a low-power state, or the specified queue is stopped. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

If a driver configures an I/O queue for manual dispatching of I/O requests, the driver typically calls **WdfIoQueueRetrieveNextRequest** to obtain requests from the queue. A driver that has configured an I/O queue for sequential dispatching might also call **WdfIoQueueRetrieveNextRequest**. For more information about using **WdfIoQueueRetrieveNextRequest** with the manual or sequential dispatching methods, see [Dispatching Methods for I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/dispatching-methods-for-i-o-requests).

After calling **WdfIoQueueRetrieveNextRequest** to obtain an I/O request, the driver [owns](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-ownership) the request and must [process the I/O request](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers) in some manner.

For more information about the **WdfIoQueueRetrieveNextRequest** method, see [Managing I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/managing-i-o-queues).

#### Examples

The following code example obtains a handle to the next request object that is contained in a device's I/O queue.

```cpp
NTSTATUS  status;
WDFREQUEST  request;

status = WdfIoQueueRetrieveNextRequest(
                                       pDeviceContext->ReadQueue,
                                       &request
                                       );
```

## See also

[WdfIoQueueRetrieveFoundRequest](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-wdfioqueueretrievefoundrequest)

[WdfIoQueueRetrieveRequestByFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueueretrieverequestbyfileobject)