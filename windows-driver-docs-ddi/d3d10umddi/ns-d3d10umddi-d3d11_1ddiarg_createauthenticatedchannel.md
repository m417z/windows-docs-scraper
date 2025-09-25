# D3D11_1DDIARG_CREATEAUTHENTICATEDCHANNEL structure

## Description

Specifies the attributes of the authenticated channel to be created by the user-mode driver's [CreateAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createauthenticatedchannel) function.

## Members

### `ChannelType`

Specifies the type of channel, as a member of the [D3D11_1DDI_AUTHENTICATED_CHANNEL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_authenticated_channel_type) enumeration.

### `hChannel`

A handle to the authenticated channel object.

## See also

[CreateAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createauthenticatedchannel)

[D3D11_1DDI_AUTHENTICATED_CHANNEL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_authenticated_channel_type)