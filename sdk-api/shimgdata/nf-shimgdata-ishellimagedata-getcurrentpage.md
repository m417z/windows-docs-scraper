# IShellImageData::GetCurrentPage

## Description

Gets the current page of a multipage image.

## Parameters

### `pnPage` [out]

Type: **ULONG***

A pointer to the page number.

## Return value

Type: **HRESULT**

Returns S_OK. If the image is not a multipage image, such as a .jpg file, the method returns S_OK with a page number of 0.