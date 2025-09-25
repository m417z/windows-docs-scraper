# IFolderView::SetCurrentViewMode

## Description

Sets the selected folder's view mode.

## Parameters

### `ViewMode` [in]

Type: **UINT**

One of the following values from the [FOLDERVIEWMODE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-folderviewmode) enumeration.

#### FVM_ICON

Medium icons

#### FVM_SMALLICON

Small icons

#### FVM_LIST

List view without details. This view also uses small icons, but they cannot be rearranged as they can be when using **FVM_SMALLICON**.

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

[CreateViewWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellview-createviewwindow)

[IFolderView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifolderview)

[IFolderView::GetCurrentViewMode](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifolderview-getcurrentviewmode)