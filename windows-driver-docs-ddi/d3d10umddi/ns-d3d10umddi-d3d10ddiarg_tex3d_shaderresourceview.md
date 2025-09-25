# D3D10DDIARG_TEX3D_SHADERRESOURCEVIEW structure

## Description

The D3D10DDIARG_TEX3D_SHADERRESOURCEVIEW structure describes a three-dimensional (3-D) texture that is used to create a shader resource view in a call to the [CreateShaderResourceView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createshaderresourceview) function.

## Members

### `MostDetailedMip` [in]

The identifier of the most detailed MIP-map.

### `MipLevels` [in]

The number of MIP-map levels for the texture.

## Remarks

If the **MipLevels** member is set to -1, the MIP-maps in the texture start from the MIP-map that is set in the **MostDetailedMip** member.

## See also

[CalcPrivateShaderResourceViewSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivateshaderresourceviewsize)

[CreateShaderResourceView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createshaderresourceview)

[D3D10DDIARG_CREATESHADERRESOURCEVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createshaderresourceview)