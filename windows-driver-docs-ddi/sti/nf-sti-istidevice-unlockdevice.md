# IStiDevice::UnLockDevice

## Description

The **IStiDevice::UnLockDevice** method unlocks a device that was locked by a previous call to [IStiDevice::LockDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-lockdevice).

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

Before the **IStiDevice::UnLockDevice** method releases the **IStiDevice**-level lock on the device, it calls [IStiUSD::UnLockDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-unlockdevice) in the appropriate vendor-supplied minidriver.

Before calling **IStiDevice::UnLockDevice**, clients of the **IStiDevice** COM interface must call [IStillImage::CreateDevice](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543778(v=vs.85)) to obtain an **IStiDevice** interface pointer, which provides access to a specified device.