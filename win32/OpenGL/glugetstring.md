# gluGetString function

The **gluGetString** function gets a string that describes the GLU version number or supported GLU extension calls.

## Parameters

*name*

Either the version number of GLU (GLU\_VERSION) or available vendor-specific extension calls (GLU\_EXTENSIONS).

## Remarks

The **gluGetString** function returns a pointer to a static, null-terminated string. When *name* is GLU\_VERSION, the returned string is a value that represents the version number of GLU. The format of the version number is as follows:

``` syntax
<version number><space><vendor-specific information>
(for example, "1.2.11 Microsoft Windows")
```

The version number has the form "major\_number.minor\_number" or "major\_number.minor\_number.release\_number". The vendor-specific information is optional, and the format and contents depend on the implementation.

When *name* is GLU\_EXTENSIONS, the returned string contains a list of names of supported GLU extensions that are separated by spaces. The format of the returned list of names is as follows:

``` syntax
<extension_name><space><extension_name><space> . . .
(for example, "GLU_NURBS GL_TESSELATION")
```

The extension names cannot contain any spaces.

The **gluGetString** function is valid for GLU version 1.1 or later.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Glu.h |
| Library<br> | Glu32.lib |
| DLL<br> | Glu32.dll |

