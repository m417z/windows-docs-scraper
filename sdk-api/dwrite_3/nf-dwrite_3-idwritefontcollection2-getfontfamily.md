## Description

Creates a font family object, given a zero-based font family index.

## Parameters

### `index`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Zero-based index of the font family.

### `fontFamily` [out]

Type: **[IDWriteFontFamily2](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontfamily2)\*\***

The address of a pointer to an [IDWriteFontFamily2](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontfamily2) interface. On successful completion, the function sets the pointer to a newly created font family object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

## Remarks

## See also