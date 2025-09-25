# D3D11_1DDI_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_COUNT_OUTPUT structure

## Description

Contains the response to a [QueryAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_queryauthenticatedchannel) query with a [D3D11_1DDI_AUTHENTICATED_QUERY_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_query_output).**QueryType** value of **D3D11_1DDI_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_COUNT**.

## Members

### `Output`

A [D3D11_1DDI_AUTHENTICATED_QUERY_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_query_output) structure that contains a Message Authentication Code (MAC) and other data.

### `RestrictedSharedResourceProcessCount`

The number of processes that are allowed to open shared resources that have restricted access. A process cannot open such a resource unless the process has been granted access.

## See also

[D3D11_1DDI_AUTHENTICATED_QUERY_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_query_output)

[QueryAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_queryauthenticatedchannel)