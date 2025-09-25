# D3D10DDIARG_BUFFER_SHADERRESOURCEVIEW structure

## Description

The D3D10DDIARG_BUFFER_SHADERRESOURCEVIEW structure describes a buffer that is used to create a shader resource view in a call to the [CreateShaderResourceView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createshaderresourceview) function.

## Members

### `FirstElement`

### `ElementOffset` [in]

The offset (that is, the number of elements) between the beginning of the buffer and the first element that is to be used in the view, starting at 0.

### `NumElements`

### `ElementWidth` [in]

The number of elements in the view.

## See also

[CalcPrivateShaderResourceViewSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivateshaderresourceviewsize)

[CreateShaderResourceView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createshaderresourceview)

[D3D10DDIARG_CREATESHADERRESOURCEVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createshaderresourceview)