# IDWriteFactory::CreateFontFileReference

## Description

 Creates a font file reference object from a local font file.

## Parameters

### `filePath` [in]

Type: **const WCHAR***

An array of characters that contains the absolute file path for the font file. Subsequent operations on the constructed object may fail
if the user provided *filePath* doesn't correspond to a valid file on the disk.

### `lastWriteTime` [in, optional]

Type: **const FILETIME***

The last modified time of the input file path. If the parameter is omitted,
the function will access the font file to obtain its last write time. You should specify this value
to avoid extra disk access. Subsequent operations on the constructed object may fail
if the user provided *lastWriteTime* doesn't match the file on the disk.

### `fontFile` [out]

Type: **[IDWriteFontFile](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfile)****

When this method returns, contains an address of a pointer to the newly created font file reference object, or **NULL** in case of failure.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFactory](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefactory)