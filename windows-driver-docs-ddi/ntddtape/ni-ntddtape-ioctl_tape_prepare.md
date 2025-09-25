# IOCTL_TAPE_PREPARE IOCTL

## Description

Loads or unloads the tape, resets tape tension, locks or unlocks the ejection mechanism, or formats the tape.

## Parameters

### Major code

### Input buffer

 The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a [TAPE_PREPARE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ns-ntddtape-_tape_prepare) structure that indicates the type of operation.

If the **Immediate** member is **TRUE**, the operation should be asynchronous.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location indicates the size, in bytes, of the parameter buffer, which must be >= **sizeof**(TAPE_PREPARE).

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes transferred. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_NO_SUCH_DEVICE, STATUS_IO_TIMEOUT, STATUS_IO_DEVICE_ERROR, STATUS_INSUFFICIENT_RESOURCES, STATUS_DEVICE_NOT_CONNECTED, STATUS_MEDIA_WRITE_PROTECTED, STATUS_NO_MEDIA_IN_DEVICE, or STATUS_VERIFY_REQUIRED.

## See also

[TAPE_PREPARE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ns-ntddtape-_tape_prepare)

[TAPE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ne-minitape-_tape_status)

[TapeMiniPrepare](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine)