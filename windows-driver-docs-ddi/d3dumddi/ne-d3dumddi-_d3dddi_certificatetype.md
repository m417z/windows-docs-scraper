# _D3DDDI_CERTIFICATETYPE enumeration

## Description

The D3DDDI_CERTIFICATETYPE enumeration contains values that identify certificate types.

## Constants

### `D3DDDI_CERTTYPE_AUTHENTICATED_CHANNEL`

The value specifies that the certificate type is an authenticated channel.

### `D3DDDI_CERTTYPE_CRYPTOSESSION`

The value specifies that the certificate type is an encryption session.

## Remarks

The user-mode display driver receives a D3DDDI_CERTIFICATETYPE-typed value in the **CertificateType** member of the [DDICERTIFICATEINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_ddicertificateinfo) structure. The **pInfo** member of the [D3DDDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps) structure points to DDICERTIFICATEINFO when the driver's [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function is called with the D3DDDICAPS_GETCERTIFICATE value set in the **Type** member of D3DDDIARG_GETCAPS.

## See also

[D3DDDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps)

[DDICERTIFICATEINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_ddicertificateinfo)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)