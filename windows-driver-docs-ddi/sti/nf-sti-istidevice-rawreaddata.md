# IStiDevice::RawReadData

## Description

The **IStiDevice::RawReadData** method reads data from a still image device.

## Parameters

### `lpBuffer` [in, out]

Caller-supplied pointer to a buffer to receive data read from the device.

### `lpdwNumberOfBytes` [in, out]

Caller-supplied pointer to a DWORD. The caller must load the DWORD with the number of bytes in the buffer pointed to by *lpBuffer*. On return, it will contain the number of bytes actually read.

### `lpOverlapped` [in, optional]

Optional, caller-supplied pointer to an OVERLAPPED structure (described in the Microsoft Windows SDK documentation).

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

The **IStiDevice::RawReadData** method calls [IStiUSD::RawReadData](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-rawreaddata), which is exported by vendor-supplied minidrivers.

Before calling **IStiDevice::RawReadData**, clients of the **IStiDevice** COM interface must call [IStillImage::CreateDevice](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543778(v=vs.85)) to obtain an **IStiDevice** interface pointer, which provides access to a specified device.

A call to **IStiDevice::RawReadData** must be preceded by a call to [IStiDevice::LockDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-lockdevice) and followed by a call to [IStiDevice::UnLockDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-unlockdevice).

## See also

[IStiDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)

[IStiDevice::RawReadCommand](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-rawreadcommand)