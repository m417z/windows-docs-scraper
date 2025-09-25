# IOCTL_POINT_OF_SERVICE_RETAIN_DEVICE IOCTL

## Description

This I/O control function is used to keep a claim on a device when a client is notified that its claim on the device is being contested by another client.

## Parameters

### Major code

### Input buffer

Not used with this operation; set to **NULL**.

### Input buffer length

Not used with this operation; set to **0** (zero).

### Output buffer

Not used with this operation; set to **NULL**.

### Output buffer length

Not used with this operation; set to **0** (zero)

### Input/output buffer

### Input/output buffer length

### Status block

Returns **TRUE** if successful; otherwise, returns **FALSE**.

## Remarks

To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following list shows common error values:

- STATUS_ACCESS_DENIED: The device is currently claimed by another client.

- STATUS_DEVICE_NOT_READY: The POS library has not successfully initialized.

This IOCTL only works if the client has previously called [IOCTL_POINT_OF_SERVICE_CLAIM_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ni-pointofservicedriverinterface-ioctl_point_of_service_claim_device).

When handling this IOCTL, the driver can call [PosCxRetainDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/poscx/nf-poscx-poscxretaindevice). The driver writer does not need to handle claim contention because the PosCx library determines who gets the claim.