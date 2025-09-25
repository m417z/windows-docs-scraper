# IDWriteFontCollectionLoader::CreateEnumeratorFromKey

## Description

 Creates a font file enumerator object that encapsulates a collection of font files.
The font system calls back to this interface to create a font collection.

## Parameters

### `factory`

Type: **[IDWriteFactory](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefactory)***

Pointer to the [IDWriteFactory](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefactory) object that was used to create the current font collection.

### `collectionKey` [in]

Type: **const void***

A font collection key that uniquely identifies the collection of font files within
the scope of the font collection loader being used. The buffer allocated for this key must be at least the size, in bytes, specified by *collectionKeySize*.

### `collectionKeySize`

Type: **UINT32**

The size of the font collection key, in bytes.

### `fontFileEnumerator` [out]

Type: **[IDWriteFontFileEnumerator](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfileenumerator)****

When this method returns, contains the address of a pointer to the newly created font file enumerator.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFontCollectionLoader](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontcollectionloader)