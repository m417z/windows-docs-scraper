# IImageList::Merge

## Description

Creates a new image by combining two existing images. This method also creates a new image list in which to store the image.

## Parameters

### `i1` [in]

Type: **int**

A value of type **int** that contains the index of the first existing image.

### `punk2` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the image list that contains the second image.

### `i2` [in]

Type: **int**

A value of type **int** that contains the index of the second existing image.

### `dx` [in]

Type: **int**

A value of type **int** that contains the x-component of the offset of the second image relative to the first image.

### `dy` [in]

Type: **int**

A value of type **int** that contains the y-component of the offset of the second image relative to the first image.

### `riid` [out]

Type: **REFIID**

An IID of the interface for the new image list.

### `ppv` [out]

Type: **[PVOID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A raw pointer to the interface for the new image list.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The new image consists of the second image drawn transparently over the first. The mask for the new image is obtained by combining the masks of the two existing images with the bitwise OR operator.

To use **IImageList::Merge**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).