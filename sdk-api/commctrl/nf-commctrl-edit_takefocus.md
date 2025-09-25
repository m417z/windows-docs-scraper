# Edit_TakeFocus macro

## Syntax

```cpp
DWORD Edit_TakeFocus(
   HWND hwndCtl
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The return value is not used.

## Description

[Intended for internal use; not recommended for use in applications. This macro may not be supported in future versions of Windows.]

Forces a single-line edit control to receive keyboard focus. You can use this macro or send the [EM_TAKEFOCUS](https://learn.microsoft.com/windows/desktop/Controls/em-takefocus) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the edit control.

## Remarks

The [EM_TAKEFOCUS](https://learn.microsoft.com/windows/desktop/Controls/em-takefocus) message is ignored if the edit control is not a single-line edit control.

If the edit control previously received an [EM_NOSETFOCUS](https://learn.microsoft.com/windows/desktop/Controls/em-nosetfocus) message, the edit control will appear to have the focus without actually having it; otherwise, the edit control will receive focus.

## See also

[EM_NOSETFOCUS](https://learn.microsoft.com/windows/desktop/Controls/em-nosetfocus)

[EM_TAKEFOCUS](https://learn.microsoft.com/windows/desktop/Controls/em-takefocus)

**Reference**