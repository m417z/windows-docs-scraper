# IStiUSD::LockDevice

## Description

A still image minidriver's **IStiUSD::LockDevice** method locks a device for exclusive use by the caller.

## Return value

If the operation succeeds, the method should return S_OK. Otherwise, it should return one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

If you are writing a driver for a device connected to a serial port, you might want to call [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) from within the driver's **IStiUSD::LockDevice** method if the device was opened in status mode. This will prohibit other applications from using the port (which might be supporting other devices) while status information is being obtained. For more information, see [Transfer Modes](https://learn.microsoft.com/windows-hardware/drivers/image/transfer-modes).

## See also

[IStiDevice::LockDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-lockdevice)

[IStiUSD](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)