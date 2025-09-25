# IDWriteRemoteFontFileLoader::CreateRemoteStreamFromKey

## Description

Creates a remote font file stream object that encapsulates an open file resource and can be used to download remote file data.

## Parameters

### `fontFileReferenceKey` [in]

Type: **void**

Font file reference key that uniquely identifies the font file resource within the scope of the font loader being used.

### `fontFileReferenceKeySize`

Type: **UINT32**

Size of font file reference key in bytes.

### `fontFileStream` [out]

Type: **[IDWriteRemoteFontFileStream](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwriteremotefontfilestream)****

Pointer to the newly created font file stream.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## Remarks

Unlike [CreateStreamFromKey](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefontfileloader-createstreamfromkey), this method can be used to create a stream for a remote file.
If the file is remote, the client must call [IDWriteRemoteFontFileStream::BeginDownload](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwriteremotefontfilestream-begindownload) with an empty array
of file fragments before the stream can be used to get the file size or access data.

## See also

[IDWriteRemoteFontFileLoader](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwriteremotefontfileloader)