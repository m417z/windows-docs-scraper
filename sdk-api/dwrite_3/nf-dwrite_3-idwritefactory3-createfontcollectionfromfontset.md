# IDWriteFactory3::CreateFontCollectionFromFontSet

## Description

Create a weight/width/slope tree from a set of fonts.

## Parameters

### `fontSet`

Type: **[IDWriteFontSet](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontset)***

A set of fonts to use to build the collection.

### `fontCollection` [out]

Type: **[IDWriteFontCollection1](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontcollection1)****

Holds the newly created font collection object, or NULL in case of failure.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFactory3](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefactory3)