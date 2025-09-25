# IShellIconOverlayManager::RefreshOverlayImages

## Description

Refreshes the overlay cache, the image list, or both.

## Parameters

### `dwFlags` [in]

Type: **DWORD**

Determines what to refresh. It can be a bitwise OR one of the following:

#### SIOM_ICONINDEX

Reloads the icons into the image list.

#### SIOM_OVERLAYINDEX

Reloads the overlay cache.

## Return value

Type: **HRESULT**

This method always returns S_OK.

## See also

[IShellIconOverlay](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-ishelliconoverlay)

[IShellIconOverlayManager](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-ishelliconoverlaymanager)