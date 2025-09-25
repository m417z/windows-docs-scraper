# _D3DDDIARG_TEXBLT1 structure

## Description

Describes parameters for a texture bit-block transfer (bitblt) operation.

## Members

### `hDstResource`

A handle to the destination resource.

### `hSrcResource`

A handle to the source resource.

### `CubeMapFace`

The face of a cube map.

### `DstPoint`

A [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that describes the destination point where the source texture is copied.

### `SrcRect`

A [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that describes the source texture to copy to the destination point.

### `CopyFlags`

A value that specifies characteristics of a copy operation as a bitwise OR of the values in the [D3DDDI_COPY_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_copy_flags) enumeration type.

## See also

[D3DDDI_COPY_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_copy_flags)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)