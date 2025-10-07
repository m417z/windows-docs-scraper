# gluGetTessProperty function

The **gluGetTessProperty** function gets a tessellation object property.

## Parameters

*tess*

The tessellation object (created with [**gluNewTess**](https://learn.microsoft.com/windows/win32/opengl/glunewtess)).

*which*

The property whose value is to be retrieved. The following values are valid: GLU\_TESS\_WINDING\_RULE, GLU\_TESS\_BOUNDARY\_ONLY, and GLU\_TESS\_TOLERANCE.

*value*

A pointer to the location where the value of the named property is written.

## Return value

This function does not return a value.

## Remarks

Use **gluGetTessProperty** to retrieve properties stored in a tessellation object. These properties affect the way tessellation objects are interpreted and rendered. For information about what the properties are and what they do, see [**gluTessProperty**](https://learn.microsoft.com/windows/win32/opengl/glutessproperty).

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Glu.h |
| Library<br> | Glu32.lib |
| DLL<br> | Glu32.dll |

## See also

[**gluNewTess**](https://learn.microsoft.com/windows/win32/opengl/glunewtess)

[**gluTessProperty**](https://learn.microsoft.com/windows/win32/opengl/glutessproperty)

