# _DDICERTIFICATEINFO structure

## Description

The DDICERTIFICATEINFO structure describes information about the certificate that the driver uses.

## Members

### `CertificateType` [in]

A [D3DDDI_CERTIFICATETYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddi_certificatetype)-typed value that indicates the certificate type.

### `ChannelType` [in]

A [DDIAUTHENTICATEDCHANNELTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_ddiauthenticatedchanneltype)-typed value that indicates the authenticated-channel type.

### `CryptoSessionType` [in]

A GUID that indicates the encryption session.

## Remarks

The runtime specifies a pointer to a DDICERTIFICATEINFO structure in the **pInfo** member of the [D3DDDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps) structure--along with the D3DDDICAPS_GETCERTIFICATE value in the **Type** member of D3DDDIARG_GETCAPS--in a call to the user-mode display driver's [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function to retrieve the certificate. The runtime also supplies a buffer in the **pData** member of D3DDDIARG_GETCAPS to hold the certificate. The runtime receives information about the size of the buffer when the runtime calls the driver's **GetCaps** with the D3DDDICAPS_GETCERTIFICATESIZE value set in the **Type** member of D3DDDIARG_GETCAPS. The driver returns a pointer to the certificate in the supplied buffer.

## See also

[D3DDDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps)

[D3DDDI_CERTIFICATETYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddi_certificatetype)

[DDIAUTHENTICATEDCHANNELTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_ddiauthenticatedchanneltype)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)