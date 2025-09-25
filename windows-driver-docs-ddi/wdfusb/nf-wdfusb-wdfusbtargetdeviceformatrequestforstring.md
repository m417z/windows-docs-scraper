# WdfUsbTargetDeviceFormatRequestForString function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetDeviceFormatRequestForString** method builds a request for the USB string descriptor that is associated with a USB device's string index value.

## Parameters

### `UsbDevice` [in]

A handle to a USB device object that was obtained from a previous call to [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters).

### `Request` [in]

A handle to a framework request object.

### `Memory` [in]

A handle to a framework memory object.

### `Offset` [in, optional]

A pointer to a caller-allocated [WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdfmemory_offset) structure that supplies optional byte offset and length values. The framework uses these values to determine the beginning address and length, within the output buffer, for storing the string descriptor. If this pointer is **NULL**, the descriptor is stored at the beginning of the output buffer, and the maximum string length is the buffer length.

### `StringIndex` [in]

An index value that identifies the string. This index value is obtained from a [USB_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_device_descriptor), [USB_CONFIGURATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_configuration_descriptor), or [USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor) structure.

### `LangID` [in, optional]

A language identifier. The string will be retrieved for the language that this identifier specifies. For information about obtaining a device's supported language identifiers, see the USB specification.

## Return value

**WdfUsbTargetDeviceFormatRequestForString** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The buffer's byte count was not an even number. |
| **STATUS_INSUFFICIENT_RESOURCES** | There was insufficient memory. |
| **STATUS_INTEGER_OVERFLOW** | The offset that *Offset* specifies was invalid. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

After **WdfUsbTargetDeviceFormatRequestForString** returns, the driver must call [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend) to send the request. After **WdfRequestSend** returns, the driver can pass the *Memory* handle to [WdfMemoryGetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorygetbuffer) to obtain a pointer to the memory buffer. The buffer will contain a [USB_STRING_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_string_descriptor) structure that describes the string descriptor.

For more information about the **WdfUsbTargetDeviceFormatRequestForString** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example creates a request object and a memory object, and it passes the object handles to **WdfUsbTargetDeviceFormatRequestForString**. Then, the example sets a [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function for the request and sends the request to an I/O target.

```cpp
NTSTATUS status;
PDEVICE_CONTEXT deviceContext = GetDeviceContext(device);
WDFREQUEST request;
WDFMEMORY memHandle;
WDF_OBJECT_ATTRIBUTES attributes;

WDF_OBJECT_ATTRIBUTES_INIT(&attributes);

status = WdfRequestCreate(
    &attributes,
    WdfUsbTargetDeviceGetIoTarget(deviceContext->UsbTargetDevice),
    &request);

if (!NT_SUCCESS(status)) {
    return status;
}

status = WdfMemoryCreate(
    WDF_NO_OBJECT_ATTRIBUTES,
    NonPagedPool,
    0,
    STR_DESC_STRING_SIZE,
    &memHandle,
    NULL);
if (!NT_SUCCESS(status)) {
    WdfObjectDelete(request);
    return status;
}

status = WdfUsbTargetDeviceFormatRequestForString(
    deviceContext->UsbTargetDevice,
    request,
    memHandle,
    NULL,
    deviceContext->UsbDeviceDescr.iManufacturer,
    0x0409);

if (NT_SUCCESS(status)) {
    WdfRequestSetCompletionRoutine(
        request,
        MyCompletionRoutine,
        NULL);

    if (WdfRequestSend(
            request,
            WdfUsbTargetDeviceGetIoTarget(deviceContext->UsbTargetDevice),
            NULL)) {
        status = STATUS_PENDING;
    }

}
else {
    WdfObjectDelete(memHandle);
    WdfObjectDelete(request);
    return status;
}
```

## See also

[USB_CONFIGURATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_configuration_descriptor)

[USB_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_device_descriptor)

[USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor)

[USB_STRING_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_string_descriptor)

[WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdfmemory_offset)

[WdfMemoryGetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorygetbuffer)

[WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend)

[WdfRequestSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsetcompletionroutine)

[WdfUsbTargetDeviceAllocAndQueryString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceallocandquerystring)

[WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters)