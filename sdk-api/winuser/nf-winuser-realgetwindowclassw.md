# RealGetWindowClassW function

## Description

Retrieves a string that specifies the window type.

## Parameters

### `hwnd` [in]

Type: **HWND**

A handle to the window whose type will be retrieved.

### `ptszClassName` [out]

Type: **LPTSTR**

A pointer to a string that receives the window type.

### `cchClassNameMax` [in]

Type: **UINT**

The length, in characters, of the buffer pointed to by the *pszType* parameter.

## Return value

Type: **UINT**

If the function succeeds, the return value is the number of characters copied to the specified buffer.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Windows Overview](https://learn.microsoft.com/windows/desktop/winmsg/windows)