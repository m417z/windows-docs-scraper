# IStiDeviceControl::GetMyDeviceOpenMode

## Description

The **IStiDeviceControl::GetMyDeviceOpenMode** method allows a still image minidriver to obtain the transfer mode that an application specified when it created an instance of a still image device.

## Parameters

### `pdwOpenMode`

Receives the mode flag that an application previously specified as the *dwMode* argument to [IStillImage::CreateDevice](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543778(v=vs.85)).

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

A still image minidriver receives an **IStiDeviceControl** interface pointer as an input argument to its [IStiUSD::Initialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-initialize) method.