# HidD_GetManufacturerString function

## Description

The **HidD_GetManufacturerString** routine returns a [top-level collection's](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) embedded string that identifies the manufacturer.

## Parameters

### `HidDeviceObject` [in]

Specifies an open handle to a top-level collection.

### `Buffer` [out]

Pointer to a caller-allocated buffer that the routine uses to return the collection's manufacturer string. The routine returns a NULL-terminated wide character string in a human-readable format.

### `BufferLength` [in]

Specifies the length, in bytes, of a caller-allocated buffer provided at *Buffer*. If the buffer is not large enough to return the entire NULL-terminated embedded string, the routine returns nothing in the buffer. The supplied buffer must be <= 4093 bytes (2^12 – 3).

## Return value

HidD_HidD_GetManufacturerString returns **TRUE** if it returns the entire NULL-terminated embedded string. Otherwise, the routine returns **FALSE**. Use [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get extended error information.

## Remarks

Only user-mode applications can call **HidD_GetManufacturerString**. Kernel-mode drivers can use an [IOCTL_HID_GET_MANUFACTURER_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_manufacturer_string) request.

The maximum possible number of characters in an embedded string is device specific. For USB devices, the maximum string length is 126 wide characters (not including the terminating NULL character).

If the supplied buffer is not <= 4093 bytes (2^12 – 3) the call may fail (depending on the underlying protocol, HID/Bluetooth/SPI) with error code ERROR_GEN_FAILURE (0x0000001f).

For more information see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

[HidD_GetIndexedString](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getindexedstring)

[HidD_GetPhysicalDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getphysicaldescriptor)

[HidD_GetProductString](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getproductstring)

[HidD_GetSerialNumberString](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getserialnumberstring)

[IOCTL_HID_GET_INDEXED_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_indexed_string)

[IOCTL_HID_GET_MANUFACTURER_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_manufacturer_string)

[IOCTL_HID_GET_PRODUCT_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_product_string)

[IOCTL_HID_GET_SERIALNUMBER_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_serialnumber_string)