# D3D11DDIARG_BUFFER_RENDERTARGETVIEW structure

## Description

The D3D11DDIARG_BUFFER_RENDERTARGETVIEW structure describes a buffer that is used to create a render target view in a call to the [CreateRenderTargetView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createrendertargetview) function.

## Members

### `FirstElement` [in]

The offset, in bytes, to the first element in the buffer.

### `ElementOffset` [in]

The offset, in bytes, to the first element in the buffer.

### `NumElements` [in]

The number of elements in the buffer.

### `ElementWidth` [in]

The width, in elements, in the buffer.

## See also

[CalcPrivateRenderTargetViewSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivaterendertargetviewsize)

[CreateRenderTargetView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createrendertargetview)

[D3D10DDIARG_CREATERENDERTARGETVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createrendertargetview)