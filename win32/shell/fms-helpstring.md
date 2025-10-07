# FMS\_HELPSTRING structure

Contains information that File Manager uses to add a Help string for a menu or toolbar command item.

## Members

**idCommand**

Type: **INT**

The identifier of the command item.

**hMenu**

Type: **HMENU**

The identifier of the menu bar.

**szHelp**

Type: **\_\_wchar\_t\[128\]**

The null-terminated string that receives the Help text.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Wfext.h |

## See also

[**FMExtensionProc**](https://learn.microsoft.com/windows/win32/shell/fmextensionproc)

[**FMEVENT\_HELPMENUITEM**](https://learn.microsoft.com/windows/win32/shell/fmevent-helpmenuitem)

