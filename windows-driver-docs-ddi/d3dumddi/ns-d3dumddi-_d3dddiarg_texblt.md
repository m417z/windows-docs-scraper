# _D3DDDIARG_TEXBLT structure

## Description

The D3DDDIARG_TEXBLT structure describes parameters for a texture bit-block transfer (bitblt) operation.

## Members

### `hDstResource` [in]

A handle to the destination resource.

### `hSrcResource` [in]

A handle to the source resource.

### `CubeMapFace` [in]

The face of a cube map.

### `DstPoint` [in]

A [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that describes the destination point where the source texture is copied.

### `SrcRect` [in]

A [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that describes the source texture to copy to the destination point.

## See also

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)

[TexBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_texblt)