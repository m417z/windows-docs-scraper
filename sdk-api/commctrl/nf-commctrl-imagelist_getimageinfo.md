# ImageList_GetImageInfo function

## Description

Retrieves information about an image.

## Parameters

### `himl`

Type: **HIMAGELIST**

A handle to the image list.

### `i`

Type: **int**

The index of the image.

### `pImageInfo`

Type: **[IMAGEINFO](https://learn.microsoft.com/windows/desktop/api/commoncontrols/ns-commoncontrols-imageinfo)***

A pointer to an [IMAGEINFO](https://learn.microsoft.com/windows/desktop/api/commoncontrols/ns-commoncontrols-imageinfo) structure that receives information about the image. The information in this structure can be used to directly manipulate the bitmaps for the image.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Remarks

An application should not call [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) to destroy the bitmaps retrieved by **ImageList_GetImageInfo**. The system destroys the bitmaps when the application calls the [ImageList_Destroy](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_destroy) function.