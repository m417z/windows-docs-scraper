# GetClassInfoW function

## Description

Retrieves information about a window class.

**Note** The **GetClassInfo** function has been superseded by the [GetClassInfoEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclassinfoexa) function. You can still use **GetClassInfo**, however, if you do not need information about the class small icon.

## Parameters

### `hInstance` [in, optional]

Type: **HINSTANCE**

A handle to the instance of the application that created the class. To retrieve information about classes defined by the system (such as buttons or list boxes), set this parameter to **NULL**.

### `lpClassName` [in]

Type: **LPCTSTR**

The class name. The name must be that of a preregistered class or a class registered by a previous call to the [RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa) or [RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa) function.

Alternatively, this parameter can be an atom. If so, it must be a class atom created by a previous call to [RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa) or [RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa). The atom must be in the low-order word of
*lpClassName*; the high-order word must be zero.

### `lpWndClass` [out]

Type: **LPWNDCLASS**

A pointer to a [WNDCLASS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassa) structure that receives the information about the class.

## Return value

Type: **BOOL**

If the function finds a matching class and successfully copies the data, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

**Conceptual**

[GetClassInfoEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclassinfoexa)

[GetClassLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclasslonga)

[GetClassName](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclassname)

**Reference**

[RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa)

[RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa)

[WNDCLASS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassa)

[Window Classes](https://learn.microsoft.com/windows/desktop/winmsg/window-classes)

## Remarks

> [!NOTE]
> The winuser.h header defines GetClassInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).