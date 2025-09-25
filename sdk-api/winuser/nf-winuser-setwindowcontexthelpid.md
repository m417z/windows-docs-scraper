# SetWindowContextHelpId function

## Description

Associates a Help context identifier with the specified window.

## Parameters

### `unnamedParam1`

Type: **HWND**

A handle to the window with which to associate the Help context identifier.

### `unnamedParam2`

Type: **DWORD**

The Help context identifier.

## Return value

Type: **BOOL**

Returns nonzero if successful, or zero otherwise.

To retrieve extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If a child window does not have a Help context identifier, it inherits the identifier of its parent window. Likewise, if an owned window does not have a Help context identifier, it inherits the identifier of its owner window. This inheritance of Help context identifiers allows an application to set just one identifier for a dialog box and all of its controls.

## See also

[GetWindowContextHelpId](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowcontexthelpid)