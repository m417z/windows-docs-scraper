## Description

Creates a font resource, given a font file and a face index.

## Parameters

### `fontFile`

Type: **[IDWriteFontFile](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfile)\***

A user-provided font file representing the font face.

### `faceIndex`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The zero-based index of a font face in cases when the font file contains a collection of font faces. If the font file contains a single face, then set this value to zero.

### `fontResource`

Type: **[IDWriteFontResource](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontresource)\*\***

The address of a pointer to an [IDWriteFontResource](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontresource) interface. On successful completion, the function sets the pointer to a newly created font resource object, otherwise it sets the pointer to `nullptr`.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

## Remarks

## See also