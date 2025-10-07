# EXT\_BUTTON structure

Contains information about a button that a File Manager extension DLL is adding to the toolbar of File Manager.

## Members

**idCommand**

Type: **WORD**

A command identifier for the button.

**idsHelp**

Type: **WORD**

The identifier of the Help string for the button.

**fsStyle**

Type: **WORD**

The style of the button.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Wfext.h |

## See also

[**FMEVENT\_TOOLBARLOAD**](https://learn.microsoft.com/windows/win32/shell/fmevent-toolbarload)

[**FMS\_TOOLBARLOAD**](https://learn.microsoft.com/windows/win32/shell/fms-toolbarload)

