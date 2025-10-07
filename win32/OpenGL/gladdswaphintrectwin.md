# glAddSwapHintRectWIN function

The **glAddSwapHintRectWIN** callback function specifies a set of rectangles that are to be copied by [**SwapBuffers**](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-swapbuffers).

## Parameters

*x*

The *x*-coordinate (in window coordinates) of the lower-left corner of the hint region rectangle.

*y*

The *y*-coordinate (in window coordinates) of the lower-left corner of the hint region rectangle.

*width*

The width of the hint region rectangle.

*height*

The height of the hint region rectangle.

## Return value

This function does not return a value.

## Remarks

The **glAddSwapHintRectWIN** function speeds up animation by reducing the amount of repainting between frames. With **glAddSwapHintRectWIN**, you specify a set of rectangular areas that you want copied when you call [**SwapBuffers**](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-swapbuffers). When you do not specify any rectangles with **glAddSwapHintRectWIN** before calling **SwapBuffers**, the entire framebuffer is swapped. Using **glAddSwapHintRectWIN** to copy only changed parts of the buffer can significantly increase the performance of **SwapBuffers**, especially when **SwapBuffers** is implemented in software.

The **glAddSwapHintRectWIN** function adds a rectangle to the hint region. When the PFD\_SWAP\_COPY flag of the [**PIXELFORMATDESCRIPTOR**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-pixelformatdescriptor) pixel format structure is set, **SwapBuffers** uses this region to clip the copying of the back buffer to the front buffer. You don't specify PFD\_SWAP\_COPY; it is set by capable hardware. The hint region is cleared after each call to **SwapBuffers**. With some hardware configurations, **SwapBuffers** can ignore the hint region and exchange the entire buffer. **SwapBuffers** is implemented by the system, not by the application.

OpenGL maintains a separate hint region for each window. When you call **glAddSwapHintRectWIN** on any rendering contexts associated with a window, the hint rectangles are combined into a single region.

Call **glAddSwapHintRectWIN** with a bounding rectangle for each object drawn for a frame and for each rectangle cleared to erase previous frame objects.

> [!Note]
> The **glAddSwapHintRectWIN** function is an extension function that is not part of the standard OpenGL library but is part of the GL\_WIN\_swap\_hint extension. To check whether your implementation of OpenGL supports **glAddSwapHintRectWIN**, call **glGetString**(GL\_EXTENSIONS). If it returns GL\_WIN\_swap\_hint, **glAddSwapHintRectWIN** is supported. To obtain the address of an extension function, call **wglGetProcAddress**.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Gl.h |

## See also

[**glGetString**](https://learn.microsoft.com/windows/win32/opengl/glgetstring)

[**PIXELFORMATDESCRIPTOR**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-pixelformatdescriptor)

[**SwapBuffers**](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-swapbuffers)

[**wglGetProcAddress**](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglgetprocaddress)

