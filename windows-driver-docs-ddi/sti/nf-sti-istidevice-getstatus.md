# IStiDevice::GetStatus

## Description

The **IStiDevice::GetStatus** method returns a still image device's status information.

## Parameters

### `pDevStatus` [in, out]

Caller-supplied pointer to an [STI_DEVICE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ns-sti-_sti_device_status) structure. The caller must set the **dwSize** and **StatusMask** members.

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

The **IStiDevice::GetStatus** method returns device status information in the caller-supplied [STI_DEVICE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ns-sti-_sti_device_status) structure. It obtains the status by calling [IStiUSD::GetStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-getstatus), which is exported by vendor-supplied minidrivers.

Before calling **IStiDevice::GetStatus**, clients of the **IStiDevice** COM interface must call [IStillImage::CreateDevice](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543778(v=vs.85)) to obtain an **IStiDevice** interface pointer, which provides access to a specified device.

A call to **IStiDevice::GetStatus** must be preceded by a call to [IStiDevice::LockDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-lockdevice) and followed by a call to [IStiDevice::UnLockDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-unlockdevice).