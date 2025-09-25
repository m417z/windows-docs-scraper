# IStiDevice::GetLastError

## Description

The **IStiDevice::GetLastError** method returns the last known error associated with a still image device.

## Parameters

### `pdwLastDeviceError` [out]

Caller-supplied pointer to a buffer in which the error code will be stored.

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

Before calling IStiDevice::GetLastError, clients of the IStiDevice COM interface must call [IStillImage::CreateDevice](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543778(v=vs.85)) to obtain an IStiDevice interface pointer, which provides access to a specified device.