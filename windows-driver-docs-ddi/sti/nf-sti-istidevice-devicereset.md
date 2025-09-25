# IStiDevice::DeviceReset

## Description

The **IStiDevice::DeviceReset** method resets a still image device to a known state.

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

The **IStiDevice::DeviceReset** method resets the device by calling [IStiUSD::DeviceReset](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-devicereset), which is exported by vendor-supplied minidrivers.

Before calling **IStiDevice::DeviceReset**, clients of the **IStiDevice** COM interface must call [IStillImage::CreateDevice](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543778(v=vs.85)) to obtain an **IStiDevice** interface pointer, which provides access to a specified device.

A call to **IStiDevice::DeviceReset** must be preceded by a call to [IStiDevice::LockDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-lockdevice) and followed by a call to [IStiDevice::UnLockDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-unlockdevice).