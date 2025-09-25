# WdfRequestGetIoQueue function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestGetIoQueue** method returns a handle to the framework queue object from which a specified I/O request was delivered.

## Parameters

### `Request` [in]

A handle to a framework request object.

## Return value

**WdfRequestGetIoQueue** returns a handle to a framework queue object. If the request was created by the driver, or if the driver has already completed the specified I/O request, the method returns **NULL**.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about **WdfRequestGetIoQueue**, see [Obtaining Information About an I/O Request](https://learn.microsoft.com/windows-hardware/drivers/wdf/obtaining-information-about-an-i-o-request).

#### Examples

The following code example obtains a handle to the device object that represents the device that a request belongs to.

```cpp
WDFDEVICE  device;

device = WdfIoQueueGetDevice(WdfRequestGetIoQueue(Request));
```

## See also

[WdfIoQueueGetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuegetdevice)