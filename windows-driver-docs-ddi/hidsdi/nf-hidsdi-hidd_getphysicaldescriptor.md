# HidD_GetPhysicalDescriptor function

## Description

The **HidD_GetPhysicalDescriptor** routine returns the _Physical Descriptor_ of a [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) that identifies the collection's physical device.

_Physical Descriptor_ is used to indicate what physical part of the human body is used to activate the controls on a device. For example, a _Physical Descriptor_ might indicate that the right hand thumb is used to activate button 5.

Note that _Physical Descriptors_ are entirely optional. They add complexity and offer very little in return for most devices. However, some devices, particularly those with a large number of identical controls (for example, buttons) will find that _Physical Descriptors_ help different applications assign functionality to these controls in a more consistent manner. See [HID specification](https://www.usb.org/hid) for more info.

## Parameters

### `HidDeviceObject` [in]

Specifies an open handle to a top-level collection.

### `Buffer` [out]

Pointer to a caller-allocated buffer that the routine uses to return the requested physical descriptor.

### `BufferLength` [in]

Specifies the length, in bytes, of the buffer at *Buffer*.

## Return value

**HidD_GetPhysicalDescriptor** returns **TRUE** if it succeeds; otherwise, it returns **FALSE**. Use [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get extended error information.

## Remarks

Only user-mode applications can call **HidD_GetPhysicalDescriptor**. Kernel-mode drivers can use an [IOCTL_GET_PHYSICAL_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_get_physical_descriptor) request.

For more information, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

[HidD_GetIndexedString](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getindexedstring)

[HidD_GetManufacturerString](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getmanufacturerstring)

[HidD_GetProductString](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getproductstring)

[HidD_GetSerialNumberString](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getserialnumberstring)

[IOCTL_GET_PHYSICAL_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_get_physical_descriptor)