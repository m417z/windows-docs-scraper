# wglSwapLayerBuffers function

## Description

The **wglSwapLayerBuffers** function swaps the front and back buffers in the overlay, underlay, and main planes of the window referenced by a specified device context.

## Parameters

### `unnamedParam1`

Specifies the device context of a window whose layer plane palette is to be realized into the physical palette.

### `unnamedParam2`

Specifies the overlay, underlay, and main planes whose front and back buffers are to be swapped. The **bReserved** member of the [PIXELFORMATDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pixelformatdescriptor) structure specifies the number of overlay and underlay planes. The *fuPlanes* parameter is a bitwise combination of the following values.

| Value | Meaning |
| --- | --- |
| **WGL_SWAP_MAIN_PLANE** | Swaps the front and back buffers of the main plane. |
| **WGL_SWAP_OVERLAYi** | Swaps the front and back buffers of the overlay plane *i*, where *i* is an integer between 1 and 15. WGL_SWAP_OVERLAY1 identifies the first overlay plane over the main plane, WGL_SWAP_OVERLAY2 identifies the second overlay plane over the first overlay plane, and so on. |
| **WGL_SWAP_UNDERLAYi** | Swaps the front and back buffers of the underlay plane *i*, where *i* is an integer between 1 and 15. WGL_SWAP_UNDERLAY1 identifies the first underlay plane under the main plane, WGL_SWAP_UNDERLAY2 identifies the second underlay plane under the first underlay plane, and so on. |

## Return value

If the function succeeds, the return value is **TRUE**. If the function fails, the return value is **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

When a layer plane doesn't include a back buffer, calling the **wglSwapLayerBuffers** function has no effect on that layer plane. After you call **wglSwapLayerBuffers**, the state of the back buffer content is given in the corresponding **LAYERPLANEDESCRIPTOR** structure of the layer plane or in the **PIXELFORMATDESCRIPTOR** structure of the main plane. The **wglSwapLayerBuffers** function swaps the front and back buffers in the specified layer planes simultaneously.

Some devices don't support swapping layer planes individually; they swap all layer planes as a group. When the PFD_SWAP_LAYER_BUFFERS flag of the **PIXELFORMATDESCRIPTOR** structure is set, it indicates that a device can swap individual layer planes and that you can call **wglSwapLayerBuffers**.

With applications that use multiple threads, before calling **wglSwapLayerBuffers**, clear all drawing commands in all threads drawing to the same window.

## See also

[LAYERPLANEDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-layerplanedescriptor)

[OpenGL on Windows](https://learn.microsoft.com/windows/desktop/OpenGL/opengl-on-windows-nt--windows-2000--and-windows-95-98)

[PIXELFORMATDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pixelformatdescriptor)

[SwapBuffers](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-swapbuffers)

[WGL Functions](https://learn.microsoft.com/windows/desktop/OpenGL/wgl-functions)