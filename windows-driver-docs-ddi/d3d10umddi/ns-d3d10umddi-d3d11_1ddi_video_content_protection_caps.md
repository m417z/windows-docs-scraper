# D3D11_1DDI_VIDEO_CONTENT_PROTECTION_CAPS structure

## Description

Describes the content-protection capabilities of the user-mode display driver.

## Members

### `Caps`

A bitwise **OR** of zero or more flags from the [D3D11_1DDI_CONTENT_PROTECTION_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_content_protection_caps) enumeration.

### `KeyExchangeTypeCount`

The number of cryptographic key-exchange types that are supported by the driver. To get the list of key-exchange types, call the [GetCryptoKeyExchangeType](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getcryptokeyexchangetype) function.

### `BlockAlignmentSize`

The encryption block size, in bytes. The size of data to be encrypted must be a multiple of this value.

### `ProtectedMemorySize`

The total amount of memory, in bytes, that can be used to hold protected surfaces.

## See also

[D3D11_1DDI_CONTENT_PROTECTION_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_content_protection_caps)

[GetCryptoKeyExchangeType](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getcryptokeyexchangetype)