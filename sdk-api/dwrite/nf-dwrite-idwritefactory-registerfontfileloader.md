# IDWriteFactory::RegisterFontFileLoader

## Description

 Registers a font file loader with DirectWrite.

## Parameters

### `fontFileLoader`

Type: **[IDWriteFontFileLoader](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfileloader)***

Pointer to a [IDWriteFontFileLoader](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfileloader) object for a particular file resource type.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 This function registers a font file loader with DirectWrite.
The font file loader interface, which should be implemented by a singleton object, handles loading font file resources of a particular type from a key.
A given instance can only be registered once.
Succeeding attempts will return an error, indicating that it has already been registered.
Note that font file loader implementations must not register themselves with DirectWrite
inside their constructors, and must not unregister themselves inside their destructors, because
registration and unregistration operations increment and decrement the object reference count respectively.
Instead, registration and unregistration with DirectWrite of font file loaders should be performed
outside of the font file loader implementation.