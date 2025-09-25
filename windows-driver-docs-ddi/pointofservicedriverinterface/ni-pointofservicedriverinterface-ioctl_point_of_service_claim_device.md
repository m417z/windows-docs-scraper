# IOCTL_POINT_OF_SERVICE_CLAIM_DEVICE IOCTL

## Description

The I/O control function claims the device for exclusive access.

## Parameters

### Major code

### Input buffer

Not used with this operation; set to **NULL**.

### Input buffer length

Not used with this operation; set to **0** (zero).

### Output buffer

Not used with this operation; set to **NULL**.

### Output buffer length

Not used with this operation; set to **0** (zero).

### Input/output buffer

### Input/output buffer length

### Status block

Returns **TRUE** if successful; otherwise, returns **FALSE**.

## Remarks

To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following list shows common error values:

- STATUS_ACCESS_DENIED: The claim could not be taken from the current claim owner.

- STATUS_DEVICE_NOT_READY: The POS library is not initialized.

- STATUS_PENDING: The claim request was queued.

This IOCTL is handled by the PosCx library. The driver writer does not need to handle this IOCTL. Instead, call [PosCxClaimDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/poscx/nf-poscx-poscxclaimdevice). If the POS device is already claimed by another client, then the POS device driver is responsible for notifying the claim owner using a [ReleaseDeviceRequested](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/dn790033(v=vs.85)) event and waiting for the claim owner to retain its claim within 50 milliseconds. If the claim is not reaffirmed, then the current claim owner's claim is automatically revoked and granted to the challenging client.