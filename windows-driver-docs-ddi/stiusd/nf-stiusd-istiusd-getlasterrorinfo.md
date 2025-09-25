# IStiUSD::GetLastErrorInfo

## Description

A still image minidriver's **IStiUSD::GetLastErrorInfo** method returns information about the last known error associated with a still image device.

## Parameters

### `pLastErrorInfo`

Caller-supplied pointer to an [STI_ERROR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ns-sti-_error_infow) structure to receive error information.

## Return value

If the operation succeeds, the method should return S_OK. Otherwise, it should return one of the STIERR-prefixed error codes defined in *Stierr.h*.

## Remarks

The method should fill in the received [STI_ERROR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ns-sti-_error_infow) structure.

## See also

[IStiDevice::GetLastErrorInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-getlasterrorinfo)

[IStiUSD](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)