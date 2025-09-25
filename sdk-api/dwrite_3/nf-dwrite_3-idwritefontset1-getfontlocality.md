## Description

Retrieves the locality of a single item.

## Parameters

### `listIndex`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Zero-based index of the font item in the set.

## Return value

Type: **[DWRITE_LOCALITY](https://learn.microsoft.com/windows/win32/api/dwrite_3/ne-dwrite_3-dwrite_locality)**

A value indicating the locality.

## Remarks

The locality enumeration. For fully local files, the result will always be **DWRITE_LOCALITY_LOCAL**. For downloadable files, the result depends on how much of the file has been downloaded.

## See also