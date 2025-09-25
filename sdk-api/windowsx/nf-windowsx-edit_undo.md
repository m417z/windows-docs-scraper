# Edit_Undo macro

## Syntax

```cpp
BOOL Edit_Undo(
   HWND hwndCtl
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

For a single-line control, the return value is always **TRUE**. For a multiline control, the return value is **TRUE** if the undo operation is successful, or **FALSE** otherwise.

## Description

Undoes the last operation in the undo queue of an edit or rich edit control. You can use this macro or send the [EM_UNDO](https://learn.microsoft.com/windows/desktop/Controls/em-undo) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

## Remarks

For more information, see [EM_UNDO](https://learn.microsoft.com/windows/desktop/Controls/em-undo).