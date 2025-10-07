# glDepthFunc function

The **glDepthFunc** function specifies the value used for depth-buffer comparisons.

## Parameters

*func*

Specifies the depth-comparison function. The following symbolic constants are accepted.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------|
|

**GL\_NEVER**

| Never passes.<br> |
|

**GL\_LESS**

| Passes if the incoming *z* value is less than the stored *z* value. This is the default value.<br> |
|

**GL\_LEQUAL**

| Passes if the incoming z value is less than or equal to the stored z value.<br> |
|

**GL\_EQUAL**

| Passes if the incoming z value is equal to the stored z value.<br> |
|

**GL\_GREATER**

| Passes if the incoming z value is greater than the stored z value.<br> |
|

**GL\_NOTEQUAL**

| Passes if the incoming z value is not equal to the stored z value.<br> |
|

**GL\_GEQUAL**

| Passes if the incoming z value is greater than or equal to the stored z value.<br> |
|

**GL\_ALWAYS**

| Always passes.<br> |

## Return value

This function does not return a value.

## Error codes

The following error code can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glDepthFunc** function specifies the function used to compare each incoming pixel *z* value with the *z* value present in the depth buffer. The comparison is performed only if depth testing is enabled. (See [**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable) with the argument GL\_DEPTH\_TEST.)

Initially, depth testing is disabled.

The following functions retrieve information related to **glDepthFunc**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_DEPTH\_FUNC

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled) with argument GL\_DEPTH\_TEST

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

[**glDepthRange**](https://learn.microsoft.com/windows/win32/opengl/gldepthrange)

[**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled)

