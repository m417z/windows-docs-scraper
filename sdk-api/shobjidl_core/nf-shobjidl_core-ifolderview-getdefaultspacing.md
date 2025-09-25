# IFolderView::GetDefaultSpacing

## Description

Gets a pointer to a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure containing the default width (x) and height (y) measurements of an item, including the surrounding white space.

## Parameters

### `ppt` [out]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)***

Pointer to an existing structure to be filled with the default sizing dimensions of the items in the folder's view.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IFolderView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifolderview)

[IFolderView::GetSpacing](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifolderview-getspacing)