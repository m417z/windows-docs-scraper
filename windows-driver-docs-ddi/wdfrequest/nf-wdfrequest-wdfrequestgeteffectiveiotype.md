# WdfRequestGetEffectiveIoType function

## Description

[Applies to UMDF only]

The **WdfRequestGetEffectiveIoType** method returns the buffer access method that UMDF is using for the data buffers of the specified I/O request.

## Parameters

### `Request` [in]

A handle to a framework request object.

## Return value

**WdfRequestGetEffectiveIoType** returns a [WDF_DEVICE_IO_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_device_io_type)-typed value that identifies the buffer access method that UMDF is using for the I/O request's data buffers.

## Remarks

For more information, see [Managing Buffer Access Methods in UMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/managing-buffer-access-methods-in-umdf-drivers).

#### Examples

The following code example shows how an [EvtIoWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_write) callback function can determine the buffer access method for the specified write request.

```cpp
VOID
MyDrvEvtIoWrite(
  _In_  WDFQUEUE Queue,
  _In_  WDFREQUEST Request,
  _In_  size_t Length
)
{

...

    WDF_DEVICE_IO_TYPE iotype = WdfDeviceIoUndefined;

    iotype = WdfRequestGetEffectiveIoType(Request);

...

}

```

## See also

[WDF_DEVICE_IO_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_device_io_type)