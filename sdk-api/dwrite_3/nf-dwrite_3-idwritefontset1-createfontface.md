## Description

Creates a font face for a single item (rather than going through the font face reference).

## Parameters

### `listIndex`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Zero-based index of the font item in the set.

### `fontFace` [out]

Type: **[IDWriteFontFace5](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontface5)\*\***

The address of a pointer to an [IDWriteFontFace5](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontface5) interface. On successful completion, the function sets the pointer to a newly created font face object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

|Return value|Description|
|-|-|
|DWRITE_E_REMOTEFONT|The font is not local.|

## Remarks

## See also