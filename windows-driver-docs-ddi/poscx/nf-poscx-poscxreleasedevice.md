## Description

PosCxReleaseDevice is called to release a device that was previously claimed with [PosCxClaimDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/poscx/nf-poscx-poscxclaimdevice). Once the device is released, the next pending claim requester is promoted.

## Parameters

### `device` [in]

A handle to a framework device object that represents the device.

### `fileObject` [in]

 A handle to a framework file object that identifies the caller.

## Return value

Possible return values are:

| Value | Description |
|---|---|
| **STATUS_SUCCESS** | The device was successfully released. |
| **STATUS_ACCESS_DENIED** | The calling thread is not the owner of the device. |
| **STATUS_DEVICE_NOT_READY** | The PosCx library was not successfully initialized. |
| **STATUS_INVALID_PARAMETER** | The specified *fileObject* is invalid. |

## See also

[PosCxClaimDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/poscx/nf-poscx-poscxclaimdevice)