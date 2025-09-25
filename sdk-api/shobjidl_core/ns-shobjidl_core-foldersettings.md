# FOLDERSETTINGS structure

## Description

Contains folder view information.

## Members

### `ViewMode`

Type: **UINT**

Folder view mode. One of the [FOLDERVIEWMODE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-folderviewmode) values.

### `fFlags`

Type: **UINT**

A set of flags that indicate the options for the folder. This can be zero or a combination of the [FOLDERFLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-folderflags) values.

## Remarks

These settings assume a particular user interface, which the Shell's folder view has. A Shell extension can use these settings if they apply to the view implemented by the extension.

## See also

[IShellView::CreateViewWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellview-createviewwindow)

[IShellView::GetCurrentInfo](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellview-getcurrentinfo)