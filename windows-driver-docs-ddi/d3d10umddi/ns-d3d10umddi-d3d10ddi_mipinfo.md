# D3D10DDI_MIPINFO structure

## Description

The D3D10DDI_MIPINFO structure describes the MIP-level texture and physical coordinates of a surface.

## Members

### `TexelWidth` [in]

The width, in texels, of the surface or volume, or the length, in texels, of the linear resource.

### `TexelHeight` [in]

The height, in texels, of the surface or volume.

### `TexelDepth` [in]

The depth, in texels, of the volume.

### `PhysicalWidth` [in]

The width, in pixels, of the surface or volume, or the length, in pixels, of the linear resource.

### `PhysicalHeight` [in]

The height, in pixels, of the surface or volume.

### `PhysicalDepth` [in]

The depth, in pixels, of the volume.

## See also

[D3D10DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createresource)