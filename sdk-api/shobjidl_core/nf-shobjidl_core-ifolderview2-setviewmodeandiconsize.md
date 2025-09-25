# IFolderView2::SetViewModeAndIconSize

## Description

Sets and applies the view mode and image size.

## Parameters

### `uViewMode` [in]

Type: **[FOLDERVIEWMODE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-folderviewmode)**

The [FOLDERVIEWMODE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-folderviewmode) to be applied.

### `iImageSize` [in]

Type: **int**

The size of the image in pixels.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If *iImageSize* is -1 then the current default icon size for the view mode is used.