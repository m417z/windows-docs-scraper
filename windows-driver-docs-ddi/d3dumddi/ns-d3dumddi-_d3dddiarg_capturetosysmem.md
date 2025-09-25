# _D3DDDIARG_CAPTURETOSYSMEM structure

## Description

The D3DDDIARG_CAPTURETOSYSMEM structure describes the parameters of a bit-block transfer (bitblt) from a capture buffer to a video memory surface.

## Members

### `hSrcResource` [in]

A handle to the source resource.

### `SrcRect` [in]

A [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure for the source rectangle.

### `hDstResource` [in]

A handle to the destination resource.

### `DstSubResourceIndex` [in]

The index to the destination surface within the resource.

### `DstRect` [in]

A [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure for the destination rectangle.

## Remarks

Because the source resource that is specified by the **hSrcResource** member is a capture buffer, it is guaranteed to be a stand alone resource. Therefore, in a call to [CaptureToSysMem](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_capturetosysmem), the Microsoft Direct3D runtime is not required to supply an index to a sub source surface within the resource. However, an index to a sub source surface is required when the runtime calls the user-mode display driver's [Blt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_blt) function to perform a more general bitblt.

## See also

[Blt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_blt)

[CaptureToSysMem](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_capturetosysmem)

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)