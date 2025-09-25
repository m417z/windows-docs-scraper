# Edit_GetWordBreakProc macro

## Syntax

```cpp
EDITWORDBREAKPROC Edit_GetWordBreakProc(
   HWND hwndCtl
);
```

## Return value

Type: **EDITWORDBREAKPROC**

The address of the application-defined Wordwrap function, or **NULL** if no function has been set.

## Description

Retrieves the address of an edit or rich edit control's Wordwrap function. You can use this macro or send the [EM_GETWORDBREAKPROC](https://learn.microsoft.com/windows/desktop/Controls/em-getwordbreakproc) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

## Remarks

For more information, see [EM_GETWORDBREAKPROC](https://learn.microsoft.com/windows/desktop/Controls/em-getwordbreakproc).