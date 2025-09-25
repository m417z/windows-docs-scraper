# SwapBuffers function

## Description

The **SwapBuffers** function exchanges the front and back buffers if the current pixel format for the window referenced by the specified device context includes a back buffer.

## Parameters

### `unnamedParam1`

Specifies a device context. If the current pixel format for the window referenced by this device context includes a back buffer, the function exchanges the front and back buffers.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the current pixel format for the window referenced by the device context does not include a back buffer, this call has no effect and the content of the back buffer is undefined when the function returns.

With multithread applications, flush the drawing commands in any other threads drawing to the same window before calling **SwapBuffers**.

## See also

[OpenGL on Windows](https://learn.microsoft.com/windows/desktop/OpenGL/opengl-on-windows-nt--windows-2000--and-windows-95-98)

[Windows Functions](https://learn.microsoft.com/windows/desktop/OpenGL/win32-functions)