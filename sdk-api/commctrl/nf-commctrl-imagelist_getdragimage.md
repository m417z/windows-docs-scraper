# ImageList_GetDragImage function

## Description

Retrieves the temporary image list that is used for the drag image. The function also retrieves the current drag position and the offset of the drag image relative to the drag position.

## Parameters

### `ppt`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)***

A pointer to a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that receives the current drag position. Can be **NULL**.

### `pptHotspot`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)***

A pointer to a **POINT** structure that receives the offset of the drag image relative to the drag position. Can be **NULL**.

## Return value

Type: **HIMAGELIST**

Returns the handle to the image list if successful, or **NULL** otherwise.

## Remarks

The temporary image list is destroyed when the [ImageList_EndDrag](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_enddrag) function is called. To begin a drag operation, use the [ImageList_BeginDrag](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_begindrag) function.