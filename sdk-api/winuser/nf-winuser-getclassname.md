# GetClassName function

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

If the function succeeds, the return value is the number of characters copied to the buffer, not including the terminating null character.

If the function fails, the return value is zero. To get extended error information, call [GetLastError function](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[FindWindowA function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-findwindowa), [GetClassInfoA function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getclassinfoa), [GetClassLongA function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getclasslonga), [GetClassWord function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getclassword), [Window Classes](https://learn.microsoft.com/windows/desktop/winmsg/window-classes)