# D3D10DDIARG_BUFFER_RENDERTARGETVIEW structure

## Description

The D3D10DDIARG_BUFFER_RENDERTARGETVIEW structure describes a buffer that is used to create a render target view in a call to the [CreateRenderTargetView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createrendertargetview) function.

## Members

### `FirstElement`

### `ElementOffset` [in]

The offset (that is, the number of elements) between the beginning of the buffer and the first element that is to be used in the view, starting at 0.

### `NumElements`

### `ElementWidth` [in]

The number of elements in the view.

## See also

[CalcPrivateRenderTargetViewSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivaterendertargetviewsize)

[CreateRenderTargetView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createrendertargetview)

[D3D10DDIARG_CREATERENDERTARGETVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createrendertargetview)