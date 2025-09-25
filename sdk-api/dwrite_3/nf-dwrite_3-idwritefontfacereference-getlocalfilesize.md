# IDWriteFontFaceReference::GetLocalFileSize

## Description

Get the local size of the font face in bytes, which will always be
less than or equal to GetFullSize. If the locality is remote, this
value is zero. If full, this value will equal GetFileSize.

## Return value

Type: **UINT64**

the local size of the font face in bytes, which will always be
less than or equal to GetFullSize. If the locality is remote, this
value is zero. If full, this value will equal [GetFileSize](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritefontfacereference-getfilesize).

## See also

[IDWriteFontFaceReference](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontfacereference)