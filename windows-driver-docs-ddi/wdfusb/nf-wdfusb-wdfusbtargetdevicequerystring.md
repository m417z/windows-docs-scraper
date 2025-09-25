# WdfUsbTargetDeviceQueryString function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetDeviceQueryString** method retrieves the Unicode string that is associated with a specified USB device and descriptor index value.

## Parameters

### `UsbDevice` [in]

A handle to a USB device object that was obtained from a previous call to [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters).

### `Request` [in, optional]

A handle to a framework request object. This parameter is optional and can be **NULL**. For more information, see the following Remarks section.

### `RequestOptions` [in, optional]

A pointer to a caller-allocated [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure that specifies options for the request. This pointer is optional and can be **NULL**. For more information, see the following Remarks section.

### `String` [out, optional]

A pointer to a caller-allocated buffer that receives the requested Unicode string. The string is NULL-terminated only if the device supplies a NULL-terminated string. If this pointer is **NULL**, **WdfUsbTargetDeviceQueryString** returns the required buffer size (that is, the required number of Unicode characters) in the location that *NumCharacters* points to.

### `NumCharacters` [in, out]

A pointer to a caller-allocated variable. The caller supplies the number of Unicode characters that the buffer can hold. When **WdfUsbTargetDeviceQueryString** returns, the variable receives the number of characters (including the NULL terminator, if supplied) that are in the Unicode string that the *String* buffer receives.

### `StringIndex` [in]

An index value that identifies the Unicode string. This index value is obtained from a [USB_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_device_descriptor), [USB_CONFIGURATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_configuration_descriptor), or [USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor) structure.

### `LangID` [in, optional]

A language identifier. The Unicode string will be retrieved for the language that this identifier specifies. For information about obtaining a device's supported language identifiers, see the USB specification.

## Return value

**WdfUsbTargetDeviceQueryString** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INSUFFICIENT_RESOURCES** | A memory buffer could not be allocated. |
| **STATUS_DEVICE_DATA_ERROR** | The USB device returned an invalid descriptor. |
| **STATUS_BUFFER_OVERFLOW** | The supplied buffer was too small. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Drivers should call **WdfUsbTargetDeviceQueryString** twice, by using the following steps:

* Set the *String* pointer to **NULL**, so that **WdfUsbTargetDeviceQueryString** will return the required buffer size in the address that the *NumCharacters* parameter points to.
* Allocate buffer space to hold the number of Unicode characters that are in the requested string. For example, a driver might call [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag) to allocate a buffer, or it might call [WdfMemoryCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreate) to create a framework memory object.
* Call **WdfUsbTargetDeviceQueryString** again, setting the *String* value to a pointer to the new buffer and setting *NumCharacters* to the buffer's length (that is, the number of Unicode characters, not the byte length).

**WdfUsbTargetDeviceQueryString** locates the specified USB string descriptor and copies the Unicode string from the descriptor into the supplied buffer.

If your driver specifies a non-**NULL** value for the *Request* parameter, the framework uses the specified request object, and another driver thread can call [WdfRequestCancelSentRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcancelsentrequest), if necessary, to attempt to cancel the string query request. If the driver specifies a **NULL** value for *Request*, the framework uses an internal request object that the driver cannot cancel.

Your driver can specify a non-**NULL** *RequestOptions* parameter, whether the driver provides a non-**NULL** or a **NULL** *Request* parameter. You can, for example, use the *RequestOptions* parameter to specify a time-out value.

For more information about USB string descriptors, see the USB specification.

For more information about the **WdfUsbTargetDeviceQueryString** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example calls **WdfUsbTargetDeviceQueryString** to obtain the required buffer size, calls [WdfMemoryCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreate) to create a memory object and buffer, and then calls **WdfUsbTargetDeviceQueryString** again to obtain the manufacturer's name string, in USA English (0x0409), from a USB device descriptor. (The driver previously stored the descriptor in driver-defined context space.)

```cpp
PMY_DEVICE_CONTEXT  myDeviceContext;
USHORT  numCharacters;
PUSHORT  stringBuf;
WDFMEMORY  memoryHandle;

myDeviceContext = GetDeviceContext(device);

status = WdfUsbTargetDeviceQueryString(
                                       myDeviceContext->UsbTargetDevice,
                                       NULL,
                                       NULL,
                                       NULL,
                                       &numCharacters,
                                       myDeviceContext->UsbDeviceDescr.iManufacturer,
                                       0x0409
                                       );

ntStatus = WdfMemoryCreate(
                           WDF_NO_OBJECT_ATTRIBUTES,
                           NonPagedPool,
                           POOL_TAG,
                           numCharacters * sizeof(WCHAR),
                           &memoryHandle,
                           (PVOID)&stringBuf
                           );
if (!NT_SUCCESS(ntStatus)) {
    return ntStatus;
}
status = WdfUsbTargetDeviceQueryString(
                                       myDeviceContext->UsbTargetDevice,
                                       NULL,
                                       NULL,
                                       stringBuf,
                                       &numCharacters,
                                       myDeviceContext->UsbDeviceDescr.iManufacturer,
                                       0x0409
                                       );
```

## See also

[USB_CONFIGURATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_configuration_descriptor)

[USB_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_device_descriptor)

[USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor)

[WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options)

[WdfRequestCancelSentRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcancelsentrequest)

[WdfUsbTargetDeviceAllocAndQueryString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceallocandquerystring)

[WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters)