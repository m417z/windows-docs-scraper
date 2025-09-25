# IStiUSD::RawReadCommand

## Description

A still image minidriver's **IStiUSD::RawReadCommand** method reads command information from a still image device.

## Parameters

### `lpBuffer`

Caller-supplied pointer to a buffer to receive data read from the device.

### `lpdwNumberOfBytes`

Caller-supplied pointer to a DWORD. The caller loads the DWORD with the number of bytes in the buffer pointed to by *lpBuffer*. The driver must replace this value with the number of bytes actually read.

### `lpOverlapped`

Optional, caller-supplied pointer to an OVERLAPPED structure (described in the Microsoft Windows SDK documentation).

## Return value

If the operation succeeds, the method should return S_OK. Otherwise, it should return one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

It is only necessary to implement **IStiUSD::RawReadCommand** if command and data information are read from a device by different methods. For other devices, [IStiUSD::RawReadData](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-rawreaddata) can be used for both commands and data. If the call is not implemented, it must return STIERR_UNSUPPORTED.

Implementation of this method, along with the meaning of buffer contents, are vendor-defined.

## See also

[IStiDevice::RawReadCommand](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-rawreadcommand)

[IStiUSD](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)