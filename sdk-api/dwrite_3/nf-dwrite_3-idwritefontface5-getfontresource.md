## Description

Retrieves the underlying font resource for this font face. You can use that to query information about the resource, or to recreate a new font face instance with different axis values.

## Parameters

### `fontResource` [out]

Type: **[IDWriteFontResource](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontresource)\*\***

The address of a pointer to an [IDWriteFontResource](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontresource) interface. On successful completion, the function sets the pointer to a newly created font resource object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

## Remarks

## See also