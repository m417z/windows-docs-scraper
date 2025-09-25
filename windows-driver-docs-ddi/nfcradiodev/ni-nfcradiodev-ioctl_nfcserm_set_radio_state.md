# IOCTL_NFCSERM_SET_RADIO_STATE IOCTL

## Description

This IOCTL is used by the SE radio management application or service to set the current radio power state of the proximity device.

## Parameters

### Major code

### Input buffer

 [NFCRM_SET_RADIO_STATE structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcradiodev/ns-nfcradiodev-_nfcrm_set_radio_state)

### Input buffer length

sizeof(NFCRM_SET_RADIO_STATE)

### Output buffer

None

### Output buffer length

None

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to **STATUS_SUCCESS** if the request is successful. Possible error codes are:

| Return Code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_STATE** | This code is returned when the device is already in the proximity radio power state that is being set by the client. |
| **STATUS_INVALID_PARAMETER** | This code is returned when the output buffer is non-zero. |