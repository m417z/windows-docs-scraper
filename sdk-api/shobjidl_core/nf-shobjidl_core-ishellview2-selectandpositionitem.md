# IShellView2::SelectAndPositionItem

## Description

Selects and positions an item in a Shell View.

## Parameters

### `pidlItem`

Type: **PCUITEMID_CHILD**

A pointer to an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure that uniquely identifies the item of interest.

### `uFlags`

Type: **UINT**

One of the [_SVSIF](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_svsif) constants that specify the type of selection to apply.

### `ppt`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)***

A pointer to a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure containing the new position.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.