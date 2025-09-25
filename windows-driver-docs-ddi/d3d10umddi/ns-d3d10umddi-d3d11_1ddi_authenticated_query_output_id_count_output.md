# D3D11_1DDI_AUTHENTICATED_QUERY_OUTPUT_ID_COUNT_OUTPUT structure

## Description

Contains the response to a [QueryAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_queryauthenticatedchannel) query with a [D3D11_1DDI_AUTHENTICATED_QUERY_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_query_output).**QueryType** value of **D3D11_1DDI_AUTHENTICATED_QUERY_OUTPUT_ID_COUNT**.TBDD3D11_1DDI_AUTHENTICATED_QUERY_OUTPUT_ID_COUNT

## Members

### `Output`

A [D3D11_1DDI_AUTHENTICATED_QUERY_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_query_output) structure that contains a Message Authentication Code (MAC) and other data.

### `DeviceHandle`

A handle to the device.

### `CryptoSessionHandle`

A handle to the cryptographic session.

### `OutputIDCount`

The number of output IDs associated with the specified device and cryptographic session.

## See also

[D3D11_1DDI_AUTHENTICATED_QUERY_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_query_output)

[QueryAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_queryauthenticatedchannel)