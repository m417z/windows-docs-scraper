# IStiDevice::LockDevice

## Description

The **IStiDevice::LockDevice** method locks a device for exclusive use by the caller.

## Parameters

### `dwTimeOut` [in]

Caller-supplied time-out value, in milliseconds. If the lock is not obtained in this time period, an error is returned.

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

Clients of the **IStiDevice** COM interface must call **IStiDevice::LockDevice** before calling the following methods:

[IStiDevice::DeviceReset](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-devicereset)

[IStiDevice::Diagnostic](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-diagnostic)

[IStiDevice::Escape](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-escape)

[IStiDevice::GetStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-getstatus)

[IStiDevice::RawReadCommand](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-rawreadcommand)

[IStiDevice::RawReadData](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-rawreaddata)

[IStiDevice::RawWriteCommand](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-rawwritecommand)

[IStiDevice::RawWriteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-rawwritedata)

If the **IStiDevice::LockDevice** method is able to obtain an **IStiDevice**-level lock on the device within the specified time-out period, it then calls [IStiUSD::LockDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-lockdevice) in the appropriate vendor-supplied minidriver.

Each call to **IStiDevice::LockDevice** must be paired with a call to [IStiDevice::UnLockDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-unlockdevice).

Before calling **IStiDevice::LockDevice**, clients of the **IStiDevice** COM interface must call [IStillImage::CreateDevice](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543778(v=vs.85)) to obtain an **IStiDevice** interface pointer, which provides access to a specified device.