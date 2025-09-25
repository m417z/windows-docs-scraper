# D3D11_1DDI_CERTIFICATE_INFO structure

## Description

Specifies a cryptographic session certificate or authenticated channel.

## Members

### `CertificateType`

A [D3D11_1DDI_CERTIFICATE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_certificate_type) value that specifies the type of authenticated certificate that is used to establish trust and perform a key exchange.

### `ChannelType`

A [D3D11_1DDI_AUTHENTICATED_CHANNEL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_authenticated_channel_type) value that specifies the type of Direct3D authenticated channel.

### `CryptoSessionType`

A GUID that indicates the cryptographic session.

## See also

[D3D11_1DDI_AUTHENTICATED_CHANNEL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_authenticated_channel_type)

[D3D11_1DDI_CERTIFICATE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_certificate_type)