# D3D11_1DDI_AUTHENTICATED_QUERY_ACCESSIBILITY_ENCRYPTION_GUID_INPUT structure

## Description

Contains the response to a [QueryAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_queryauthenticatedchannel) query with a [D3D11_1DDI_AUTHENTICATED_QUERY_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_query_input).**QueryType** value of **D3D11_1DDI_AUTHENTICATED_CONFIGURE_ENCRYPTION_WHEN_ACCESSIBLE_GUID**.

## Members

### `Input`

A [D3D11_1DDI_AUTHENTICATED_QUERY_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_query_input) structure that contains the GUID for the query and other data.

### `EncryptionGuidIndex`

The index of the encryption GUID.

## See also

[D3D11_1DDI_AUTHENTICATED_QUERY_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_query_input)

[QueryAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_queryauthenticatedchannel)