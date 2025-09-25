# Button_SetState macro

## Syntax

```cpp
LRESULT Button_SetState(
   HWND hwndCtl,
   BOOL state
);
```

## Return value

Type: **[LRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The return value is always zero.

## Description

Sets the highlight state of a button. The highlight state indicates whether the button is highlighted as if the user had pushed it. You can use this macro or send the [BM_SETSTATE](https://learn.microsoft.com/windows/desktop/Controls/bm-setstate) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the button control.

### `state`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** to highlight the button; otherwise **FALSE**.

## Remarks

Highlighting affects only the appearance of a button. It has no effect on the check state of a radio button or check box.

A button is automatically highlighted when the user positions the cursor over it and presses and holds the left mouse button. The highlighting is removed when the user releases the mouse button.