# IOCTL_CHANGER_QUERY_VOLUME_TAGS IOCTL

## Description

Returns volume tag information for the specified elements.

## Parameters

### Major code

### Input buffer

 The buffer at **Irp->AssociatedIrp.SystemBuffer** indicates the starting element for which to return information, the action to perform, and a template to use when searching for volume IDs.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location indicates the size, in bytes, of the parameter buffer, which must be >= **sizeof**([CHANGER_SEND_VOLUME_TAG_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_send_volume_tag_information)).

### Output buffer

The driver returns the [READ_ELEMENT_ADDRESS_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_read_element_address_info) data in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** indicates the size, in bytes, of the parameter buffer for output, which must be >= **sizeof**(READ_ELEMENT_ADDRESS_INFO).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the correct output buffer size, in bytes. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INFO_LENGTH_MISMATCH, STATUS_INSUFFICIENT_RESOURCES, STATUS_INVALID_DEVICE_REQUEST, or STATUS_INVALID_ELEMENT_ADDRESS.

## See also

[READ_ELEMENT_ADDRESS_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_read_element_address_info)