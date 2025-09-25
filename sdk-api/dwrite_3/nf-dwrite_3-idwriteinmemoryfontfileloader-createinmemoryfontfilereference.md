# IDWriteInMemoryFontFileLoader::CreateInMemoryFontFileReference

## Description

Creates a font file reference ([IDWriteFontFile](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfile) object) from an array of bytes. The font file reference is bound to the [IDWriteInMemoryFontFileLoader](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwriteinmemoryfontfileloader) instance with which it was
created and remains valid for as long as that loader is registered with the factory.

## Parameters

### `factory`

Type: **[IDWriteFactory](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefactory)***

Factory object used to create the font file reference.

### `fontData` [in]

Type: **void const***

Pointer to a memory block containing the font data.

### `fontDataSize`

Type: **UINT32**

Size of the font data.

### `ownerObject` [in, optional]

Type: **[IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown)***

Optional object that owns the memory specified by the fontData parameter. If this parameter is not NULL, the method stores a
pointer to the font data and adds a reference to the owner object. The fontData pointer must remain valid until the owner object is released. If
this parameter is NULL, the method makes a copy of the font data.

### `fontFile` [out]

Type: **[IDWriteFontFile](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfile)****

Receives a pointer to the newly-created font file reference.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[Creating a custom font set using font data loaded into memory](https://learn.microsoft.com/windows/win32/directwrite/custom-font-sets-win10#creating-a-custom-font-set-using-font-data-loaded-into-memory)

[IDWriteInMemoryFontFileLoader](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwriteinmemoryfontfileloader)