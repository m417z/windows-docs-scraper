# IDWriteFactory::CreateCustomFontFileReference

## Description

 Creates a reference to an application-specific font file resource.

## Parameters

### `fontFileReferenceKey` [in]

Type: **const void***

A font file reference key that uniquely identifies the font file resource
during the lifetime of *fontFileLoader*.

### `fontFileReferenceKeySize`

Type: **UINT32**

The size of the font file reference key in bytes.

### `fontFileLoader`

Type: **[IDWriteFontFileLoader](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfileloader)***

The font file loader that will be used by the font system to load data from the file identified by
*fontFileReferenceKey*.

### `fontFile` [out]

Type: **[IDWriteFontFile](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfile)****

Contains an address of a pointer to the newly created font file object when this method succeeds, or **NULL** in case of failure.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 This function is provided for cases when an application or a document needs to use a private font
without having to install it on the system. *fontFileReferenceKey* has to be unique only in the scope
of the *fontFileLoader* used in this call.

## See also

[IDWriteFactory](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefactory)