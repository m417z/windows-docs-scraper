# _MSR_AUTHENTICATE_DEVICE structure

## Description

This structure provides the authentication information used to authenticate a device.

## Members

### `Size`

If the optional **SessionId** is present, this will include the size of **SessionId[MSR_SESSION_ID_SIZE]**

### `Challenge1`

The challenge token.

### `SessionId`

The session ID. This is primarily used to identify each transaction so that you can prevent errors such as processing the same transaction twice.

## See also

[IOCTL_POINT_OF_SERVICE_MSR_AUTHENTICATE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ni-pointofservicedriverinterface-ioctl_point_of_service_msr_authenticate_device)