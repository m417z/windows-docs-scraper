# IOCTL_NFCSERM_QUERY_RADIO_STATE IOCTL

## Description

This IOCTL is used by the SE radio management application or service to query the current radio power state of the proximity device.

## Parameters

### Major code

### Input buffer

None

### Input buffer length

None

### Output buffer

 [NFCRM_RADIO_STATE structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcradiodev/ns-nfcradiodev-_nfcrm_set_radio_state)

### Output buffer length

sizeof(NFCRM_RADIO_STATE)

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to **STATUS_SUCCESS** if the request is successful. Possible error codes are:

| Return Code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | This code is returned when the input buffer is non-zero. |