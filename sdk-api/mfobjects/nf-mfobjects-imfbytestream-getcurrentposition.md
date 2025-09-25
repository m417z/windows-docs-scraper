# IMFByteStream::GetCurrentPosition

## Description

Retrieves the current read or write position in the stream.

## Parameters

### `pqwPosition` [out]

Receives the current position, in bytes.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The methods that update the current position are [Read](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-read), [BeginRead](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-beginread), [Write](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-write), [BeginWrite](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-beginwrite), [SetCurrentPosition](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-setcurrentposition), and [Seek](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-seek).

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream)