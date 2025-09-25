# D3D11_DDI_CREATEDEPTHSTENCILVIEW_FLAG enumeration

## Description

The D3D11_DDI_CREATEDEPTHSTENCILVIEW_FLAG enumeration type contains values that identify the type of depth-stencil view to create through a call to the driver's [CreateDepthStencilView(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createdepthstencilview) function.

## Constants

### `D3D11_DDI_CREATE_DSV_READ_ONLY_DEPTH`

The driver should create a read-only depth view.

### `D3D11_DDI_CREATE_DSV_READ_ONLY_STENCIL`

The driver should create a read-only stencil view.

### `D3D11_DDI_CREATE_DSV_FLAG_MASK`

A mask value that indicates the valid bitfields in a bitwise OR combination of the values from this enumeration.

## Remarks

D3D11_DDI_CREATEDEPTHSTENCILVIEW_FLAG values are specified in the **Flags** member of the [D3D11DDIARG_CREATEDEPTHSTENCILVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createdepthstencilview) structure to indicate the type of depth-stencil view to create.

## See also

[CreateDepthStencilView(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createdepthstencilview)

[D3D11DDIARG_CREATEDEPTHSTENCILVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createdepthstencilview)