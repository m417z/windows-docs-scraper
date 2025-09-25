# IXpsOMGlyphs::GetDeviceFontName

## Description

Gets the name of the device font.

## Parameters

### `deviceFontName` [out, retval]

The string that contains the unescaped name of the device font. If the name has not been set, a **NULL** pointer will be returned.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *deviceFontName* is **NULL**. |

## Remarks

The device font name uniquely identifies a specific device font and is typically defined by a hardware vendor or font vendor.

The escaped version of the device font name is created when the object is serialized.

This method allocates the memory used by the string that is returned in *deviceFontName*. If *deviceFontName* is not **NULL**, use the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free the memory.

## See also

[IXpsOMGlyphs](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphs)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))