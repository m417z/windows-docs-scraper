# Button_GetState macro

## Syntax

```cpp
LRESULT Button_GetState(
   HWND hwndCtl
);
```

## Return value

Type: **[LRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The return value specifies the current state of the button. It is a combination of the following values:

| Return code | Description |
|---|---|
| BST_CHECKED | The button is checked. |
| BST_DROPDOWNPUSHED | Windows Vista. The button is in the drop-down state. Applies only if the button has the TBSTYLE_DROPDOWN style. |
| BST_FOCUS | The button has the keyboard focus. |
| BST_HOT | The button is hot; that is, the mouse is hovering over it. |
| BST_INDETERMINATE | The state of the button is indeterminate. Applies only if the button has the BS_3STATE or BS_AUTO3STATE style. |
| BST_PUSHED | The button is being shown in the pushed state. |
| BST_UNCHECKED | No special state. Equivalent to zero. |

## Description

Retrieves the state of a button or check box. You can use this macro or send the [BM_GETSTATE](https://learn.microsoft.com/windows/desktop/Controls/bm-getstate) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the button control.

## See also

[Button_GetCheck](https://learn.microsoft.com/windows/desktop/api/windowsx/nf-windowsx-button_getcheck)

[Button_SetState](https://learn.microsoft.com/windows/desktop/api/windowsx/nf-windowsx-button_setstate)

**Reference**