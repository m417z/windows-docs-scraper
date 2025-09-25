# IDWriteFontFileStream::ReadFileFragment

## Description

 Reads a fragment from a font file.

## Parameters

### `fragmentStart` [out]

Type: **const void****

When this method returns, contains an address of a pointer to the start of the font file fragment. This parameter is passed uninitialized.

### `fileOffset`

Type: **UINT64**

The offset of the fragment, in bytes, from the beginning of the font file.

### `fragmentSize`

Type: **UINT64**

The size of the file fragment, in bytes.

### `fragmentContext` [out]

Type: **void****

When this method returns, contains the address of a pointer to a pointer to the client-defined context to be passed to [ReleaseFileFragment](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefontfilestream-releasefilefragment).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 Note that **ReadFileFragment** implementations must check whether the requested font file fragment
is within the file bounds. Otherwise, an error should be returned from **ReadFileFragment**.

[DirectWrite](https://learn.microsoft.com/windows/win32/DirectWrite/direct-write-portal) may invoke [IDWriteFontFileStream](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfilestream) methods on the same object from multiple threads simultaneously. Therefore, **ReadFileFragment** implementations that rely on internal mutable state must serialize access to such state across multiple threads. For example, an implementation that uses separate Seek and Read operations to read a file fragment must place the code block containing Seek and Read calls under a lock or a critical section.

## See also

[IDWriteFontFileStream](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfilestream)