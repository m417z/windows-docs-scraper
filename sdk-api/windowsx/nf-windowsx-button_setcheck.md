# Button_SetCheck macro

## Syntax

```cpp
LRESULT Button_SetCheck(
   HWND hwndCtl,
   int  check
);
```

## Return value

Type: **[LRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The return value is always zero.

## Description

Sets the check state of a radio button or check box. You can use this macro or send the [BM_SETCHECK](https://learn.microsoft.com/windows/desktop/Controls/bm-setcheck) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the button control.

### `check`

Type: **int**

The check state. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **BST_CHECKED** | Sets the button state to checked. |
| **BST_INDETERMINATE** | Sets the button state to grayed, indicating an indeterminate state. Use this value only if the button has the [BS_3STATE](https://learn.microsoft.com/windows/desktop/Controls/button-styles) or [BS_AUTO3STATE](https://learn.microsoft.com/windows/desktop/Controls/button-styles) style. |
| **BST_UNCHECKED** | Sets the button state to cleared. |

## Remarks

The macro has no effect on push buttons.