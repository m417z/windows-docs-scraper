# Edit_CanUndo macro

## Syntax

```cpp
BOOL Edit_CanUndo(
   HWND hwndCtl
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

**TRUE** if there are actions in the undo queue; otherwise **FALSE**.

## Description

Determines whether there are any actions in the undo queue of an edit or rich edit control. You can use this macro or send the [EM_CANUNDO](https://learn.microsoft.com/windows/desktop/Controls/em-canundo) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

## Remarks

For more information, see [EM_CANUNDO](https://learn.microsoft.com/windows/desktop/Controls/em-canundo).