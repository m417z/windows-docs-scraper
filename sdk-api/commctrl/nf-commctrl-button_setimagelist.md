# Button_SetImageList macro

## Syntax

```cpp
BOOL Button_SetImageList(
   HWND              hwnd,
   PBUTTON_IMAGELIST pbuttonImagelist
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the macro succeeds, it returns **TRUE**. Otherwise it returns **FALSE**.

## Description

Assigns an image list to a button control. You can use this macro or send the [BCM_SETIMAGELIST](https://learn.microsoft.com/windows/desktop/Controls/bcm-setimagelist) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the button control.

### `pbuttonImagelist`

Type: **PBUTTON_IMAGELIST**

A pointer to a [BUTTON_IMAGELIST](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-button_imagelist) structure that contains the image list information to set.

## Remarks

**Note** To use this macro, you must provide a manifest specifying Comctl32.dll version 6.0. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).