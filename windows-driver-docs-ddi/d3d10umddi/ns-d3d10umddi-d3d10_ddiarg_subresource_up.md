# D3D10_DDIARG_SUBRESOURCE_UP structure

## Description

The D3D10_DDIARG_SUBRESOURCE_UP structure describes initialization information about a subresource.

## Members

### `pSysMem` [in]

A pointer to a buffer that contains the contents of the subresource to copy from.

### `SysMemPitch` [in]

The pitch, in bytes, of the surface--that is, the distance, in bytes, to the start of the next row.

### `SysMemSlicePitch` [in]

The pitch, in bytes, of the depth slice--that is, the distance, in bytes, to the start of the next depth, where a 3-D subresource is composed of width x rows x depth.

## See also

[D3D10DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createresource)