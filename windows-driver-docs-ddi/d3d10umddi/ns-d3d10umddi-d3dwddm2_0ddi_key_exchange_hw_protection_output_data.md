# D3DWDDM2_0DDI_KEY_EXCHANGE_HW_PROTECTION_OUTPUT_DATA structure

## Description

**D3DWDDM2_0DDI_KEY_EXCHANGE_HW_PROTECTION_OUTPUT_DATA** is used with [D3DWDDM2_0DDI_KEY_EXCHANGE_HW_PROTECTION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_key_exchange_hw_protection_data) in the implementation of Digital Rights Management (DRM).

## Members

### `PrivateDataSize`

Contains the size of the private data reserved for IHV usage. This size is determined from the **pPrivateInputSize** member returned by [GetCryptoSessionPrivateDataSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_getcryptosessionprivatedatasize).

### `MaxHWProtectionDataSize`

The maximum size of data that the driver can return in the output buffer. The last byte that it can write to is **pbOuput**[**PrivateDataSize** + **MaxHWProtectionDataSize** – 1].

### `HWProtectionDataSize`

Returns the size of the output data written by the driver.

### `TransportTime`

Returns the number of 100 nanosecond units spent transporting the data.

### `ExecutionTime`

Returns the number of 100 nanosecond units spent executing the content protection command.

### `pbOutput`

If **PrivateDataSize** is greater than 0, **pbOutput**[0] – **pbOutput**[**PrivateDataSize** - 1] is reserved for IHV use.

**pbOutput**[**PrivateDataSize**] – **pbOutput**[**MaxHWProtectionDataSize** + **PrivateDataSize** - 1] contains the region into which the driver should return the output data from the DRM command. The format and size of the DRM command is defined by the DRM specification.

## See also

[D3DWDDM2_0DDI_KEY_EXCHANGE_HW_PROTECTION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_key_exchange_hw_protection_data)

[GetCryptoSessionPrivateDataSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_getcryptosessionprivatedatasize)

[NegotiateCryptoSessionKeyExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_negotiatecryptosessionkeyeschange)