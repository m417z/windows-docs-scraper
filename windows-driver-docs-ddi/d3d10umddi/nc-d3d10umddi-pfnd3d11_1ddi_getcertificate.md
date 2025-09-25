# PFND3D11_1DDI_GETCERTIFICATE callback function

## Description

Returns a certificate that the display miniport driver uses for either the cryptographic session certificate or authenticated channel.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `pCertificateInfo`

A pointer to a [D3D11_1DDI_CERTIFICATE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_certificate_info) structure that specifies the cryptographic session certificate or authenticated channel to return.

### `CertificateSize`

The size, in bytes, of the buffer that is referenced by the *pCertificate* parameter.

### `pCertificate`

A pointer to a byte array that receives the driver's certificate chain.

## Remarks

Based on the data in the [D3D11_1DDI_CERTIFICATE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_certificate_info) structure, **GetCertificate** returns the certificate for either the cryptographic session or the authenticated channel. The driver uses this certificate to establish trust and perform key exchange for the session or channel.

**Note** The size, in bytes, of a driver's certificate chain can be queried by calling [GetCertificateSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getcertificatesize).

## See also

[D3D11_1DDI_CERTIFICATE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_certificate_info)

[GetCertificateSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getcertificatesize)