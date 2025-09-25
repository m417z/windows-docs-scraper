# HidD_GetIndexedString function

## Description

The **HidD_GetIndexedString** routine returns a specified embedded string from a [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections).

## Parameters

### `HidDeviceObject` [in]

Specifies an open handle to a top-level collection.

### `StringIndex` [in]

Specifies the device-specific index of an embedded string.

### `Buffer` [out]

Pointer to a caller-allocated buffer that the routine uses to return the embedded string specified by *StringIndex*. The routine returns a NULL-terminated wide character string in a human-readable format.

### `BufferLength` [in]

Specifies the length, in bytes, of a caller-allocated buffer provided at *Buffer*. If the buffer is not large enough to return the entire NULL-terminated embedded string, the routine returns nothing in the buffer. The supplied buffer must be <= 4093 bytes (2^12 – 3).

## Return value

**HidD_GetIndexedString** returns **TRUE** if it successfully returns the entire NULL-terminated embedded string. Otherwise, the routine returns **FALSE**. Use [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get extended error information.

## Remarks

Only user-mode applications can call **HidD_GetIndexedString**. Kernel-mode drivers can use an [IOCTL_HID_GET_INDEXED_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_indexed_string) request.

The maximum possible number of characters in an embedded string is device specific. For USB devices, the maximum string length is 126 wide characters (not including the terminating NULL character).

The **iProduct** member of a [USB_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_device_descriptor) structure for a particular interface is set by the [USB common class generic parent driver](https://learn.microsoft.com/windows-hardware/drivers/ddi/) based on the following rules:

- If the **iInterface** member of the [USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor) structure for the interface is nonzero, the **iProduct** member of the USB_DEVICE_DESCRIPTOR structure for the interface is set to the **iInterface** member of the USB_INTERFACE_DESCRIPTOR structure.

- If the interface is grouped by a [USB interface association descriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/) and the **iFunction** member of the interface association descriptor for the interface is nonzero, the **iProduct** member of the USB_DEVICE_DESCRIPTOR structure for the interface is set to the **iFunction** member of the interface association descriptor.

If the supplied buffer is not <= 4093 bytes (2^12 – 3) the call may fail (depending on the underlying protocol, HID/Bluetooth/SPI) with error code ERROR_GEN_FAILURE (0x0000001f)

For more information see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

[HidD_GetManufacturerString](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getmanufacturerstring)

[HidD_GetPhysicalDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getphysicaldescriptor)

[HidD_GetProductString](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getproductstring)

[HidD_GetSerialNumberString](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getserialnumberstring)

[IOCTL_HID_GET_INDEXED_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_indexed_string)

[IOCTL_HID_GET_MANUFACTURER_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_manufacturer_string)

[IOCTL_HID_GET_PRODUCT_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_product_string)

[IOCTL_HID_GET_SERIALNUMBER_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_serialnumber_string)