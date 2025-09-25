# WdfDeviceGetDefaultQueue function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceGetDefaultQueue** method returns a handle to a device's default I/O queue.

## Parameters

### `Device` [in]

A handle to a framework device object.

## Return value

If the operation succeeds, the method returns a handle to a framework queue object. If the driver did not create a default I/O queue for the device, the method returns **NULL**.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about default I/O queues, see [Creating I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-i-o-queues).

#### Examples

The following code example obtains a handle to a device's default I/O queue.

```cpp
WDFQUEUE DefaultQueue;

DefaultQueue = WdfDeviceGetDefaultQueue(Device);
```