# IShellIconOverlay::GetOverlayIndex

## Description

Gets the overlay index in the system image list.

## Parameters

### `pidl` [in]

Type: **PCUITEMID_CHILD**

Pointer to an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure that identifies the object whose icon is being displayed.

### `pIndex` [in, out]

Type: **int***

Pointer to a value that states the overlay index (one-based) in the system image list. This index is equivalent to the *iOverlay* value that is specified when you add an overlay image to a private image list with the [ImageList::SetOverlayImage](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_setoverlayimage) function.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The index of an overlay was found. |
| **S_FALSE** | No overlay exists for this file. |
| **E_FAIL** | The PIDL is invalid. |
| **E_INVALIDARG** | The argument is invalid, for example, if *pIndex* is **NULL**. |
| **E_PENDING** | The calling application passed OI_ASYNC to signify that the operation of calculating the overlay index will take some time. |

## Remarks

To retrieve the overlay index in the system image list, call [SHGetIconOverlayIndex](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgeticonoverlayindexa).

If you set *pIndex* to point to OI_ASYNC when you call this method, the Shell icon overlay handler might return E_PENDING instead of storing the overlay index in *pIndex*. This return value indicates that computing the overlay is a slow operation and should be handled in the background. When an [IShellIconOverlay](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-ishelliconoverlay) implementation returns E_PENDING, it is called back on a background worker thread without the OI_ASYNC flag. If you do not use OI_ASYNC when you call **GetOverlayIndex**, the overlay handler must compute the overlay index and store the value in *pIndex* before returning.

## See also

[IShellIconOverlay](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-ishelliconoverlay)