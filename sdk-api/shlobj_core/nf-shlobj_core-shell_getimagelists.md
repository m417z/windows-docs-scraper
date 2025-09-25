# Shell_GetImageLists function

## Description

[This function is available through Windows XP Service Pack 2 (SP2) and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows.]

Retrieves system image lists for large and small icons.

## Parameters

### `phiml` [in]

Type: **HIMAGELIST***

A pointer to the handle of an image list which, on success, receives the system image list for large (32 x 32) icons.

### `phimlSmall` [in]

Type: **HIMAGELIST***

A pointer to the handle of an image list which, on success, receives the system image list for small (16 x 16) icons.

## Return value

Type: **BOOL**

Returns **TRUE** on success. On failure, returns **FALSE** and the image lists pointed to by *phiml* and *phimlSmall* are unchanged.

## Remarks

**Important** The image lists retrieved through this function are global system image lists; do not call [ImageList_Destroy](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_destroy) using them.

## See also

[Image Lists](https://learn.microsoft.com/windows/desktop/Controls/image-list-reference)

[SHGetFileInfo](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shgetfileinfoa)

[SHGetImageList](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shgetimagelist)