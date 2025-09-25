# IXpsOMGlyphsEditor::GetDeviceFontName

## Description

Gets the name of the device font.

## Parameters

### `deviceFontName` [out, retval]

The name of the device font; if not specified, a **NULL** pointer will be returned.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *deviceFontName* is **NULL**. |

## Remarks

The device font name is created as an escaped name when the object is serialized.

The device font name uniquely identifies a specific device font and is typically defined by a hardware or font vendor.

This method allocates the memory used by the string that is returned in *deviceFontName*. If *deviceFontName* is not **NULL**, use the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free the memory.

## See also

[IXpsOMGlyphsEditor](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphseditor)