# D3DWDDM2_0DDI_KEY_EXCHANGE_HW_PROTECTION_INPUT_DATA structure

## Description

**D3DWDDM2_0DDI_KEY_EXCHANGE_HW_PROTECTION_INPUT_DATA** is used with [D3DWDDM2_0DDI_KEY_EXCHANGE_HW_PROTECTION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_key_exchange_hw_protection_data) in the implementation of Digital Rights Management (DRM).

## Members

### `PrivateDataSize`

Contains the size of the private data reserved for IHV usage. This size is determined from the **pPrivateInputSize** member returned by [GetCryptoSessionPrivateDataSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_getcryptosessionprivatedatasize).

### `HWProtectionDataSize`

Contains the size of the DRM command data.

### `pbInput`

If **PrivateDataSize** is greater than 0, **pbInput**[0] – **pbInput**[**PrivateDataSize** - 1] is reserved for IHV use.

**pbInput**[**PrivateDataSize**] – **pbInput**[**HWProtectionDataSize** + **PrivateDataSize** - 1] contains the input data for the DRM command. The format and size of the DRM command is defined by the DRM specification.

## See also

[D3DWDDM2_0DDI_KEY_EXCHANGE_HW_PROTECTION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_key_exchange_hw_protection_data)

[GetCryptoSessionPrivateDataSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_getcryptosessionprivatedatasize)

[NegotiateCryptoSessionKeyExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_negotiatecryptosessionkeyeschange)