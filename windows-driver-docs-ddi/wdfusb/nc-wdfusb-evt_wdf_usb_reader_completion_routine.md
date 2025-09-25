# EVT_WDF_USB_READER_COMPLETION_ROUTINE callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtUsbTargetPipeReadComplete* event callback function informs the driver that a continuous reader has successfully completed a read request.

## Parameters

### `Pipe` [in]

A handle to a framework pipe object.

### `Buffer` [in]

A handle to a framework memory object that represents a buffer that contains data from the device.

### `NumBytesTransferred` [in]

The number of bytes of data that are in the read buffer.

### `Context` [in]

Driver-defined context information that the driver specified in the **EvtUsbTargetPipeReadCompleteContext** member of the pipe's [WDF_USB_CONTINUOUS_READER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_continuous_reader_config) structure.

## Remarks

To register an *EvtUsbTargetPipeReadComplete* callback function, the driver must place the function's address in a [WDF_USB_CONTINUOUS_READER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_continuous_reader_config) structure.

If a driver has created a continuous reader for a USB pipe, the framework calls the driver's *EvtUsbTargetPipeReadComplete* callback function each time the driver's I/O target successfully completes a read request. The callback function is called at the IRQL at which the I/O target completed the read request, which is typically IRQL = DISPATCH_LEVEL, but no higher than DISPATCH_LEVEL. (If the I/O target does not successfully complete a request, the framework calls the driver's [EvtUsbTargetPipeReadersFailed](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nc-wdfusb-evt_wdf_usb_readers_failed) callback function.)

To access the buffer that contains data that was read from the device, the driver can call [WdfMemoryGetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorygetbuffer). The framework writes the data into the buffer, after the header that is defined by the **HeaderLength** member of the [WDF_USB_CONTINUOUS_READER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_continuous_reader_config) structure. Note that the pointer that **WdfMemoryGetBuffer** returns points to the beginning of the header, but the *EvtUsbTargetPipeReadComplete* callback function's *NumBytesTransferred* parameter does *not* include the header's length.

By default, the framework deletes the buffer's memory object after the *EvtUsbTargetPipeReadComplete* callback function returns. However, you might want the memory object to remain valid after the callback function returns. For example, you might want your driver to store the object handle in the framework pipe object's context space so that the driver can process the memory object's contents after the callback function returns. To extend the lifetime of the memory object, the callback function must pass the memory object's handle to [WdfObjectReference](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectreference). Subsequently, the driver must call [WdfObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectdereference) so that the framework can delete the object.

The framework synchronizes calls to the *EvtUsbTargetPipeReadComplete* and [EvtUsbTargetPipeReadersFailed](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nc-wdfusb-evt_wdf_usb_readers_failed) callback functions according to the following rules:

* These callback functions do not run simultaneously for an individual USB pipe.
* If the driver creates multiple continuous readers for multiple USB pipes, with multiple *EvtUsbTargetPipeReadComplete* and [EvtUsbTargetPipeReadersFailed](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nc-wdfusb-evt_wdf_usb_readers_failed) callback functions, the multiple callback functions can run simultaneously.
* If the driver has specified the default [NumPendingReads](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_continuous_reader_config) value or a value that is greater than 1, and if a read request completes while the *EvtUsbTargetPipeReadComplete* callback function is executing, the framework can call the *EvtUsbTargetPipeReadComplete* callback function again before the callback function returns.
* The framework does not synchronize these callback functions with any other callback functions.

In the **BufferAttributes** member of the [WDF_USB_CONTINUOUS_READER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_continuous_reader_config) structure, your driver can specify [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) and [EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) callback functions for the memory object. If you specify an *EvtCleanupCallback* callback function, the framework will call that callback function when it attempts to delete the memory object, after the *EvtUsbTargetPipeReadComplete* callback function returns. If the *EvtUsbTargetPipeReadComplete* callback function has called [WdfObjectReference](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectreference), the *EvtCleanupCallback* callback function (if provided) must not call [WdfObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectdereference).

The driver must call [WdfObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectdereference) when it has finished using the memory object. The framework can then call the driver's [EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) callback function (if provided) and delete the memory object.

For more information about the *EvtUsbTargetPipeReadComplete* callback function and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

## See also

[EvtUsbTargetPipeReadersFailed](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nc-wdfusb-evt_wdf_usb_readers_failed)

[WDF_USB_CONTINUOUS_READER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_continuous_reader_config)

[WdfMemoryGetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorygetbuffer)