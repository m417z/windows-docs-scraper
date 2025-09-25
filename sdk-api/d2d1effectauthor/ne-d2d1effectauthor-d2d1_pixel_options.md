# D2D1_PIXEL_OPTIONS enumeration

## Description

Indicates how pixel shader sampling will be restricted.

## Constants

### `D2D1_PIXEL_OPTIONS_NONE:0`

The pixel shader is not restricted in its sampling.

### `D2D1_PIXEL_OPTIONS_TRIVIAL_SAMPLING:1`

 The pixel shader samples inputs only at the same scene coordinate as the output pixel and returns transparent black whenever the input pixels are also transparent black.

### `D2D1_PIXEL_OPTIONS_FORCE_DWORD:0xffffffff`

## Remarks

If the shader specifies **D2D1_PIXEL_OPTIONS_NONE**, it must still correctly implement the region of interest calculations in [ID2D1Transform::MapOutputRectToInputRects](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1transform-mapoutputrecttoinputrects) and [ID2D1Transform::MapInputRectsToOutputRect](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1transform-mapinputrectstooutputrect).

## See also

[ID2D1DrawInfo::SetPixelShader](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1drawinfo-setpixelshader)