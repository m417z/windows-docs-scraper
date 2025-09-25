# IDWriteFactory::UnregisterFontCollectionLoader

## Description

 Unregisters a custom font collection loader that was previously registered using [RegisterFontCollectionLoader](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefactory-registerfontcollectionloader).

## Parameters

### `fontCollectionLoader`

Type: **[IDWriteFontCollectionLoader](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontcollectionloader)***

Pointer to a [IDWriteFontCollectionLoader](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontcollectionloader) object to be unregistered.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFactory](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefactory)