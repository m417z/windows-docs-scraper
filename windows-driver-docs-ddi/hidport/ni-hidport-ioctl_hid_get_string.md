# IOCTL_HID_GET_STRING IOCTL

## Description

The IOCTL_HID_GET_STRING request obtains a manufacturer ID, product ID, or serial number for a [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections). The retrieved string is a NULL-terminated wide character string in a human-readable format.

For general information about HIDClass devices, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## Parameters

### Major code

### Input buffer

IOCTL_HID_GET_STRING makes use of two input buffers.

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the locked-down output buffer at **Irp->UserBuffer**. If the output buffer is not large enough to hold the entire NULL-terminated embedded string, the request returns nothing in the output buffer. The maximum possible number of characters in an embedded string is device specific. For USB devices, the maximum string length is 126 wide characters (not including the terminating NULL character).

**Parameters.DeviceIoControl.Type3InputBuffer** in the I/O stack location of the IRP contains a composite value. The two most significant bytes contain the language ID of the string to be retrieved. The two least significant bytes contain one of the following three constant values:

* HID_STRING_ID_IMANUFACTURER
* HID_STRING_ID_IPRODUCT
* HID_STRING_ID_ISERIALNUMBER

The HID minidriver determines which of these three constants is present in the lower two bytes of the input buffer, then it must retrieve the corresponding string index from the device descriptor. Device descriptor information is stored in the device extension of a top-level collection associated with the device.

It is important not to confuse these three constants with the actual string indices of the IDs. These constants represent the offsets in the device descriptor where the corresponding string indices can be found.

For example, HID_STRING_ID_IMANUFACTURER indicates the location in the device descriptor where the index for the manufacturer ID is found. This index, in turn, serves as an offset into the string descriptor where the human-readable form of the manufacturer ID is located.

### Input buffer length

The size of the **OutputBufferLength** and the size of the **Type3InputBuffer**.

### Output buffer

The HID minidriver fills the buffer at **Irp->UserBuffer** with the requested string (a NULL-terminated wide character string).

### Output buffer length

The size of the **UserBuffer**.

### Input/output buffer

### Input/output buffer length

### Status block

HID minidrivers that carry out the I/O to the device set the following fields of **Irp->IoStatus**:

* **Information** is set to the number of bytes transferred from the device.
* **Status** is set to STATUS_SUCCESS if the transfer completed without error. Otherwise, it is set to an appropriate NTSTATUS error code.

HID minidrivers that call other drivers with this IOCTL to carry out the I/O to their device, should ensure that the **Information** field of the status block is correct and not change the contents of the **Status** field.

## See also

[HidD_GetIndexedString](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getindexedstring)

[HidD_GetManufacturerString](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getmanufacturerstring)

[HidD_GetProductString](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getproductstring)

[HidD_GetSerialNumberString](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getserialnumberstring)

[IOCTL_HID_GET_INDEXED_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_indexed_string)

[IOCTL_HID_GET_MANUFACTURER_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_manufacturer_string)

[IOCTL_HID_GET_PRODUCT_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_product_string)

[IOCTL_HID_GET_SERIALNUMBER_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_serialnumber_string)