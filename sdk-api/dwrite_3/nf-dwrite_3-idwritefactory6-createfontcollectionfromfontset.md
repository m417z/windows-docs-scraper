## Description

From a font set, create a collection of fonts grouped into families.

## Parameters

### `fontSet`

Type: **[IDWriteFontSet](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontset)\***

A set of fonts to use to build the collection.

### `fontFamilyModel`

Type: **[DWRITE_FONT_FAMILY_MODEL](https://learn.microsoft.com/windows/win32/api/dwrite_3/ne-dwrite_3-dwrite_font_family_model)**

How to group families in the collection.

### `fontCollection` [out]

Type: **[IDWriteFontCollection2](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontcollection2)\*\***

The address of a pointer to an [IDWriteFontCollection2](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontcollection2) interface. On successful completion, the function sets the pointer to a newly created font collection object, otherwise it sets the pointer to `nullptr`.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

## Remarks

## See also