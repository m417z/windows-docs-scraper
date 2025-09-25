# IDWriteFactory::RegisterFontCollectionLoader

## Description

Registers a custom font collection loader with the factory object.

## Parameters

### `fontCollectionLoader`

Type: **[IDWriteFontCollectionLoader](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontcollectionloader)***

Pointer to a [IDWriteFontCollectionLoader](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontcollectionloader) object to be registered.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function registers a font collection loader with DirectWrite. The font collection loader interface, which should be implemented by a singleton object,
handles enumerating font files in a font collection given a particular type of key. A given instance can only be registered once. Succeeding attempts will return an error,
indicating that it has already been registered. Note that font file loader implementations must not register themselves with DirectWrite inside their constructors,
and must not unregister themselves inside their destructors, because registration and unregistration operations increment and decrement the object reference count respectively.
Instead, registration and unregistration with DirectWrite of font file loaders should be performed outside of the font file loader implementation.