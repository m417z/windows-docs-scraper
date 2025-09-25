# IStiDevice::GetCapabilities

## Description

The **IStiDevice::GetCapabilities** method returns a still image device's capabilities.

## Parameters

### `pDevCaps` [in, out]

Caller-supplied pointer to an empty [STI_DEV_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ns-sti-_sti_dev_caps) structure.

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

The **IStiDevice::GetCapabilities** method returns device capability flags in the caller-supplied [STI_DEV_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ns-sti-_sti_dev_caps) structure.

Before calling **IStiDevice::GetCapabilities**, clients of the **IStiDevice** COM interface must call [IStillImage::CreateDevice](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543778(v=vs.85)) to obtain an **IStiDevice** interface pointer, which provides access to a specified device.