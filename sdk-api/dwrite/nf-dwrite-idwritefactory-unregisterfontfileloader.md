# IDWriteFactory::UnregisterFontFileLoader

## Description

 Unregisters a font file loader that was previously registered with the DirectWrite font system using [RegisterFontFileLoader](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefactory-registerfontfileloader).

## Parameters

### `fontFileLoader`

Type: **[IDWriteFontFileLoader](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfileloader)***

Pointer to the file loader that was previously registered with the DirectWrite font system using [RegisterFontFileLoader](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefactory-registerfontfileloader).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 This function unregisters font file loader callbacks with the DirectWrite font system.
You should implement the font file loader interface by a singleton object.
Note that font file loader implementations must not register themselves with DirectWrite
inside their constructors and must not unregister themselves in their destructors, because
registration and unregistration operations increment and decrement the object reference count respectively.
Instead, registration and unregistration of font file loaders with DirectWrite should be performed
outside of the font file loader implementation.

## See also

[IDWriteFactory](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefactory)