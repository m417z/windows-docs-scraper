# IOCTL_HID_GET_COLLECTION_INFORMATION IOCTL

## Description

The IOCTL_HID_GET_COLLECTION_INFORMATION request obtains a [top-level collection's](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) [HID_COLLECTION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ns-hidclass-_hid_collection_information) structure. This information includes the size, in bytes, of a collection's [preparsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data).

For general information about HIDClass devices, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## Parameters

### Major code

### Input buffer

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the output buffer, which must be >= **sizeof**(HID_COLLECTION_INFORMATION).

### Input buffer length

Greater than or equal to **sizeof**(HID_COLLECTION_INFORMATION).

### Output buffer

**Irp->AssociatedIrp.SystemBuffer** points to a buffer that will receive the collection information. This data will be formatted in the requester-supplied buffer as a HID_COLLECTION_INFORMATION structure.

### Output buffer length

The size of a HID_COLLECTION_INFORMATION structure.

### Input/output buffer

### Input/output buffer length

### Status block

The HID class driver sets the following fields of **Irp->IoStatus**:

* **Information** is set to **sizeof**(HID_COLLECTION_INFORMATION) if the data was retrieved successfully.
* **Status** is set to STATUS_SUCCESS if the transfer completed without error. Otherwise, it is set to an appropriate NTSTATUS error code.

## See also

[HID_COLLECTION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ns-hidclass-_hid_collection_information)