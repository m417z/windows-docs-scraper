# ImageList_ReadEx function

## Description

Reads an image list from a stream, and returns an [IImageList](https://learn.microsoft.com/windows/desktop/api/commoncontrols/nn-commoncontrols-iimagelist) interface to the image list.

## Parameters

### `dwFlags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A flag that specifies how the stream is read.

| Value | Meaning |
| --- | --- |
| **ILP_NORMAL** | Expects an image list that was written with the ILP_NORMAL flag specified. |
| **ILP_DOWNLEVEL** | Expects an image list that was written with the ILP_DOWNLEVEL flag specified. |

### `pstm` [in]

Type: **LPSTREAM**

The address of the stream.

### `riid` [out]

Type: **REFIID**

An IID for the image list.

### `ppv` [out]

Type: **void****

The address of a pointer to the interface for the image list if successful, **NULL** otherwise.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use **ImageList_ReadEx**, the application must specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).

## See also

[ImageList_Read](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_read)

[ImageList_Write](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_write)

[ImageList_WriteEx](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_writeex)

**Reference**