# IFolderView::SelectAndPositionItems

## Description

Allows the selection and positioning of items visible in the folder's view.

## Parameters

### `cidl` [in]

Type: **UINT**

The number of items to select.

### `apidl` [in]

Type: **PCUITEMID_CHILD_ARRAY***

A pointer to an array of size *cidl* that contains the PIDLs of the items.

### `apt` [in]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)***

A pointer to an array of *cidl* structures containing the locations each corresponding element in *apidl* should be positioned.

### `dwFlags` [in]

Type: **DWORD**

One of the [_SVSIF](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_svsif) constants that specifies the type of selection to apply.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[FOLDERVIEWOPTIONS](https://learn.microsoft.com/windows/desktop/api/shobjidl/ne-shobjidl-folderviewoptions)

[IFolderView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifolderview)

[IFolderView::SelectItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifolderview-selectitem)

[SelectItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellview-selectitem)