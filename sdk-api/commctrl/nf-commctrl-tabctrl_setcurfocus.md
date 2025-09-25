# TabCtrl_SetCurFocus macro

## Syntax

```cpp
VOID TabCtrl_SetCurFocus(
   HWND hwnd,
   int  i
);
```

## Return value

Type: **[VOID](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

No return value.

## Description

Sets the focus to a specified tab in a tab control. You can use this macro or send the [TCM_SETCURFOCUS](https://learn.microsoft.com/windows/desktop/Controls/tcm-setcurfocus) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tab control.

### `i`

Type: **int**

Zero-based index of the tab that gets the focus.

## Remarks

If the tab control has the [TCS_BUTTONS](https://learn.microsoft.com/windows/desktop/Controls/tab-control-styles) style (button mode), the tab with the focus may be different from the selected tab. For example, when a tab is selected, the user can press the arrow keys to set the focus to a different tab without changing the selected tab. In button mode, the **TabCtrl_SetCurFocus** macro sets the input focus to the button associated with the specified tab, but it does not change the selected tab.

If the tab control does not have the [TCS_BUTTONS](https://learn.microsoft.com/windows/desktop/Controls/tab-control-styles) style, changing the focus also changes the selected tab. In this case, the tab control sends the [TCN_SELCHANGING](https://learn.microsoft.com/windows/desktop/Controls/tcn-selchanging) and [TCN_SELCHANGE](https://learn.microsoft.com/windows/desktop/Controls/tcn-selchange) notification codes to its parent window.

## See also

**Reference**

[TCM_GETCURFOCUS](https://learn.microsoft.com/windows/desktop/Controls/tcm-getcurfocus)

[TabCtrl_GetCurFocus](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-tabctrl_getcurfocus)