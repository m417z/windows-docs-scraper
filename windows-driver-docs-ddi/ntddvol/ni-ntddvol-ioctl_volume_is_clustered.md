# IOCTL_VOLUME_IS_CLUSTERED IOCTL

## Description

Allows a driver or application to determine if a volume is clustered.

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

 If the volume is clustered, the IOCTL returns **STATUS_SUCCESS**. If the volume is not clustered, the IOCTL returns **STATUS_UNSUCCESSFUL**.

## Remarks

For an invalid disk type, such as dynamic disk, the disk management component will return **STATUS_INVALID_DEVICE_REQUEST**.