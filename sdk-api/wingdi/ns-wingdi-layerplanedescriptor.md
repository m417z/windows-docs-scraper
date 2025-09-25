# LAYERPLANEDESCRIPTOR structure

## Description

The **LAYERPLANEDESCRIPTOR** structure describes the pixel format of a drawing surface.

## Members

### `nSize`

Specifies the size of this data structure. Set this value to **sizeof**(**LAYERPLANEDESCRIPTOR**).

### `nVersion`

Specifies the version of this data structure. Set this value to 1.

### `dwFlags`

A set of bit flags that specify properties of the layer plane. The properties are generally not mutually exclusive; any combination of bit flags can be set, with the exceptions noted. The following bit flag constants are defined.

| Value | Meaning |
| --- | --- |
| LPD_SUPPORT_OPENGL | The layer plane supports OpenGL drawing. |
| LPD_SUPPORT_GDI | The layer plane supports GDI drawing. The current implementation of OpenGL doesn't support this flag. |
| LPD_DOUBLEBUFFER | The layer plane is double-buffered. A layer plane can be double-buffered even when the main plane is single-buffered and vice versa. |
| LPD_STEREO | The layer plane is stereoscopic. A layer plane can be stereoscopic even when the main plane is monoscopic and vice versa. |
| LPD_SWAP_EXCHANGE | In a double-buffered layer plane, swapping the color buffer exchanges the front buffer and back buffer contents. The back buffer then contains the contents of the front buffer before the swap. This flag is a hint only and might not be provided by a driver. |
| LPD_SWAP_COPY | In a double-buffered layer plane, swapping the color buffer copies the back buffer contents to the front buffer. The swap does not affect the back buffer contents. This flag is a hint only and might not be provided by a driver. |
| LPD_TRANSPARENT | The **crTransparent** member of this structure contains a transparent color or index value that enables underlying layers to show through this layer. All layer planes, except the lowest-numbered underlay layer, have a transparent color or index. |
| LPD_SHARE_DEPTH | The layer plane shares the depth buffer with the main plane. |
| LPD_SHARE_STENCIL | The layer plane shares the stencil buffer with the main plane. |
| LPD_SHARE_ACCUM | The layer plane shares the accumulation buffer with the main plane. |

### `iPixelType`

Specifies the type of pixel data. The following types are defined.

| Value | Meaning |
| --- | --- |
| LPD_TYPE_RGBA | RGBA pixels. Each pixel has four components: red, green, blue, and alpha. |
| LPD_TYPE_COLORINDEX | Color-index pixels. Each pixel uses a color-index value. |

### `cColorBits`

Specifies the number of color bitplanes in each color buffer. For RGBA pixel types, it is the size of the color buffer, excluding the alpha bitplanes. For color-index pixels, it is the size of the color-index buffer.

### `cRedBits`

Specifies the number of red bitplanes in each RGBA color buffer.

### `cRedShift`

Specifies the shift count for red bitplanes in each RGBA color buffer.

### `cGreenBits`

Specifies the number of green bitplanes in each RGBA color buffer.

### `cGreenShift`

Specifies the shift count for green bitplanes in each RGBA color buffer.

### `cBlueBits`

Specifies the number of blue bitplanes in each RGBA color buffer.

### `cBlueShift`

Specifies the shift count for blue bitplanes in each RGBA color buffer.

### `cAlphaBits`

Specifies the number of alpha bitplanes in each RGBA color buffer. Alpha bitplanes are not supported.

### `cAlphaShift`

Specifies the shift count for alpha bitplanes in each RGBA color buffer. Alpha bitplanes are not supported.

### `cAccumBits`

Specifies the total number of bitplanes in the accumulation buffer.

### `cAccumRedBits`

Specifies the number of red bitplanes in the accumulation buffer.

### `cAccumGreenBits`

Specifies the number of green bitplanes in the accumulation buffer.

### `cAccumBlueBits`

Specifies the number of blue bitplanes in the accumulation buffer.

### `cAccumAlphaBits`

Specifies the number of alpha bitplanes in the accumulation buffer.

### `cDepthBits`

Specifies the depth of the depth (z-axis) buffer.

### `cStencilBits`

Specifies the depth of the stencil buffer.

### `cAuxBuffers`

Specifies the number of auxiliary buffers. Auxiliary buffers are not supported.

### `iLayerPlane`

### `bReserved`

Not used. Must be zero.

### `crTransparent`

When the LPD_TRANSPARENT flag is set, specifies the transparent color or index value. Typically the value is zero.

#### - iLayerType

Specifies the layer plane number. Positive values of **iLayerType** identify overlay planes, where 1 is the first overlay plane over the main plane, 2 is the second overlay plane over the first overlay plane, and so on. Negative values identify underlay planes, where 1 is the first underlay plane under the main plane, 2 is the second underlay plane under the first underlay plane, and so on. The number of overlay and underlay planes is given in the **bReserved** member of the **PIXELFORMATDESCRIPTOR** structure.

## Remarks

Please notice, as documented above, that certain layer plane properties are not supported in the current implementation. The implementation is the Microsoft GDI software implementation of OpenGL. Hardware manufacturers that enhance parts of OpenGL may support some layer plane properties not supported by the generic implementation.

## See also

[OpenGL on Windows](https://learn.microsoft.com/windows/desktop/OpenGL/opengl-on-windows-nt--windows-2000--and-windows-95-98)

[PIXELFORMATDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pixelformatdescriptor)

[Structures](https://learn.microsoft.com/windows/desktop/OpenGL/structures)

[wglCreateLayerContext](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglcreatelayercontext)

[wglDescribeLayerPlane](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wgldescribelayerplane)

[wglGetLayerPaletteEntries](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglgetlayerpaletteentries)

[wglRealizeLayerPalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglrealizelayerpalette)

[wglSetLayerPaletteEntries](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglsetlayerpaletteentries)

[wglSwapLayerBuffers](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglswaplayerbuffers)