# IFolderView2::GetViewModeAndIconSize

## Description

Gets the current view mode and icon size applied to the view.

## Parameters

### `puViewMode` [out]

Type: **[FOLDERVIEWMODE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-folderviewmode)***

A pointer to the current [FOLDERVIEWMODE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-folderviewmode).

### `piImageSize` [out]

Type: **int***

A pointer to the size of the icon in pixels.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.