# Edit_GetModify macro

## Syntax

```cpp
BOOL Edit_GetModify(
   HWND hwndCtl
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the contents of edit control have been modified, the return value is nonzero; otherwise, it is zero.

## Description

Gets the state of an edit or rich edit control's modification flag. The flag indicates whether the contents of the control have been modified. You can use this macro or send the [EM_GETMODIFY](https://learn.microsoft.com/windows/desktop/Controls/em-getmodify) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

## Remarks

For more information, see [EM_GETMODIFY](https://learn.microsoft.com/windows/desktop/Controls/em-getmodify).