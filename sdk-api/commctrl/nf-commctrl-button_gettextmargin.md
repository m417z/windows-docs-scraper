# Button_GetTextMargin macro

## Syntax

```cpp
BOOL Button_GetTextMargin(
   HWND  hwnd,
   RECT* pmargin
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the macro succeeds, it returns **TRUE**. Otherwise it returns **FALSE**.

## Description

Gets the margins used to draw text in a button control. You can use this macro or send the [BCM_GETTEXTMARGIN](https://learn.microsoft.com/windows/desktop/Controls/bcm-gettextmargin) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the button control.

### `pmargin`

Type: **RECT***

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies the margins to use for drawing text in a button control.

## Remarks

**Note** To use this macro, you must provide a manifest specifying Comctl32.dll version 6.0. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).