# Button_GetSplitInfo macro

## Syntax

```cpp
BOOL Button_GetSplitInfo(
  [in]      HWND             hwnd,
  [in, out] BUTTON_SPLITINFO *pInfo
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Does not return a meaningful value.

## Description

Gets information for a specified split button control. Use this macro or send the [BCM_GETSPLITINFO](https://learn.microsoft.com/windows/desktop/Controls/bcm-getsplitinfo) message explicitly.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the button control.

### `pInfo` [in, out]

Type: **[BUTTON_SPLITINFO](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-button_splitinfo)***

A pointer to a [BUTTON_SPLITINFO](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-button_splitinfo) structure to receive information on the button specified by *hwnd*. The calling application is responsible for allocating the memory for the structure. Set the **mask** member of this structure to determine what information to receive.

## Remarks

Use this macro only with the [BS_SPLITBUTTON](https://learn.microsoft.com/windows/desktop/Controls/button-styles) and [BS_DEFSPLITBUTTON](https://learn.microsoft.com/windows/desktop/Controls/button-styles) button styles.

## See also

[Button Styles](https://learn.microsoft.com/windows/desktop/Controls/button-styles)

[Button Types](https://learn.microsoft.com/windows/desktop/Controls/button-types-and-styles)

**Conceptual**

**Reference**