# DAD_SetDragImage function

## Description

[**DAD_SetDragImage** is available in Windows 2000 and Windows XP. It might be altered or unavailable in subsequent versions. Use [ImageList_BeginDrag](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_begindrag) instead.]

Sets the drag image.

## Parameters

### `him`

Type: **HIMAGELIST**

A handle to an image list. This parameter uses the zero index in the ImageList.

### `pptOffset`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)***

A pointer to the coordinates used as the hot spot for dragging the image. The coordinates are relative to upper-left corner of the image.

## Return value

Type: **BOOL**

Returns nonzero if successful, or zero otherwise.

## Remarks

You can clear the drag image by setting the *him* parameter to `-1` and the *pptOffset* parameter to `NULL`. The image must have been set within the same thread.