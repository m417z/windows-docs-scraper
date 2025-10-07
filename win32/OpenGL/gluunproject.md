# gluUnProject function

The **gluUnProject** function maps window coordinates to object coordinates.

## Parameters

*winx*

The x window coordinate to be mapped.

*winy*

The y window coordinate to be mapped.

*winz*

The z window coordinate to be mapped.

*modelMatrix*

The modelview matrix (as from a [**glGetDoublev**](https://learn.microsoft.com/windows/win32/opengl/glgetdoublev) call).

*projMatrix*

The projection matrix (as from a **glGetDoublev** call).

*viewport*

The viewport (as from a [**glGetIntegerv**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) call).

*objx*

The computed x object coordinate.

*objy*

The computed y object coordinate.

*objz*

The computed z object coordinate.

## Return value

If the function succeeds, the return value is GL\_TRUE.

If the function fails, the return value is GL\_FALSE.

## Remarks

The **gluUnProject** function maps the specified window coordinates into object coordinates using *modelMatrix*, *projMatrix*, and *viewport*. The result is stored in *objx*, *objy*, and *objz*.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Glu.h |
| Library<br> | Glu32.lib |
| DLL<br> | Glu32.dll |

## See also

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glGetDoublev**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glGetIntegerv**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**gluProject**](https://learn.microsoft.com/windows/win32/opengl/gluproject)

