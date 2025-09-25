# IFolderView::GetCurrentViewMode

## Description

Gets an address containing a value representing the folder's current view mode.

## Parameters

### `pViewMode` [out]

Type: **UINT***

A pointer to a memory location at which to store the folder's current view mode. The value at that address is one of the following [FOLDERVIEWMODE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-folderviewmode) values.

#### FVM_ICON

Medium icons

#### FVM_SMALLICON

Small icons

#### FVM_LIST

List view without details

#### FVM_DETAILS

Show details (size, type, last modification date)

#### FVM_THUMBNAIL

Thumbnail view

#### FVM_TILE

Large icons

#### FVM_THUMBSTRIP

Filmstrip view

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[GetCurrentInfo](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellview-getcurrentinfo)

[IFolderView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifolderview)

[IFolderView::SetCurrentViewMode](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifolderview-setcurrentviewmode)