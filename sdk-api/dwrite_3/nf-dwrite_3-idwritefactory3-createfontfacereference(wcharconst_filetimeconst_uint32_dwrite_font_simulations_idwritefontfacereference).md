## Description

Creates a reference to a font given a full path.

## Parameters

### `filePath`

Type: [in] **WCHAR**

Absolute file path. Subsequent operations on the constructed object may fail if the user provided filePath doesn't correspond to a valid file on the disk.

### `lastWriteTime`

Type: [in, optional] **FILETIME**

Last modified time of the input file path. If the parameter is omitted,
the function will access the font file to obtain its last write time, so the clients are encouraged to specify this value
to avoid extra disk access. Subsequent operations on the constructed object may fail
if the user provided lastWriteTime doesn't match the file on the disk.

### `faceIndex`

Type: **UINT32**

The zero based index of a font face in cases when the font files contain a collection of font faces.
If the font files contain a single face, this value should be zero.

### `fontSimulations`

Type: **[DWRITE_FONT_SIMULATIONS](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_simulations)**

Font face simulation flags for algorithmic emboldening and italicization.

### `fontFaceReference`

Type: [out] **[IDWriteFontFaceReference](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontfacereference)****

Contains newly created font face reference object, or nullptr in case of failure.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFactory3](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefactory3)