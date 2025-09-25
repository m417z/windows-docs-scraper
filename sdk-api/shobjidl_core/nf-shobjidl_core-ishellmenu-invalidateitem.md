# IShellMenu::InvalidateItem

## Description

Redraws an item in a menu band.

## Parameters

### `psmd` [in]

Type: **LPSMDATA**

A pointer to an [SMDATA](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-smdata) structure that identifies the item to be redrawn. Set this value to **NULL** to redraw the entire menu.

### `dwFlags` [in]

Type: **DWORD**

Flags that control how the menu is redrawn. If *psmd* is **NULL**, set *dwFlags* to SMINV_REFRESH. If *psmd* is set to a valid [SMDATA](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-smdata) structure, set *dwFlags* to SMINV_ID | SMINV_REFRESH.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.