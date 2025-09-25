# Edit_NoSetFocus macro

## Syntax

```cpp
DWORD Edit_NoSetFocus(
   HWND hwndCtl
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The return value is not used.

## Description

[Intended for internal use; not recommended for use in applications. This macro may not be supported in future versions of Windows.]

Prevents a single-line edit control from receiving keyboard focus. You can use this macro or send the [EM_NOSETFOCUS](https://learn.microsoft.com/windows/desktop/Controls/em-nosetfocus) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the edit control.

## Remarks

The [EM_NOSETFOCUS](https://learn.microsoft.com/windows/desktop/Controls/em-nosetfocus) message is ignored if the edit control is not a single-line edit control.

After this message is sent, the effect is permanent.

## See also

[EM_NOSETFOCUS](https://learn.microsoft.com/windows/desktop/Controls/em-nosetfocus)