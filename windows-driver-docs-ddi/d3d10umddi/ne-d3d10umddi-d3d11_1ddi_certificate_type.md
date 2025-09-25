# D3D11_1DDI_CERTIFICATE_TYPE enumeration

## Description

Specifies the type of authenticated certificate that is used to establish trust and perform a key exchange. This type is used by callers of the [GetCertificate](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getcertificate) and [GetCertificateSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getcertificatesize) functions.

## Constants

### `D3D11_1DDI_CERTIFICATE_TYPE_AUTHENTICATED_CHANNEL`

The certificate is used for an authenticated channel.

### `D3D11_1DDI_CERTIFICATE_TYPE_CRYPTO_SESSION`

The certificate is used for a cryptographic session.

## See also

[GetCertificate](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getcertificate)

[GetCertificateSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getcertificatesize)