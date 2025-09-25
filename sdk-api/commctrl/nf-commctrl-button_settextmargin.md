# Button_SetTextMargin macro

## Syntax

```cpp
BOOL Button_SetTextMargin(
   HWND hwnd,
   RECT *pmargin
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the macro succeeds, it returns **TRUE**. Otherwise it returns **FALSE**.

## Description

Sets the margins for drawing text in a button control. You can use this macro or send the [BCM_SETTEXTMARGIN](https://learn.microsoft.com/windows/desktop/Controls/bcm-settextmargin) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the button control.

### `pmargin`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies the margins to set for drawing text in a button control.

## Remarks

To use this macro, you must provide a manifest specifying Comctl32.dll version 6.0. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).