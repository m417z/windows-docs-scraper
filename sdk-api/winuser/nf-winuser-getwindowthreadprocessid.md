# GetWindowThreadProcessId function

## Description

Retrieves the identifier of the thread that created the specified window and, optionally, the identifier of the process that created the window.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window.

### `lpdwProcessId` [out, optional]

Type: **LPDWORD**

A pointer to a variable that receives the process identifier. If this parameter is not **NULL**, **GetWindowThreadProcessId** copies the identifier of the process to the variable; otherwise, it does not. If the function fails, the value of the variable is unchanged.

## Return value

Type: **DWORD**

If the function succeeds, the return value is the identifier of the thread that created the window. If the window handle is invalid, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Windows Overview](https://learn.microsoft.com/windows/desktop/winmsg/windows)