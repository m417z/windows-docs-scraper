# EndMenu function

## Description

Ends the calling thread's active menu.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If a platform does not support **EndMenu**, send the owner of the active menu a [WM_CANCELMODE](https://learn.microsoft.com/windows/desktop/winmsg/wm-cancelmode) message.

## See also

**Conceptual**

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**

[WM_CANCELMODE](https://learn.microsoft.com/windows/desktop/winmsg/wm-cancelmode)