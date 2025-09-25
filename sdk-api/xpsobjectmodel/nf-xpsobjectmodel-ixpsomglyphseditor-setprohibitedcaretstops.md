# IXpsOMGlyphsEditor::SetProhibitedCaretStops

## Description

Sets an array of prohibited caret stop locations.

## Parameters

### `count` [in]

The number of prohibited caret stop locations in the array that is referenced by *prohibitedCaretStops*. A value of 0 clears the property.

### `prohibitedCaretStops` [in]

The array of prohibited caret stop locations to be set. If *count* is 0, this parameter is ignored and can be set to **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *prohibitedCaretStops* is **NULL** and *count* is greater than 0. |
| **XPS_E_CARET_OUTOFORDER** | A caret location value is out of order. The location values must be sorted in ascending order. |

## Remarks

Each caret stop index corresponds to the scalar values of a UTF-16 **UnicodeString** property. Index 0 represents the location just before the first UTF-16 scalar value of **UnicodeString**; index 1 represents the location between the first and second UTF-16 scalar values, and so on. There is an additional index at the end of **UnicodeString**. Any unspecified index is a valid caret stop location.

## See also

[IXpsOMGlyphsEditor](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphseditor)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))