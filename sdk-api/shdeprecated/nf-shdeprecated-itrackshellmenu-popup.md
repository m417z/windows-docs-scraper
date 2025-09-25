# ITrackShellMenu::Popup

## Description

Displays a modal pop-up menu at a specific location.

## Parameters

### `hwnd` [in]

Type: **HWND**

The handle of the parent window of the pop-up menu.

### `ppt` [in]

Type: **[POINTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-pointl)***

A pointer to a [POINTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-pointl) structure that specifies an initial point in screen coordinates. The pop-up menu is displayed in relation to this point as determined by the position flags set in *dwFlags*.

### `prcExclude` [in]

Type: **[RECTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rectl)***

A pointer to a [RECTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rectl) structure that specifies the rectangle to exclude when positioning the menu. The alignment of the menu in relation to this area is determined by the alignment flags set in *dwFlags*. This parameter can be set to **NULL**.

### `dwFlags` [in]

Type: **MP_POPUPFLAGS**

One or more of the [MP_POPUPFLAGS](https://learn.microsoft.com/windows/desktop/shell/mp-popupflags) constants that specify options involved in the display of the pop-up menu.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.