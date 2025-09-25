# IBrowserService3::_PositionViewWindow

## Description

Deprecated. Used in view size negotiations. This method is called by [_UpdateViewRectSize](https://learn.microsoft.com/windows/win32/api/shdeprecated/nf-shdeprecated-ibrowserservice2-_updateviewrectsize) after determining the available dimensions.

## Parameters

### `hwnd`

Type: **HWND**

The handle of the view window.

### `prc`

Type: **LPRECT**

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the available dimensions.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.