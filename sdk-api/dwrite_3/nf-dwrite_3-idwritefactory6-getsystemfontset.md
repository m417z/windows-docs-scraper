## Description

Retrieves the set of system fonts.

## Parameters

### `includeDownloadableFonts`

Type: **[BOOL](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

`true` if you want to include downloadable fonts. `false` if you only want locally installed fonts.

### `fontSet`

Type: **[IDWriteFontSet1](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontset1)\*\***

The address of a pointer to an [IDWriteFontSet1](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontset1) interface. On successful completion, the function sets the pointer to the font set object, otherwise it sets the pointer to `nullptr`.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

## Remarks

## See also