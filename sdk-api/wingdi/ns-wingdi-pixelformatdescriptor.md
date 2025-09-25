# PIXELFORMATDESCRIPTOR structure

## Description

The **PIXELFORMATDESCRIPTOR** structure describes the pixel format of a drawing surface.

## Members

### `nSize`

Specifies the size of this data structure. This value should be set to **sizeof**(**PIXELFORMATDESCRIPTOR**).

### `nVersion`

Specifies the version of this data structure. This value should be set to 1.

### `dwFlags`

A set of bit flags that specify properties of the pixel buffer. The properties are generally not mutually exclusive; you can set any combination of bit flags, with the exceptions noted. The following bit flag constants are defined.

| Value | Meaning |
| --- | --- |
| **PFD_DRAW_TO_WINDOW**<br><br>0x00000004 | The buffer can draw to a window or device surface. |
| **PFD_DRAW_TO_BITMAP**<br><br>0x00000008 | The buffer can draw to a memory bitmap. |
| **PFD_SUPPORT_GDI**<br><br>0x00000010 | The buffer supports GDI drawing. This flag and PFD_DOUBLEBUFFER are mutually exclusive in the current generic implementation. |
| **PFD_SUPPORT_OPENGL**<br><br>0x00000020 | The buffer supports OpenGL drawing. |
| **PFD_GENERIC_ACCELERATED**<br><br>0x00001000 | The pixel format is supported by a device driver that accelerates the generic implementation. If this flag is clear and the PFD_GENERIC_FORMAT flag is set, the pixel format is supported by the generic implementation only. |
| **PFD_GENERIC_FORMAT**<br><br>0x00000040 | The pixel format is supported by the GDI software implementation, which is also known as the generic implementation. If this bit is clear, the pixel format is supported by a device driver or hardware. |
| **PFD_NEED_PALETTE**<br><br>0x00000080 | The buffer uses RGBA pixels on a palette-managed device. A logical palette is required to achieve the best results for this pixel type. Colors in the palette should be specified according to the values of the **cRedBits**, **cRedShift**, **cGreenBits**, **cGreenShift**, **cBluebits**, and **cBlueShift** members. The palette should be created and realized in the device context before calling [wglMakeCurrent](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglmakecurrent). |
| **PFD_NEED_SYSTEM_PALETTE**<br><br>0x00000100 | Defined in the pixel format descriptors of hardware that supports one hardware palette in 256-color mode only. For such systems to use hardware acceleration, the hardware palette must be in a fixed order (for example, 3-3-2) when in RGBA mode or must match the logical palette when in color-index mode.When this flag is set, you must call **SetSystemPaletteUse** in your program to force a one-to-one mapping of the logical palette and the system palette. If your OpenGL hardware supports multiple hardware palettes and the device driver can allocate spare hardware palettes for OpenGL, this flag is typically clear.<br><br>This flag is not set in the generic pixel formats. |
| **PFD_DOUBLEBUFFER**<br><br>0x00000001 | The buffer is double-buffered. This flag and PFD_SUPPORT_GDI are mutually exclusive in the current generic implementation. |
| **PFD_STEREO**<br><br>0x00000002 | The buffer is stereoscopic. This flag is not supported in the current generic implementation. |
| **PFD_SWAP_LAYER_BUFFERS**<br><br>0x00000800 | Indicates whether a device can swap individual layer planes with pixel formats that include double-buffered overlay or underlay planes. Otherwise all layer planes are swapped together as a group. When this flag is set, **wglSwapLayerBuffers** is supported. |

You can specify the following bit flags when calling [ChoosePixelFormat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-choosepixelformat).

| Value | Meaning |
| --- | --- |
| **PFD_DEPTH_DONTCARE**<br><br>0x20000000 | The requested pixel format can either have or not have a depth buffer. To select a pixel format without a depth buffer, you must specify this flag. The requested pixel format can be with or without a depth buffer. Otherwise, only pixel formats with a depth buffer are considered. |
| **PFD_DOUBLEBUFFER_DONTCARE**<br><br>0x40000000 | The requested pixel format can be either single- or double-buffered. |
| **PFD_STEREO_DONTCARE**<br><br>0x80000000 | The requested pixel format can be either monoscopic or stereoscopic. |

With the **glAddSwapHintRectWIN** extension function, two new flags are included for the **PIXELFORMATDESCRIPTOR** pixel format structure.

| Value | Meaning |
| --- | --- |
| **PFD_SWAP_COPY**<br><br>0x00000400 | Specifies the content of the back buffer in the double-buffered main color plane following a buffer swap. Swapping the color buffers causes the content of the back buffer to be copied to the front buffer. The content of the back buffer is not affected by the swap. PFD_SWAP_COPY is a hint only and might not be provided by a driver. |
| **PFD_SWAP_EXCHANGE**<br><br>0x00000200 | Specifies the content of the back buffer in the double-buffered main color plane following a buffer swap. Swapping the color buffers causes the exchange of the back buffer's content with the front buffer's content. Following the swap, the back buffer's content contains the front buffer's content before the swap. PFD_SWAP_EXCHANGE is a hint only and might not be provided by a driver. |

### `iPixelType`

Specifies the type of pixel data. The following types are defined.

| Value | Meaning |
| --- | --- |
| **PFD_TYPE_RGBA**<br><br>0 | RGBA pixels. Each pixel has four components in this order: red, green, blue, and alpha. |
| **PFD_TYPE_COLORINDEX**<br><br>1 | Color-index pixels. Each pixel uses a color-index value. |

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

### `iLayerType`

Ignored. Earlier implementations of OpenGL used this member, but it is no longer used.

### `bReserved`

Specifies the number of overlay and underlay planes. Bits 0 through 3 specify up to 15 overlay planes and bits 4 through 7 specify up to 15 underlay planes.

### `dwLayerMask`

Ignored. Earlier implementations of OpenGL used this member, but it is no longer used.

### `dwVisibleMask`

Specifies the transparent color or index of an underlay plane. When the pixel type is RGBA, **dwVisibleMask** is a transparent RGB color value. When the pixel type is color index, it is a transparent index value.

### `dwDamageMask`

Ignored. Earlier implementations of OpenGL used this member, but it is no longer used.

## Remarks

Please notice carefully, as documented above, that certain pixel format properties are not supported in the current generic implementation. The generic implementation is the Microsoft GDI software implementation of OpenGL. Hardware manufacturers may enhance parts of OpenGL, and may support some pixel format properties not supported by the generic implementation.

## See also

[ChoosePixelFormat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-choosepixelformat)

[DescribePixelFormat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-describepixelformat)

[GetPixelFormat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getpixelformat)

[OpenGL on Windows](https://learn.microsoft.com/windows/desktop/OpenGL/opengl-on-windows-nt--windows-2000--and-windows-95-98)

[SetPixelFormat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpixelformat)

[Structures](https://learn.microsoft.com/windows/desktop/OpenGL/structures)