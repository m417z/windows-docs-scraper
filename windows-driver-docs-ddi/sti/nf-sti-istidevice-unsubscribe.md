# IStiDevice::UnSubscribe

## Description

The **IStiDevice::UnSubscribe** method removes the caller from the list of applications registered to receive notification of device events.

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

Before calling **IStiDevice::UnSubscribe**, clients of the **IStiDevice** COM interface must call [IStillImage::CreateDevice](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543778(v=vs.85)) to obtain an **IStiDevice** interface pointer, which provides access to a specified device.

## See also

[IStiDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)

[IStiDevice::Subscribe](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-subscribe)