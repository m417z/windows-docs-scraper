# IXpsOMGlyphsEditor::GetProhibitedCaretStopCount

## Description

Gets the number of prohibited caret stops.

## Parameters

### `prohibitedCaretStopCount` [out, retval]

The number of prohibited caret stops.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *prohibitedCaretStopCount* is **NULL**. |

## Remarks

To get the prohibited caret stops, call [GetProhibitedCaretStops](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomglyphseditor-getprohibitedcaretstops).

Each caret stop index corresponds to the scalar values of a UTF-16 **UnicodeString** property. Index 0 represents the location just before the first UTF-16 scalar value of **UnicodeString**; index 1 represents the location between the first and second UTF-16 scalar values, and so on. There is an additional index at the end of **UnicodeString**. Any unspecified index is a valid caret stop location.

## See also

[IXpsOMGlyphsEditor](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphseditor)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))