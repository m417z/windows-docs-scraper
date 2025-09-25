# ImageList_WriteEx function

## Description

Writes an image list to a stream.

## Parameters

### `himl` [in]

Type: **HIMAGELIST**

A handle to the image list.

### `dwFlags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A flag that specifies how the stream is written.

| Value | Meaning |
| --- | --- |
| **ILP_NORMAL** | Writes to the stream using the file format for [Common Controls 6.0](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions), which includes information about image list attributes new to this version. |
| **ILP_DOWNLEVEL** | Writes to the stream using a file format previous to version 6.0. Specify this flag if you need to save image lists loaded under Common Controls versions earlier than version 6.0. |

### `pstm` [in]

Type: **LPSTREAM**

The address of the stream.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You should not create an image list that is written with the ILP_DOWNLEVEL flag with [ILC_COLOR32](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_create).

To use **ImageList_WriteEx**, the application must specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).

## See also

[ImageList_Read](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_read)

[ImageList_ReadEx](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_readex)

[ImageList_Write](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_write)

**Reference**