# IStiDevice::Diagnostic

## Description

The **IStiDevice::Diagnostic** method executes diagnostic tests on a still image device.

## Parameters

### `pBuffer` [in, out]

Caller-supplied pointer to an [STI_DIAG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ns-sti-_sti_diag) structure specifying the type of tests to be run. On return, the structure contains status information.

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

The **IStiDevice::Diagnostic** method calls [IStiUSD::Diagnostic](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-diagnostic), which is exported by vendor-supplied minidrivers. The Scanners and Cameras Control Panel calls **IStiDevice::Diagnostic** when a user presses the Test button.

Before calling **IStiDevice::Diagnostic**, clients of the **IStiDevice** COM interface must call [IStillImage::CreateDevice](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543778(v=vs.85)) to obtain an **IStiDevice** interface pointer, which provides access to a specified device.

A call to **IStiDevice::Diagnostic** must be preceded by a call to [IStiDevice::LockDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-lockdevice) and followed by a call to [IStiDevice::UnLockDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-unlockdevice).