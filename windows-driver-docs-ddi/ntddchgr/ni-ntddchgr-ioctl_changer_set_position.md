# IOCTL_CHANGER_SET_POSITION IOCTL

## Description

Sets the changer's robotic transport mechanism to the specified element address, typically to optimize moving or exchanging media by positioning the transport beforehand.

## Parameters

### Major code

### Input buffer

 The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a [CHANGER_SET_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_set_position) structure that specifies the transport to move and the destination. If the **Flip** member is **TRUE** and the device supports two-sided media, the media currently carried by the transport should be flipped.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location indicates the size, in bytes, of the parameter buffer, which must be >= **sizeof**(CHANGER_SET_POSITION).

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to **sizeof**(CHANGER_SET_POSITION). The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INFO_LENGTH_MISMATCH, STATUS_INSUFFICIENT_RESOURCES, STATUS_INVALID_DEVICE_REQUEST, or STATUS_INVALID_PARAMETER.

## See also

[CHANGER_SET_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_set_position)

[ChangerSetPosition](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changersetposition)