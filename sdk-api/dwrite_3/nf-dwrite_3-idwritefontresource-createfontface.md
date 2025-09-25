## Description

Creates a font face instance with specific axis values.

## Parameters

### `fontSimulations`

Type: **[DWRITE_FONT_SIMULATIONS](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_simulations)**

Font face simulation flags for algorithmic emboldening and italicization.

### `fontAxisValues`

Type: **[DWRITE_FONT_AXIS_VALUE](https://learn.microsoft.com/windows/win32/api/dwrite_3/ns-dwrite_3-dwrite_font_axis_value) const \***

A pointer to an array containing a list of font axis values. The array should be the size (the number of elements) indicated by the *fontAxisValueCount* argument.

### `fontAxisValueCount`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of font axis values contained in the *fontAxisValues* array.

### `fontFace` [out]

Type: **[IDWriteFontFace5](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontface5)\*\***

The address of a pointer to an [IDWriteFontFace5](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontface5) interface. On successful completion, the function sets the pointer to a newly created font face object, otherwise it sets the pointer to `nullptr`.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

|Return value|Description|
|-|-|
|DWRITE_E_REMOTEFONT|The font is not local.|

## Remarks

The axis values that you provide are permitted to be a subset or superset of all the ones actually supported by the font. Any unspecified axes use their default values: values beyond the ranges are clamped, and any non-varying axes have no effect.

## See also