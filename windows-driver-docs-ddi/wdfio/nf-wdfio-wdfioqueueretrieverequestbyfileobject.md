# WdfIoQueueRetrieveRequestByFileObject function

## Description

[Applies to KMDF and UMDF]

The **WdfIoQueueRetrieveRequestByFileObject** method retrieves the next available I/O request, from a specified I/O queue, that is associated with a specified file object.

## Parameters

### `Queue` [in]

A handle to a framework queue object.

### `FileObject` [in]

A handle to a framework file object.

### `OutRequest` [out]

A pointer to a location that receives a handle to a framework request object. If **WdfIoQueueRetrieveRequestByFileObject** does not return STATUS_SUCCESS, it does not set the location's value.

## Return value

**WdfIoQueueRetrieveRequestByFileObject** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The driver supplied an invalid handle. |
| **STATUS_NO_MORE_ENTRIES** | The framework reached the end of the I/O queue. |
| **STATUS_INVALID_DEVICE_STATE** | The specified I/O queue is configured for the parallel dispatching method. |
| **STATUS_WDF_PAUSED** | The specified I/O queue is [power-managed](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-power-managed-i-o-queues) and its device is in a low-power state. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

A driver that has configured an I/O queue for manual or sequential dispatching might call **WdfIoQueueRetrieveRequestByFileObject**. For more information about using **WdfIoQueueRetrieveRequestByFileObject** with the manual or sequential dispatching methods, see [Dispatching Methods for I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/dispatching-methods-for-i-o-requests).

After calling **WdfIoQueueRetrieveRequestByFileObject** to obtain an I/O request, the driver [owns](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-ownership) the request and must [process the I/O request](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers) in some manner.

For more information about the **WdfIoQueueRetrieveRequestByFileObject** method, see [Managing I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/managing-i-o-queues).

#### Examples

The following code example obtains, from a specified I/O queue, a handle to the next framework request object that is associated with a specified framework file object.

```cpp
WDFREQUEST  request;

status = WdfIoQueueRetrieveRequestByFileObject(
                                               queue,
                                               fileObject,
                                               &request
                                               );
```

## See also

[WdfIoQueueRetrieveFoundRequest](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-wdfioqueueretrievefoundrequest)

[WdfIoQueueRetrieveNextRequest](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-wdfioqueueretrievenextrequest)