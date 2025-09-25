# IStiDevice::RawWriteData

## Description

The **IStiDevice::RawWriteData** method writes data to a still image device.

## Parameters

### `lpBuffer` [in]

Caller-supplied pointer to a buffer containing data to be sent to the device.

### `nNumberOfBytes`

Caller-supplied number of bytes to be written. This is the number of bytes in the buffer pointed to by *lpBuffer*.

### `lpOverlapped` [in, optional]

Optional, caller-supplied pointer to an OVERLAPPED structure (described in the Microsoft Windows SDK documentation).

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

The **IStiDevice::RawWriteData** method calls [IStiUSD::RawWriteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-rawwritedata), which is exported by vendor-supplied minidrivers.

Before calling **IStiDevice::RawWriteData**, clients of the **IStiDevice** COM interface must call [IStillImage::CreateDevice](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543778(v=vs.85)) to obtain an **IStiDevice** interface pointer, which provides access to a specified device.

A call to **IStiDevice::RawWriteData** must be preceded by a call to [IStiDevice::LockDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-lockdevice) and followed by a call to [IStiDevice::UnLockDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-unlockdevice).

## See also

[IStiDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)

[IStiDevice::RawWriteCommand](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-rawwritecommand)