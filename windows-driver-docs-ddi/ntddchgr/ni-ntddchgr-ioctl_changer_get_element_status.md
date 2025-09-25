# IOCTL_CHANGER_GET_ELEMENT_STATUS IOCTL

## Description

Returns the status of all elements or the status of a specified number of elements of a particular type.

For a description of the possible element types, see [CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element).

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains the [CHANGER_READ_ELEMENT_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_read_element_status) data that indicates the element type and the number of elements for which to return status.

If the caller sets the **VolumeTagInfo** member of CHANGER_READ_ELEMENT_STATUS to **TRUE**, the element status that is returned will include volume tag information.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location indicates the size, in bytes, of the parameter buffer for input, which must be >= **sizeof**(CHANGER_READ_ELEMENT_STATUS).

### Output buffer

The changer miniclass driver returns the changer element status data in the buffer at **Irp->AssociatedIrp.SystemBuffer**. Some elements of type **ChangerDrive** return product information data. If the device provides product information, the miniclass driver will report the element status data in a structure of type [CHANGER_ELEMENT_STATUS_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element_status_ex). The miniclass driver sets ELEMENT_STATUS_PRODUCT_DATA in the **Flags** member of the structure to indicate that it contains product information data. For elements of all types other than **ChangerDrive**, the driver reports element status data in a structure of type [CHANGER_ELEMENT_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element_status).

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** indicates the size, in bytes, of the parameter buffer for output. For elements of type **ChangerDrive**, this value must be >= *NumberOfElements* * **sizeof**(CHANGER_ELEMENT_STATUS_EX). For elements of all other types, this value must be >= *NumberOfElements* * **sizeof**(CHANGER_ELEMENT_STATUS).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes returned. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_BUFFER_TOO_SMALL, STATUS_INFO_LENGTH_MISMATCH, STATUS_INSUFFICIENT_RESOURCES, STATUS_INVALID_ELEMENT_ADDRESS, or STATUS_INVALID_PARAMETER.

## See also

[CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element)

[CHANGER_ELEMENT_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element_status)

[CHANGER_ELEMENT_STATUS_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element_status_ex)

[ChangerGetElementStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changergetelementstatus)