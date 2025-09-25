# IOCTL_HID_GET_PRODUCT_STRING IOCTL

## Description

The IOCTL_HID_GET_PRODUCT_STRING request obtains a [top-level collection's](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) embedded string that identifies the manufacturer's product. The retrieved string is a NULL-terminated wide character string in a human-readable format.

For general information about HIDClass devices [HID Collections(/windows-hardware/drivers/hid/hid-collections).

## Parameters

### Major code

### Input buffer

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the output buffer. If the output buffer is not large enough to hold the entire NULL-terminated embedded string, the request returns nothing in the output buffer.

### Input buffer length

The maximum possible number of characters in an embedded string is device specific. For USB devices, the maximum string length is 126 wide characters (not including the terminating NULL character).

### Output buffer

**Irp->MdlAddress** points to a buffer to receive the product ID string (a NULL-terminated wide character string).

### Output buffer length

The length of a NULL-terminated wide character string. The supplied buffer must be <= 4093 bytes (2^12 – 3).

### Input/output buffer

### Input/output buffer length

### Status block

The HID class driver sets the following fields of **Irp->IoStatus**:

- **Information** is set to the number of bytes transferred from the device.

- **Status** is set to STATUS_SUCCESS if the transfer completed without error. Otherwise, it is set to an appropriate NTSTATUS error code.

## See also

[HidD_GetIndexedString](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getindexedstring)

[HidD_GetManufacturerString](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getmanufacturerstring)

[HidD_GetPhysicalDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getphysicaldescriptor)

[HidD_GetProductString](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getproductstring)

[HidD_GetSerialNumberString](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getserialnumberstring)

[IOCTL_HID_GET_MANUFACTURER_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_manufacturer_string)

[IOCTL_HID_GET_PRODUCT_STRING]()

[IOCTL_HID_GET_SERIALNUMBER_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_serialnumber_string)