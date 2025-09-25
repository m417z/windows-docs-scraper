# IStiUSD::RawReadData

## Description

A still image minidriver's **IStiUSD::RawReadData** method reads data from a still image device.

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

A still image minidriver typically implements this method by calling **ReadFile** (described in the Windows SDK documentation).

For USB devices, better performance can be achieved if read requests are aligned to maximum packet size boundaries. Maximum packet sizes can be obtained by calling [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol), specifying the [IOCTL_GET_CHANNEL_ALIGN_RQST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ni-usbscan-ioctl_get_channel_align_rqst) I/O control code.

## See also

[IStiDevice::RawReadData](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-rawreaddata)

[IStiUSD](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)