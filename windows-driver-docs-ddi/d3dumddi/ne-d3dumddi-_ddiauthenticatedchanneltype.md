# _DDIAUTHENTICATEDCHANNELTYPE enumeration

## Description

The DDIAUTHENTICATEDCHANNELTYPE enumeration contains values that identify authenticated-channel types.

## Constants

### `DDIAUTHENTICATEDCHANNEL_DRIVER_SOFTWARE`

The value specifies that the authenticated-channel type is software.

### `DDIAUTHENTICATEDCHANNEL_DRIVER_HARDWARE`

The value specifies that the authenticated-channel type is hardware.

## Remarks

The user-mode display driver receives a DDIAUTHENTICATEDCHANNELTYPE-typed value in the **ChannelType** member of the [DDICERTIFICATEINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_ddicertificateinfo) structure. The **pInfo** member of the [D3DDDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps) structure points to this DDICERTIFICATEINFO structure when the driver's [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function is called with the D3DDDICAPS_GETCERTIFICATE value set in the **Type** member of D3DDDIARG_GETCAPS.

The Microsoft Direct3D runtime specifies a DDIAUTHENTICATEDCHANNELTYPE-typed value in the **ChannelType** member of the [D3DDDIARG_CREATEAUTHENTICATEDCHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createauthenicatedchannel) structure that the *pData* parameter points to in a call to the driver's [CreateAuthenticatedChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createauthenticatedchannel) function.

## See also

[CreateAuthenticatedChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createauthenticatedchannel)

[D3DDDIARG_CREATEAUTHENTICATEDCHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createauthenicatedchannel)

[D3DDDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps)

[DDICERTIFICATEINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_ddicertificateinfo)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)