# WdfUsbTargetDeviceAllocAndQueryString function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetDeviceAllocAndQueryString** method allocates a buffer, then it retrieves the Unicode string that is associated with a specified USB device and descriptor index value.

## Parameters

### `UsbDevice` [in]

A handle to a USB device object that was obtained from a previous call to [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters).

### `StringMemoryAttributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains caller-supplied attributes for the new memory object. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `StringMemory` [out]

A pointer to a location that receives a handle to the memory object that contains the Unicode string. The string is NULL-terminated only if the device supplies a NULL-terminated string.

### `NumCharacters` [out, optional]

A pointer to a location that receives the number of characters that are contained in the string descriptor. If the Unicode string is NULL-terminated, this number includes the NULL character. This parameter is optional and can be **NULL**.

### `StringIndex` [in]

An index value that identifies the Unicode string. This index value is obtained from a [USB_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_device_descriptor), [USB_CONFIGURATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_configuration_descriptor), or [USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor) structure.

### `LangID` [in, optional]

A language identifier. The Unicode string will be retrieved for the language that this identifier specifies. For information about obtaining a device's supported language identifiers, see the USB specification.

## Return value

**WdfUsbTargetDeviceAllocAndQueryString** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INSUFFICIENT_RESOURCES** | A memory buffer could not be allocated. |
| **STATUS_DEVICE_DATA_ERROR** | The USB device returned an invalid descriptor. |
| **STATUS_BUFFER_OVERFLOW** | The supplied buffer was too small. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The **WdfUsbTargetDeviceAllocAndQueryString** method, which your driver only needs to call once to obtain a string descriptor, is an alternative to the [WdfUsbTargetDeviceQueryString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicequerystring) method, which must be called twice to obtain a string.

The method locates the specified USB string descriptor, copies the Unicode string from the descriptor into a memory object, and returns a handle to the memory object.

After calling **WdfUsbTargetDeviceAllocAndQueryString**, your driver can pass the *StringMemory* handle to [WdfMemoryGetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorygetbuffer) to access the contents of the memory object.

For more information about USB string descriptors, see the USB specification.

For more information about the **WdfUsbTargetDeviceAllocAndQueryString** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example calls **WdfUsbTargetDeviceAllocAndQueryString** to obtain a manufacturer's name string, in USA English (0x0409), from a USB device descriptor. (The driver previously stored the descriptor in driver-defined context space.)

```cpp
PMY_DEVICE_CONTEXT  myDeviceContext;
WDFMEMORY  memoryHandle;
USHORT  numCharacters;

myDeviceContext = GetDeviceContext(device);

status = WdfUsbTargetDeviceAllocAndQueryString(
                                        myDeviceContext->UsbTargetDevice,
                                        WDF_NO_OBJECT_ATTRIBUTES,
                                        &memoryHandle,
                                        &numCharacters,
                                        myDeviceContext->UsbDeviceDescr.iManufacturer,
                                        0x0409
                                        );
```

## See also

[USB_CONFIGURATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_configuration_descriptor)

[USB_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_device_descriptor)

[USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters)

[WdfUsbTargetDeviceQueryString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicequerystring)