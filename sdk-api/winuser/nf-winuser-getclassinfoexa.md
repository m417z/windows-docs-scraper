# GetClassInfoExA function

## Description

Retrieves information about a window class, including a handle to the small icon associated with the window class. The [GetClassInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclassinfoa) function does not retrieve a handle to the small icon.

## Parameters

### `hInstance` [in, optional]

Type: **HINSTANCE**

A handle to the instance of the application that created the class. To retrieve information about classes defined by the system (such as buttons or list boxes), set this parameter to **NULL**.

### `lpszClass` [in]

Type: **LPCTSTR**

The class name. The name must be that of a preregistered class or a class registered by a previous call to the [RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa) or [RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa) function. Alternatively, this parameter can be a class atom created by a previous call to **RegisterClass** or **RegisterClassEx**. The atom must be in the low-order word of
*lpszClass*; the high-order word must be zero.

### `lpwcx` [out]

Type: **LPWNDCLASSEX**

A pointer to a [WNDCLASSEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassexa) structure that receives the information about the class.

## Return value

Type: **BOOL**

If the function finds a matching class and successfully copies the data, the return value is nonzero.

If the function does not find a matching class and successfully copy the data, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Class atoms are created using the [RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa) or [RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa) function, not the
[GlobalAddAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globaladdatoma) function.

> [!NOTE]
> The winuser.h header defines GetClassInfoEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[GetClassLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclasslonga)

[GetClassName](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclassname)

**Reference**

[RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa)

[RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa)

[Window Classes](https://learn.microsoft.com/windows/desktop/winmsg/window-classes)