## Description

A still image minidriver's **IStiUSD::GetCapabilities** method returns a still image device's capabilities.

## Parameters

### `pDevCaps`

Caller-supplied pointer to an empty [STI_USD_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/ns-stiusd-_sti_usd_caps) structure.

## Return value

If the operation succeeds, the method should return S_OK. Otherwise, it should return one of the STIERR-prefixed error codes defined in *stierr.h<*.

## Remarks

The **IStiUSD::GetCapabilities** method should set appropriate device capability flags in the caller-supplied [STI_USD_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/ns-stiusd-_sti_usd_caps) structure. It should also set the version number to STI_VERSION.

## See also

[IStiDevice::GetCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-getcapabilities)

[IStiUSD](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)