# IDWriteFactory::CreateCustomFontCollection

## Description

 Creates a font collection using a custom font collection loader.

## Parameters

### `collectionLoader`

Type: **[IDWriteFontCollectionLoader](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontcollectionloader)***

An application-defined font collection loader, which must have been previously
registered using [RegisterFontCollectionLoader](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefactory-registerfontcollectionloader).

### `collectionKey` [in]

Type: **const void***

The key used by the loader to identify a collection of font files. The buffer allocated for this key should at least be the size of *collectionKeySize*.

### `collectionKeySize`

Type: **UINT32**

The size, in bytes, of the collection key.

### `fontCollection` [out]

Type: **[IDWriteFontCollection](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontcollection)****

Contains an address of a pointer to the system font collection object if the method succeeds, or **NULL** in case of failure.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFactory](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefactory)