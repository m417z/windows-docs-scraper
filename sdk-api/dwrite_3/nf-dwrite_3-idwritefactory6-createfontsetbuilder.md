## Description

Creates an empty font set builder, ready to add font instances to, and create a custom font set.

## Parameters

### `fontSetBuilder`

Type: **[IDWriteFontSetBuilder2](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontsetbuilder2)\*\***

The address of a pointer to an [IDWriteFontSetBuilder2](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontsetbuilder2) interface. On successful completion, the function sets the pointer to a newly created font set builder object, otherwise it sets the pointer to `nullptr`.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

## Remarks

## See also