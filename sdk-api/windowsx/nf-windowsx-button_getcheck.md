# Button_GetCheck macro

## Syntax

```cpp
LRESULT Button_GetCheck(
   HWND hwndCtl
);
```

## Return value

Type: **[LRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The return value from a button created with the **BS_AUTOCHECKBOX**, **BS_AUTORADIOBUTTON**, **BS_AUTO3STATE**, **BS_CHECKBOX**, **BS_RADIOBUTTON**, or **BS_3STATE** style can be one of the following:

| Return code | Description |
|---|---|
| BST_CHECKED | Button is checked. |
| BST_INDETERMINATE | Button is grayed, indicating an indeterminate state (applies only if the button has the BS_3STATE or BS_AUTO3STATE style). |
| BST_UNCHECKED | Button is cleared. |

## Description

Gets the check state of a radio button or check box. You can use this macro or send the [BM_GETCHECK](https://learn.microsoft.com/windows/desktop/Controls/bm-getcheck) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the button control.

## Remarks

If the button has a style other than those listed, the return value is zero.