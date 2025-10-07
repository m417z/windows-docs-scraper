# gluProject function

The **gluProject** function maps object coordinates to window coordinates.

## Parameters

*objx*

The x object coordinate.

*objy*

The y object coordinate.

*objz*

The z object coordinate.

*modelMatrix*

The current modelview matrix (as from a [**glGetDoublev**](https://learn.microsoft.com/windows/win32/opengl/glgetdoublev) call).

*projMatrix*

The current projection matrix (as from a **glGetDoublev** call).

*viewport*

The current viewport (as from a [**glGetIntegerv**](https://learn.microsoft.com/windows/win32/opengl/glgetintegerv) call).

*winx*

The computed x window coordinate.

*winy*

The computed y window coordinate.

*winz*

The computed z window coordinate.

## Return value

If the function succeeds, the return value is GL\_TRUE.

If the function fails, the return value is GL\_FALSE.

## Remarks

The **gluProject** function transforms the specified object coordinates into window coordinates using *modelMatrix*, *projMatrix*, and *viewport*. The result is stored in *winx*, *winy*, and *winz*.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Glu.h |
| Library<br> | Glu32.lib |
| DLL<br> | Glu32.dll |

## See also

[**glGetDoublev**](https://learn.microsoft.com/windows/win32/opengl/glgetdoublev)

[**glGetIntegerv**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**gluUnProject**](https://learn.microsoft.com/windows/win32/opengl/gluunproject)

