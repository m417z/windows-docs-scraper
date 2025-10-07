# glGetString function

The **glGetString** function returns a string describing the current OpenGL connection.

## Parameters

*name*

One of the following symbolic constants.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_VENDOR** | Returns the company responsible for this OpenGL implementation. This name does not change from release to release.<br> |
| **GL\_RENDERER** | Returns the name of the renderer. This name is typically specific to a particular configuration of a hardware platform. It does not change from release to release.<br> |
| **GL\_VERSION** | Returns a version or release number.<br> |
| **GL\_EXTENSIONS** | Returns a space-separated list of supported extensions to OpenGL.<br> |

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *name* was not an accepted value.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glGetString** function returns a pointer to a static string describing some aspect of the current OpenGL connection.

Because OpenGL does not include queries for the performance characteristics of an implementation, it is expected that some applications will be written to recognize known platforms and will modify their OpenGL usage based on known performance characteristics of these platforms. The strings GL\_VENDOR and GL\_RENDERER together uniquely specify a platform, and will not change from release to release. They should be used as such by platform recognition algorithms.

The format and contents of the string that **glGetString** returns depend on the implementation, except that:

- Extension names will not include space characters and will be separated by space characters in the GL\_EXTENSIONS string.
- The GL\_VERSION string begins with a version number. The version number uses one of these forms:

    *major\_number*.*minor\_number*

    *major\_number*.*minor\_number*.*release\_number*

- Vendor-specific information may follow the version number. Its format depends on the implementation, but a space always separates the version number and the vendor-specific information.
- All strings are null-terminated.

If an error is generated, **glGetString** returns zero.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Gl.h |
| Library<br> | Opengl32.lib |
| DLL<br> | Opengl32.dll |

## See also

[**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

