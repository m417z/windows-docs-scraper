# _STI_USD_CAPS structure

## Description

The STI_USD_CAPS structure is used as a parameter for the [IStiUSD::GetCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-getcapabilities) method.

## Members

### `dwVersion`

STI version number. This value must be STI_VERSION, defined in *Sti.h*.

### `dwGenericCaps`

Bit flags indicating driver capabilities. The following flags are defined in *Stiusd.h*.

#### STI_USD_GENCAP_NATIVE_PUSHSUPPORT

The driver supports asynchronous device notifications.

#### STI_USD_GENCAP_OPEN_DEVICE_FOR_ME

*Not used.*