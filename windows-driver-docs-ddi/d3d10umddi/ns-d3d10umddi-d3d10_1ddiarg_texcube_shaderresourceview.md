# D3D10_1DDIARG_TEXCUBE_SHADERRESOURCEVIEW structure

## Description

The D3D10_1DDIARG_TEXCUBE_SHADERRESOURCEVIEW structure describes cube textures that are used to create a shader resource view in a call to the [CreateShaderResourceView(D3D10_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_1ddi_createshaderresourceview) function.

## Members

### `MostDetailedMip` [in]

The identifier of the most detailed MIP-map.

### `MipLevels` [in]

The number of MIP-map levels for the texture.

### `First2DArrayFace` [in]

The identifier of the first 2-D texture that comprises one or more cube textures.

### `NumCubes` [in]

The number of cube textures for a shader resource view.

## Remarks

The value in the **First2DArrayFace** member added with 6 multiplied by the number in the **NumCubes** member must be less than or equal to the value in the **ArraySize** member of the [D3D10DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createresource) structure for the shader resource whose view is created in a call to the driver's [CreateShaderResourceView(D3D10_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_1ddi_createshaderresourceview) function. That is, the following calculation applies:

```cpp
::First2DArrayFace + 6 * ::NumCubes <= Resource ::ArraySize
```

## See also

[CalcPrivateShaderResourceViewSize(D3D10_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_1ddi_calcprivateshaderresourceviewsize)

[CreateShaderResourceView(D3D10_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_1ddi_createshaderresourceview)

[D3D10DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createresource)

[D3D10_1DDIARG_CREATESHADERRESOURCEVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_1ddiarg_createshaderresourceview)