# IOCTL_STORAGE_RESERVE IOCTL

## Description

Claims a device for the exclusive use of the caller on a bus that supports multiple initiators and the concept of reserving a device, such as a SCSI bus.

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

The **Information** field is set to zero. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INVALID_DEVICE_REQUEST, STATUS_DEVICE_NOT_CONNECTED, or STATUS_IO_TIMEOUT.