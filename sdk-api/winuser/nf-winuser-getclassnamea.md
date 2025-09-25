# GetClassNameA function

## Description

Retrieves the name of the class to which the specified window belongs.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window and, indirectly, the class to which the window belongs.

### `lpClassName` [out]

Type: **LPTSTR**

The class name string.

### `nMaxCount` [in]

Type: **int**

The length of the *lpClassName* buffer, in characters. The buffer must be large enough to include the terminating null character; otherwise, the class name string is truncated to `nMaxCount-1` characters.

## Return value

Type: **int**

If the function succeeds, the return value is the number of
characters copied to the buffer, not including the terminating null character.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

**Conceptual**

[FindWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-findwindowa)

[GetClassInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclassinfoa)

[GetClassLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclasslonga)

[GetClassWord](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclassword)

**Reference**

[Window Classes](https://learn.microsoft.com/windows/desktop/winmsg/window-classes)

## Remarks

> [!NOTE]
> The winuser.h header defines GetClassName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).