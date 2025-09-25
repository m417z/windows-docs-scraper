# D3D11_1DDI_AUTHENTICATED_QUERY_ACESSIBILITY_OUTPUT structure

## Description

Contains the response to a [QueryAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_queryauthenticatedchannel) query with a [D3D11_1DDI_AUTHENTICATED_QUERY_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_query_output).**QueryType** value of **D3D11_1DDI_AUTHENTICATED_QUERY_ACCESSIBILITY_ATTRIBUTES**.

## Members

### `Output`

A [D3D11_1DDI_AUTHENTICATED_QUERY_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_query_output) structure that contains a Message Authentication Code (MAC) and other data.

### `BusType`

A bitwise **OR** of flags from the [D3D11_1DDI_BUS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_bus_type) enumeration.

### `AccessibleInContiguousBlocks`

If **TRUE**, contiguous blocks of video memory may be accessible to the CPU or the bus.

### `AccessibleInNonContiguousBlocks`

If **TRUE**, non-contiguous blocks of video memory may be accessible to the CPU or the bus.

## See also

[D3D11_1DDI_AUTHENTICATED_QUERY_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_query_output)

[D3D11_1DDI_BUS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_bus_type)

[QueryAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_queryauthenticatedchannel)