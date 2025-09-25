# wglCopyContext function

## Description

The **wglCopyContext** function copies selected groups of rendering states from one OpenGL rendering context to another.

## Parameters

### `unnamedParam1`

Specifies the source OpenGL rendering context whose state information is to be copied.

### `unnamedParam2`

Specifies the destination OpenGL rendering context to which state information is to be copied.

### `unnamedParam3`

Specifies which groups of the *hglrcSrc* rendering state are to be copied to *hglrcDst*. It contains the bitwise-OR of the same symbolic names that are passed to the **glPushAttrib** function. You can use GL_ALL_ATTRIB_BITS to copy all the rendering state information.

## Return value

If the function succeeds, the return value is **TRUE**. If the function fails, the return value is **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Using the **wglCopyContext** function, you can synchronize the rendering state of two rendering contexts. You can only copy the rendering state between two rendering contexts within the same process. The rendering contexts must be from the same OpenGL implementation. For example, you can always copy a rendering state between two rendering contexts with identical pixel format in the same process.

You can copy the same state information available only with the **glPushAttrib** function. You cannot copy some state information, such as pixel pack/unpack state, render mode state, select state, and feedback state. When you call **wglCopyContext**, make sure that the destination rendering context, *hglrcDst*, is not current to any thread.

## See also

[OpenGL on Windows](https://learn.microsoft.com/windows/desktop/OpenGL/opengl-on-windows-nt--windows-2000--and-windows-95-98)

[WGL Functions](https://learn.microsoft.com/windows/desktop/OpenGL/wgl-functions)

[glPushAttrib](https://learn.microsoft.com/windows/desktop/OpenGL/glpushattrib)

[wglCreateContext](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglcreatecontext)

[wglCreateLayerContext](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglcreatelayercontext)

[wglShareLists](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglsharelists)