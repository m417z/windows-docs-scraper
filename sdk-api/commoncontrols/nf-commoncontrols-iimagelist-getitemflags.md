# IImageList::GetItemFlags

## Description

Gets the flags of an image.

## Parameters

### `i` [in]

Type: **int**

A value of type **int** that contains the index of the images whose flags need to be retrieved.

### `dwFlags` [out]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to a **DWORD** that contains the flags when the method returns. One of the following values:

| Value | Meaning |
| --- | --- |
| **ILIF_ALPHA**<br><br>0x00000001 | Indicates that the item in the imagelist has an alpha channel. |
| **ILIF_LOWQUALITY**<br><br>0x00000002 | **Windows Vista and later.** Indicates that the item in the imagelist was generated via a StretchBlt function, consequently image quality may have degraded. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use **IImageList::GetItemFlags**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).