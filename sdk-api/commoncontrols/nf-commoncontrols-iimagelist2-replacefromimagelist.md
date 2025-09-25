# IImageList2::ReplaceFromImageList

## Description

Replaces an image in one image list with an image from another image list.

## Parameters

### `i` [in]

Type: **int**

The index of the destination image in the image list. This is the image that is overwritten by the new image.

### `pil` [in]

Type: **[IImageList](https://learn.microsoft.com/windows/desktop/api/commoncontrols/nn-commoncontrols-iimagelist)***

A pointer to the source image list.

### `iSrc` [in]

Type: **int**

The index of the source image in the image list pointed to by *pil*.

### `punk` [in, optional]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface.

### `dwFlags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Not used; must be 0.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.