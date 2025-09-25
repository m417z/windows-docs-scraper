# Edit_SetSel macro

## Syntax

```cpp
void Edit_SetSel(
   HWND hwndCtl,
   int  ichStart,
   int  ichEnd
);
```

## Description

Selects a range of characters in an edit or rich edit control. You can use this macro or send the [EM_SETSEL](https://learn.microsoft.com/windows/desktop/Controls/em-setsel) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `ichStart`

Type: **int**

The starting character position of the selection.

### `ichEnd`

Type: **int**

The ending character position of the selection.

## Remarks

For more information, see [EM_SETSEL](https://learn.microsoft.com/windows/desktop/Controls/em-setsel).