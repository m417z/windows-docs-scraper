# IDWriteFontFileEnumerator::MoveNext

## Description

 Advances to the next font file in the collection. When it is first created, the enumerator is positioned
before the first element of the collection and the first call to **MoveNext** advances to the first file.

## Parameters

### `hasCurrentFile` [out]

Type: **BOOL***

When the method returns, contains the value **TRUE** if the enumerator advances to a file; otherwise, **FALSE** if
the enumerator advances past the last file in the collection.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFontFileEnumerator](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfileenumerator)