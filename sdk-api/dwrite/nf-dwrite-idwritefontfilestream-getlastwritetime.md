# IDWriteFontFileStream::GetLastWriteTime

## Description

 Obtains the last modified time of the file.

## Parameters

### `lastWriteTime` [out]

Type: **UINT64***

When this method returns, contains the last modified time of the file in the format that represents
the number of 100-nanosecond intervals since January 1, 1601 (UTC).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The "last modified time" is used by DirectWrite font selection algorithms
to determine whether one font resource is more up to date than another one.

## See also

[IDWriteFontFileStream](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfilestream)