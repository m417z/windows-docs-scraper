# WdfRequestRequeue function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestRequeue** method returns an I/O request to the head of the I/O queue from which it was delivered to the driver.

## Parameters

### `Request` [in]

A handle to a framework request object.

## Return value

**WdfRequestRequeue** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An input parameter is invalid. |
| **STATUS_INVALID_DEVICE_REQUEST** | This value is returned if one of the following occurs:<br><br>* The specified I/O request did not come from an I/O queue.<br>* The driver does not own the I/O request.<br>* The request is cancelable.<br>* The queue's dispatching method is not manual. |

This method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

A driver can call **WdfRequestRequeue** only if it using the manual dispatching method for the I/O queue.

If the driver calls **WdfRequestRequeue** after calling [WdfIoQueuePurge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuepurge), the requeue attempt may succeed before the purge is complete. In versions 1.9 and earlier of KMDF, this
sequence causes the operating system to crash. This problem is fixed in KMDF version 1.11 and later.

For more information about **WdfRequestRequeue**, see [Requeuing I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/requeuing-i-o-requests).

#### Examples

The following code example returns a specified I/O request to the queue from which the driver received the request.

```cpp
NTSTATUS status;

status = WdfRequestRequeue(request);
```