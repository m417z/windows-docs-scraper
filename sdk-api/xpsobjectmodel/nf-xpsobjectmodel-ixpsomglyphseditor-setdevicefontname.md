# IXpsOMGlyphsEditor::SetDeviceFontName

## Description

Sets the name of the device font.

## Parameters

### `deviceFontName` [in]

A pointer to the string that contains the name of the device font in its unescaped form. A **NULL** pointer clears the property.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

The device font name that is passed in *deviceFontName* can be set in its unescaped form; it will be converted to its escaped form when the document is serialized.

## See also

[IXpsOMGlyphsEditor](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphseditor)