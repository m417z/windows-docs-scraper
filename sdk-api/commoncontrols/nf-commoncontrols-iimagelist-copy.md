# IImageList::Copy

## Description

Copies images from a given image list.

## Parameters

### `iDst` [in]

Type: **int**

A value of type **int** that contains the zero-based index of the destination image for the copy operation.

### `punkSrc` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface for the source image list.

### `iSrc` [in]

Type: **int**

A value of type **int** that contains the zero-based index of the source image for the copy operation.

### `uFlags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value that specifies the type of copy operation to be made.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The *uFlags* parameter can have the following values.

| Value | Description |
| --- | --- |
| **ILCF_MOVE** | The source image is copied to the destination image's index. This operation results in multiple instances of a given image. |
| **ILCF_SWAP** | The source and destination images exchange positions within the image list. |

To use **IImageList::Copy**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).