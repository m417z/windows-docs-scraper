# IOCTL_STORAGE_RESET_DEVICE IOCTL

## Description

If possible, resets a non-SCSI storage device without affecting other devices on the bus. Device reset for SCSI devices is not supported. The caller requires only read access to issue a device reset and, to comply, the device must be capable of responding to I/O requests. If the device reset succeeds, pending I/O requests are canceled.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to zero. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INSUFFICIENT_RESOURCES, STATUS_NOT_IMPLEMENTED, or STATUS_INVALID_DEVICE_REQUEST.