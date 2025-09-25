# IDWriteFontFileStream::GetFileSize

## Description

 Obtains the total size of a file.

## Parameters

### `fileSize` [out]

Type: **UINT64***

When this method returns, contains the total size of the file.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 Implementing **GetFileSize**() for asynchronously loaded font files may require
downloading the complete file contents. Therefore, this method should be used only for operations that
either require a complete font file to be loaded (for example, copying a font file) or that need to make
decisions based on the value of the file size (for example, validation against a persisted file size).

## See also

[IDWriteFontFileStream](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfilestream)