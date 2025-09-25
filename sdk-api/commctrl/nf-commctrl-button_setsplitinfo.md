# Button_SetSplitInfo macro

## Syntax

```cpp
BOOL Button_SetSplitInfo(
  [in] HWND             hwnd,
  [in] BUTTON_SPLITINFO *pInfo
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Sets information for a specified split button control. Use this macro or send the [BCM_SETSPLITINFO](https://learn.microsoft.com/windows/desktop/Controls/bcm-setsplitinfo) message explicitly.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the button control.

### `pInfo` [in]

Type: **[BUTTON_SPLITINFO](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-button_splitinfo)***

A pointer to a [BUTTON_SPLITINFO](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-button_splitinfo) structure. The calling application is responsible for allocating the memory for this structure and initializing it. Set the **mask** member of this structure to determine what information to set for the button specified by *hwnd*.

## Remarks

Use this macro only with the [BS_SPLITBUTTON](https://learn.microsoft.com/windows/desktop/Controls/button-styles) and [BS_DEFSPLITBUTTON](https://learn.microsoft.com/windows/desktop/Controls/button-styles) button styles.

## See also

[Button Styles](https://learn.microsoft.com/windows/desktop/Controls/button-styles)

[Button Types](https://learn.microsoft.com/windows/desktop/Controls/button-types-and-styles)

**Conceptual**

**Reference**