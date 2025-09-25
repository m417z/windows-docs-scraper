# IMAGEINFO structure

## Description

Contains information about an image in an image list. This structure is used with the [IImageList::GetImageInfo](https://learn.microsoft.com/windows/desktop/api/commoncontrols/nf-commoncontrols-iimagelist-getimageinfo) function.

## Members

### `hbmImage`

Type: **[HBITMAP](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the bitmap that contains the images.

### `hbmMask`

Type: **[HBITMAP](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a monochrome bitmap that contains the masks for the images. If the image list does not contain a mask, this member is **NULL**.

### `Unused1`

Type: **int**

Not used. This member should always be zero.

### `Unused2`

Type: **int**

Not used. This member should always be zero.

### `rcImage`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

The bounding rectangle of the specified image within the bitmap specified by
**hbmImage**.