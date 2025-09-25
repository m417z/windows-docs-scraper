# IExplorerBrowser::SetFolderSettings

## Description

Sets the folder settings for the current view.

## Parameters

### `pfs` [in]

Type: **const [FOLDERSETTINGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-foldersettings)***

A pointer to a [FOLDERSETTINGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-foldersettings) structure that contains the folder settings to be applied.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method also changes the default that will be applied when navigating to another location.

To ensure the view state is preserved across sessions, specify the persistence name using [IExplorerBrowser::SetPropertyBag](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerbrowser-setpropertybag).

## See also

[FOLDERSETTINGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-foldersettings)

[IExplorerBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iexplorerbrowser)