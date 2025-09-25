# PFND3D11_1DDI_DESTROYAUTHENTICATEDCHANNEL callback function

## Description

Releases resources for the authenticated channel that were created through a call to the [CreateAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createauthenticatedchannel) function.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `hAuthChannel`

A handle to the driver's private data for the authenticated channel. This handle was created by the Direct3D runtime and passed to the driver in the call to [CreateAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createauthenticatedchannel).

## See also

[CreateAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createauthenticatedchannel)