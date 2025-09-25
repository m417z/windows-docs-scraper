# IImageList2::Replace2

## Description

Replaces an image in an image list.

## Parameters

### `i` [in]

Type: **int**

The index of the image to replace.

### `hbmImage` [in]

Type: **[HBITMAP](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the bitmap that contains the image.

### `hbmMask` [in, optional]

Type: **[HBITMAP](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the bitmap that contains the mask. If no mask is used with the image list, this parameter is ignored.

### `punk` [in, optional]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface.

### `dwFlags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies how the mask is applied to the image as one or a bitwise combination of the following decoration flags.

| Value | Meaning |
| --- | --- |
| **ILR_DEFAULT**<br><br>0x0000 | Not used. |
| **ILR_HORIZONTAL_LEFT**<br><br>0x0000 | Horizontally align to left. |
| **ILR_HORIZONTAL_CENTER**<br><br>0x0001 | Horizontally center. |
| **ILR_HORIZONTAL_RIGHT**<br><br>0x0002 | Horizontally align to right. |
| **ILR_VERTICAL_TOP**<br><br>0x0000 | Vertically align to top. |
| **ILR_VERTICAL_CENTER**<br><br>0x0010 | Vertically align to center. |
| **ILR_VERTICAL_BOTTOM**<br><br>0x0020 | Vertically align to bottom. |
| **ILR_SCALE_CLIP**<br><br>0x0000 | Do nothing. |
| **ILR_SCALE_ASPECTRATIO**<br><br>0x0100 | Scale. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.