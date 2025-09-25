# IStiUSD::GetLastError

## Description

The **IStiUSD::GetLastError** method returns the last known error associated with a still image device.

## Parameters

### `pdwLastDeviceError`

Caller-supplied pointer to a buffer in which the error code will be stored.

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## See also

[IStiDevice::GetLastError](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-getlasterror)

[IStiUSD](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)