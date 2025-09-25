# IXpsOMGlyphs::GetProhibitedCaretStops

## Description

Gets an array of prohibited caret stop locations.

## Parameters

### `prohibitedCaretStopCount` [in, out]

The number of prohibited caret stop locations that will fit in the array referenced by *prohibitedCaretStops*. When the method returns, *prohibitedCaretStopCount* will contain the number of values returned in the array referenced by *prohibitedCaretStops*.

### `prohibitedCaretStops` [out]

An array of prohibited caret stop locations; if such are not defined, a **NULL** pointer is returned.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *prohibitedCaretStopCount*, *prohibitedCaretStops*, or both are **NULL**. |
| **ERROR_MORE_DATA** | *prohibitedCaretStops* is not large enough to receive the prohibited caret stop data. *prohibitedCaretStopCount* contains the required number of elements. |

## Remarks

Each caret stop index corresponds to the scalar values of a UTF-16 **UnicodeString** property. Index 0 represents the location just before the first UTF-16 scalar value of **UnicodeString**; index 1 represents the location between the first and second UTF-16 scalar values, and so on. There is an additional index at the end of **UnicodeString**. Any unspecified index is a valid caret stop location.

[GetProhibitedCaretStopCount](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomglyphs-getprohibitedcaretstopcount) gets the number of prohibited caret stops.

A caret stop is the index of the UTF-16 code point in the **UnicodeString** property of the glyph.

## See also

[GetProhibitedCaretStopCount](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomglyphs-getprohibitedcaretstopcount)

[IXpsOMGlyphs](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphs)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))