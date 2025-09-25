# IStiUSD::RawWriteCommand

## Description

A still image minidriver's **IStiDevice::RawWriteCommand** method sends command information to a still image device.

## Parameters

### `lpBuffer`

Caller-supplied pointer to a buffer containing data to be sent to the device.

### `nNumberOfBytes`

Caller-supplied number of bytes to be written. This is the number of bytes in the buffer pointed to by *lpBuffer*.

### `lpOverlapped`

Optional, caller-supplied pointer to an OVERLAPPED structure (described in the Microsoft Windows SDK documentation).

## Return value

If the operation succeeds, the method should return S_OK. Otherwise, it should return one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

It is only necessary to call **IStiUSD::RawWriteCommand** if commands and data are written to a device by different methods. For other devices, [IStiUSD::RawWriteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-rawwritedata) can be used for both commands and data. If the call is not implemented, it must return STIERR_UNSUPPORTED.

Implementation of this method, along with the meaning of buffer contents, are vendor-defined.

## See also

[IStiDevice::RawWriteCommand](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-rawwritecommand)

[IStiUSD](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)