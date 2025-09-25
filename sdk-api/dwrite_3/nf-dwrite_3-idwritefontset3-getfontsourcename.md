## Description

Copies the font source name (for the specified font) into an output array.

## Parameters

### `listIndex`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Zero-based index of the font.

### `stringBuffer` [out]

Type: **[WCHAR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Character array that receives the string. Call [GetFontSourceNameLength](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritefontset3-getfontsourcenamelength) to determine the size of array to allocate.

### `stringBufferSize`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Size of the array in characters. The size must include space for the terminating null character.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

## Remarks

## See also

[GetFontSourceNameLength](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritefontset3-getfontsourcenamelength)