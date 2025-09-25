# IShellIconOverlayManager::OverlayIndexFromImageIndex

## Description

Finds the index of an overlay image for the specified icon image. It can add an overlay if one is not found for the icon.

## Parameters

### `iImage` [in]

Type: **int**

The existing shell image list index to look for.

### `piIndex` [out]

Type: **int**

The returned overlay index.

### `fAdd` [in]

Type: **BOOL**

Whether to add an image if one is not already present.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The image index was found. |
| **E_FAIL** | An error occurred or the image was not found. |

## See also

[IShellIconOverlay](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-ishelliconoverlay)

[IShellIconOverlayManager](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-ishelliconoverlaymanager)