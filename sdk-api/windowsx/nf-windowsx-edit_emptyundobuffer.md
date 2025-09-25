# Edit_EmptyUndoBuffer macro

## Syntax

```cpp
void Edit_EmptyUndoBuffer(
   HWND hwndCtl
);
```

## Description

Resets the undo flag of an edit or rich edit control. The undo flag is set whenever an operation within the edit control can be undone. You can use this macro or send the [EM_EMPTYUNDOBUFFER](https://learn.microsoft.com/windows/desktop/Controls/em-emptyundobuffer) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

## Remarks

For more information, see [EM_EMPTYUNDOBUFFER](https://learn.microsoft.com/windows/desktop/Controls/em-emptyundobuffer).