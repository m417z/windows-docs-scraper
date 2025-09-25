## Description

Creates the font resource of a single item.

## Parameters

### `listIndex`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Zero-based index of the font item in the set.

### `fontResource` [out]

Type: **[IDWriteFontResource](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontresource)\*\***

The address of a pointer to an [IDWriteFontResource](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontresource) interface. On successful completion, the function sets the pointer to a newly created font resource object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

|Return value|Description|
|-|-|
|DWRITE_E_REMOTEFONT|The file is not local.|

## Remarks

## See also