# IShellIconOverlay::GetOverlayIconIndex

## Description

Gets the index of the icon overlay in the system image list.

## Parameters

### `pidl` [in]

Type: **PCUITEMID_CHILD**

Pointer to an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure that identifies the object whose icon is being displayed.

### `pIconIndex` [in, out]

Type: **int***

Pointer to the index of the icon overlay's image in the system image list. This index is equivalent to the *iImage* value that is specified when you add an overlay image to a private image list with the [ImageList::SetOverlayImage](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_setoverlayimage) function.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The index of an overlay was found. |
| **S_FALSE** | No overlay exists for this file. |
| **E_FAIL** | The PIDL is invalid. |

## Remarks

To retrieve the overlay's image index in the system image list, you must first call [SHGetIconOverlayIndex](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgeticonoverlayindexa) to retrieve the overlay index. Then use the [INDEXTOOVERLAYMASK](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-indextooverlaymask) macro to convert the overlay index into the equivalent image index.

## See also

[IShellIconOverlay](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-ishelliconoverlay)