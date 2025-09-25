# IStiDevice::Release

## Description

The **IStiDevice::Release** method closes the instance of the COM object that was created by a previous call to [IStillImage::CreateDevice](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543778(v=vs.85)), and removes access to the object's interface.

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.