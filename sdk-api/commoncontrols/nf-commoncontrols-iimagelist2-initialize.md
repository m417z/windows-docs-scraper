# IImageList2::Initialize

## Description

Initializes an image list.

## Parameters

### `cx` [in]

Type: **int**

Width, in pixels, of each image.

### `cy` [in]

Type: **int**

Height, in pixels, of each image.

### `flags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A combination of [Image List Creation Flags](https://learn.microsoft.com/windows/desktop/Controls/ilc-constants).

### `cInitial` [in]

Type: **int**

Number of images that the image list initially contains.

### `cGrow` [in]

Type: **int**

Number of new images that the image list can contain.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.