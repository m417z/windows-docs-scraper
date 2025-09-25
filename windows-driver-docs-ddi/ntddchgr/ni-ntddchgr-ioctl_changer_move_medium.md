# IOCTL_CHANGER_MOVE_MEDIUM IOCTL

## Description

Moves a piece of media from a source element to a destination.

## Parameters

### Major code

### Input buffer

 The buffer at **Irp->AssociatedIrp.SystemBuffer** contains the [CHANGER_MOVE_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_move_medium) data, which indicates the transport to use for the operation, the source, the destination, and whether the medium should be flipped, assuming the device supports two-sided media.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location indicates the size, in bytes, of the parameter buffer, which must be >= **sizeof**(CHANGER_MOVE_MEDIUM).

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to **sizeof**(CHANGER_MOVE_MEDIUM). The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_DESTINATION_ELEMENT_FULL, STATUS_INFO_LENGTH_MISMATCH, STATUS_INSUFFICIENT_RESOURCES, STATUS_INVALID_DEVICE_REQUEST, STATUS_INVALID_ELEMENT_ADDRESS, STATUS_INVALID_PARAMETER, or STATUS_SOURCE_ELEMENT_EMPTY.

## See also

[CHANGER_MOVE_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_move_medium)

[ChangerMoveMedium](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changermovemedium)