# PFND3D11_1DDI_CALCPRIVATEAUTHENTICATEDCHANNELSIZE callback function

## Description

Returns the number of bytes that the driver requires to store private data for the authenticated channel state.

## Parameters

### `hDevice` [in]

A handle to the display device (graphics context).

### `pCreateData` [in]

A pointer to a [D3D11_1DDIARG_CREATEAUTHENTICATEDCHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createauthenticatedchannel) structure that describes the authenticated channel.

## Return value

The required number of bytes for the authenticated channel state.

## Remarks

This function is not expected to fail.

## See also

[D3D11_1DDIARG_CREATEAUTHENTICATEDCHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createauthenticatedchannel)