# WdfIoQueueGetDevice function

## Description

[Applies to KMDF and UMDF]

The **WdfIoQueueGetDevice** method returns a handle to the framework device object that a specified I/O queue belongs to.

## Parameters

### `Queue` [in]

A handle to a framework queue object.

## Return value

**WdfIoQueueGetDevice** returns a handle to a framework device object.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about the **WdfIoQueueGetDevice** method, see [Obtaining I/O Queue Properties](https://learn.microsoft.com/windows-hardware/drivers/wdf/managing-i-o-queues).

#### Examples

The following code example obtains a handle to the framework device object that is associated with the I/O queue that contains a specified request.

```cpp
WDFDEVICE  device;

device = WdfIoQueueGetDevice(WdfRequestGetIoQueue(Request));
```

## See also

[WdfRequestGetIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetioqueue)