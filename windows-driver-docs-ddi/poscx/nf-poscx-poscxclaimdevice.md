## Description

PosCxClaimDevice is called to claim a device for exclusive use.

The caller should call [PosCxReleaseDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/poscx/nf-poscx-poscxreleasedevice) when the device is no longer needed.

If the device is already claimed, the caller must wait until access is granted.

## Parameters

### `device` [in]

A handle to a framework device object that represents the device.

### `request` [in]

A handle to a framework request object that represents the request. This request must come from a WDF IO queue.

## Return value

Possible return values are:

| Value | Description |
|---|---|
| **STATUS_SUCCESS** | The device was successfully claimed. |
| **STATUS_PENDING** | The claim request was queued. |
| **STATUS_DEVICE_NOT_READY** | The PosCx library was not successfully initialized. |
| **STATUS_ACCESS_DENIED** | The current owner has retained device ownership. |