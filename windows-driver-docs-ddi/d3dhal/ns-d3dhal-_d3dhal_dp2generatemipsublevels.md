# _D3DHAL_DP2GENERATEMIPSUBLEVELS structure

## Description

 DirectX 9.0 and later versions only.

The D3DHAL_DP2GENERATEMIPSUBLEVELS structure is used to inform the driver to automatically generate the sublevels of a given MIP-map texture using a given filter type.

## Members

### `hSurface`

Specifies the surface handle used in the generation.

### `Filter`

Specifies the filter type used in the generation.

## Remarks

To generate the sublevels of a MIP-map texture, the driver receives a D3DDP2OP_GENERATEMIPSUBLEVELS command along with a D3DHAL_DP2GENERATEMIPSUBLEVELS structure. For more information about automatically generating the sublevels of MIP-map textures, see [Generating Sublevels of MIP Map Textures](https://learn.microsoft.com/windows-hardware/drivers/display/generating-sublevels-of-mip-map-textures).

## See also

D3DDP2OP_GENERATEMIPSUBLEVELS