# DWRITE_FILE_FRAGMENT structure

## Description

Represents a range of bytes in a font file.

## Members

### `fileOffset`

Starting offset of the fragment from the beginning of the file.

### `fragmentSize`

Size of the file fragment, in bytes.

## Remarks

DWRITE_FILE_FRAGMENT is passed as input to [IDWriteRemoteFontFileStream::BeginDownload](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwriteremotefontfilestream-begindownload).