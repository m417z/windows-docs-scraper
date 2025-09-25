# Edit_SetWordBreakProc macro

## Syntax

```cpp
void Edit_SetWordBreakProc(
   HWND              hwndCtl,
   EDITWORDBREAKPROC lpfnWordBreak
);
```

## Description

Replaces an edit control's default Wordwrap function with an application-defined Wordwrap function. You can use this macro or send the [EM_SETWORDBREAKPROC](https://learn.microsoft.com/windows/desktop/Controls/em-setwordbreakproc) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `lpfnWordBreak`

Type: **EDITWORDBREAKPROC**

The address of the application-defined Wordwrap function. For more information about breaking lines, see the description of the [EditWordBreakProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-editwordbreakproca) callback function.

## Remarks

For more information, see [EM_SETWORDBREAKPROC](https://learn.microsoft.com/windows/desktop/Controls/em-setwordbreakproc).