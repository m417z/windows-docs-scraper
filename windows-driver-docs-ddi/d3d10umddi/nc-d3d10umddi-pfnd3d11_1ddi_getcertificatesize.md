# PFND3D11_1DDI_GETCERTIFICATESIZE callback function

## Description

Queries the size in bytes of the certificate that the display miniport driver uses for either the cryptographic session certificate or authenticated channel.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `pCertificateInfo`

A pointer to a [D3D11_1DDI_CERTIFICATE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_certificate_info) structure that specifies the cryptographic session certificate or authenticated channel to query.

### `pCertificateSize`

The size, in bytes, of the specified certificate.

## Remarks

Based on the data in the [D3D11_1DDI_CERTIFICATE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_certificate_info) structure, the **GetCertificateSize** function returns the size in bytes of the certificate chain for either the cryptographic session or the authenticated channel. The driver uses this certificate to establish trust and perform key exchange for the session or channel.

**Note** The driver's certificate can be queried by calling [GetCertificate](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getcertificate).

## See also

[D3D11_1DDI_CERTIFICATE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_certificate_info)

[GetCertificate](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getcertificate)