## Description

The **IStiDevice::GetLastErrorInfo** method returns information about the last known error associated with a still image device.

## Parameters

### `pLastErrorInfo` [out]

Caller-supplied pointer to an [STI_ERROR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ns-sti-_error_infow) structure to receive error information.

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h<*.

## Remarks

The **IStiDevice::GetLastErrorInfo** method returns information about the most recent error by filling in the caller-supplied [STI_ERROR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ns-sti-_error_infow) structure. The method calls [IStiUSD::GetLastErrorInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-getlasterrorinfo), which is exported by vendor-supplied minidrivers.

Before calling **IStiDevice::GetLastErrorInfo**, clients of the **IStiDevice** COM interface must call [IStillImage::CreateDevice](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543778(v=vs.85)) to obtain an **IStiDevice** interface pointer, which provides access to a specified device.