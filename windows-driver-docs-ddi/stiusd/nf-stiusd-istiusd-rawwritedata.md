## Description

A still image minidriver's **IStiUSD::RawWriteData** method writes data to a still image device.

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

A still image minidriver typically implements this method by calling **WriteFile** (described in the Windows SDK documentation).

## See also

[IStiDevice::RawWriteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-rawwritedata)

[IStiUSD](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)