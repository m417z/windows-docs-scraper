# IDWriteFactory::CreateTextLayout

## Description

 Takes a string, text format, and associated constraints,
and produces an object that represents the fully analyzed
and formatted result.

## Parameters

### `string` [in]

Type: **const WCHAR***

An array of characters that contains the string to create a new [IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout) object from. This array must be of length *stringLength* and can contain embedded **NULL** characters.

### `stringLength`

Type: **UINT32**

The number of characters in the string.

### `textFormat`

Type: **[IDWriteTextFormat](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextformat)***

A pointer to an object that indicates the format to apply to the string.

### `maxWidth`

Type: **FLOAT**

The width of the layout box.

### `maxHeight`

Type: **FLOAT**

The height of the layout box.

### `textLayout` [out]

Type: **[IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout)****

When this method returns, contains an address of a pointer to the resultant text layout object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFactory](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefactory)