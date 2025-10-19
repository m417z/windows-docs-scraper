# IXpsOMVisual::SetIsHyperlinkTarget

## Description

Specifies whether the visual is the target of a hyperlink.

## Parameters

### `isHyperlink` [in]

The Boolean value that specifies whether the visual is the target of a hyperlink.

| Value | Meaning |
| --- | --- |
| **TRUE** | The visual is the target of a hyperlink. |
| **FALSE** | The visual is not the target of a hyperlink. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_MISSING_NAME** | The page has not been named. The hyperlink target status can only be set if the page has a name. |

## Remarks

The visual must be named before it can be set as the target of a hyperlink.

## See also

[IXpsOMVisual](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisual)

[SetName](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setname)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))