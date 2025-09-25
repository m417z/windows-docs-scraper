# GetAncestor function

## Description

Retrieves the handle to the ancestor of the specified window.

## Parameters

### `hwnd` [in]

Type: **HWND**

A handle to the window whose ancestor is to be retrieved. If this parameter is the desktop window, the function returns **NULL**.

### `gaFlags` [in]

Type: **UINT**

The ancestor to be retrieved. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **GA_PARENT**<br><br>1 | Retrieves the parent window. This does not include the owner, as it does with the [GetParent](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getparent) function. |
| **GA_ROOT**<br><br>2 | Retrieves the root window by walking the chain of parent windows. |
| **GA_ROOTOWNER**<br><br>3 | Retrieves the owned root window by walking the chain of parent and owner windows returned by [GetParent](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getparent). |

## Return value

Type: **HWND**

The return value is the handle to the ancestor window.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

**Conceptual**

[GetParent](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getparent)

**Reference**

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)