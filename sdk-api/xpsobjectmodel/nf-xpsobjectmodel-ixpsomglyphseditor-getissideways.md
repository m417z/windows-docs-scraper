# IXpsOMGlyphsEditor::GetIsSideways

## Description

Gets a Boolean value that indicates whether the text is to be rendered with the glyphs rotated sideways.

## Parameters

### `isSideways` [out, retval]

The Boolean value that indicates whether the text is to be rendered with the glyphs rotated sideways.

| Value | Meaning |
| --- | --- |
| ****TRUE**** | Rotate the glyphs sideways. Produces sideways text. |
| ****FALSE**** | Do not rotate the glyphs sideways. Produces normal text. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *isSideways* is **NULL**. |

## Remarks

The default value for this property is **false**.

## See also

[IXpsOMGlyphsEditor](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphseditor)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))