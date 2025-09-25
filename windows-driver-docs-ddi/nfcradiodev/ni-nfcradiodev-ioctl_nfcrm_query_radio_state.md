# IOCTL_NFCRM_QUERY_RADIO_STATE IOCTL

## Description

This IOCTL is used by the radio management application or service to query the current radio power state of the proximity device.

## Parameters

### Major code

### Input buffer

None

### Input buffer length

None

### Output buffer

 [NFCRM_RADIO_STATE structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcradiodev/ns-nfcradiodev-_nfcrm_radio_state)

### Output buffer length

sizeof(NFCRM_RADIO_STATE)

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to **STATUS_SUCCESS** if the request is successful.

## Remarks

The **STATUS_INVALID_PARAMETER** return code is no longer required. A bug was discovered in Windows 10 build 10240, that Windows would send a non-null input parameter with this IOCTL. This bug was fixed in later versions of Windows. To simplify code, drivers can ignore the input parameters in all versions of Windows 10.