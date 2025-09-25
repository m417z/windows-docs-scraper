# IStiUSD::UnLockDevice

## Description

A still image minidriver's **IStiUSD::UnLockDevice** method unlocks a device that was locked by a previous call to [IStiUSD::LockDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-lockdevice).

## Return value

If the operation succeeds, the method should return S_OK. Otherwise, it should return one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

If a driver's [IStiUSD::LockDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-lockdevice) method called [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea), then **IStiUSD::UnlockDevice** should call **CloseHandle**.

## See also

[IStiDevice::UnLockDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-unlockdevice)

[IStiUSD](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)