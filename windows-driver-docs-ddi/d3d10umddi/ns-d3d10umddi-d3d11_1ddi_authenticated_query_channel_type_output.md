# D3D11_1DDI_AUTHENTICATED_QUERY_CHANNEL_TYPE_OUTPUT structure

## Description

Contains the response to a [QueryAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_queryauthenticatedchannel) query with a [D3D11_1DDI_AUTHENTICATED_QUERY_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_query_output).**QueryType** value of **D3D11_1DDI_AUTHENTICATED_QUERY_CHANNEL_TYPE**.

## Members

### `Output`

A [D3D11_1DDI_AUTHENTICATED_QUERY_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_query_output) structure that contains a Message Authentication Code (MAC) and other data.

### `ChannelType`

A [D3D11_1DDI_AUTHENTICATED_CHANNEL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_authenticated_channel_type) value that specifies the channel type.

## See also

[D3D11_1DDI_AUTHENTICATED_CHANNEL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_authenticated_channel_type)

[D3D11_1DDI_AUTHENTICATED_QUERY_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_query_output)

[QueryAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_queryauthenticatedchannel)