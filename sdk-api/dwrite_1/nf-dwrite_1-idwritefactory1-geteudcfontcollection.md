# IDWriteFactory1::GetEudcFontCollection

## Description

Gets a font collection representing the set of EUDC (end-user defined characters) fonts.

## Parameters

### `fontCollection` [out]

Type: **[IDWriteFontCollection](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontcollection)****

The font collection to fill.

### `checkForUpdates`

Type: **BOOL**

Whether to check for updates.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Note that if no EUDC is set on the system,
the returned collection will be empty, meaning it will return success
but GetFontFamilyCount will be zero.

## See also

[IDWriteFactory1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritefactory1)