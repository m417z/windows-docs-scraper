# IXpsOMGlyphsEditor::GetProhibitedCaretStops

## Description

Gets an array of prohibited caret stop locations.

## Parameters

### `count` [in, out]

The number of prohibited caret stop values that will fit in the array that is referenced by the *prohibitedCaretStops* parameter. When the method returns, *prohibitedCaretStopCount* will contain the number of values in that array.

### `prohibitedCaretStops` [out]

An array of glyph mapping values. If no prohibited caret stops have been defined, a **NULL** pointer is returned.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *prohibitedCaretStopCount*, *prohibitedCaretStops*, or both were **NULL**. |
| **ERROR_MORE_DATA** | *prohibitedCaretStops* was not large enough to receive the prohibited caret stop data. *prohibitedCaretStopCount* contains the required number of elements. |

## Remarks

Each caret stop index corresponds to the scalar values of a UTF-16 **UnicodeString** property. Index 0 represents the location just before the first UTF-16 scalar value of **UnicodeString**; index 1 represents the location between the first and second UTF-16 scalar values, and so on. There is an additional index at the end of **UnicodeString**. Any unspecified index is a valid caret stop location.

[GetProhibitedCaretStopCount](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomglyphseditor-getprohibitedcaretstopcount) gets the number of prohibited caret stops.

A caret stop is the index of the UTF-16 code point in the **UnicodeString** property of the glyph.

## See also

[IXpsOMGlyphsEditor](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphseditor)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))