# GetProcessDefaultLayout function

## Description

Retrieves the default layout that is used when windows are created with no parent or owner.

## Parameters

### `pdwDefaultLayout` [out]

Type: **DWORD***

The current default process layout. For a list of values, see [SetProcessDefaultLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setprocessdefaultlayout).

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The layout specifies how text and graphics are laid out in a window; the default is left to right. The **GetProcessDefaultLayout** function lets you know if the default layout has changed, from using [SetProcessDefaultLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setprocessdefaultlayout).

## See also

**Conceptual**

**Reference**

[SetProcessDefaultLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setprocessdefaultlayout)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)