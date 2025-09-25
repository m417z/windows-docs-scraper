# IXpsOMVisual::SetName

## Description

Sets the **Name** property of the visual.

## Parameters

### `name` [in]

The name of the visual. A **NULL** pointer clears the **Name** property.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_INVALID_NAME** | According to the [XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification), the string that is passed in *name* is not a valid name. |

## Remarks

Names must be unique.

Clearing the **Name** property by passing a **NULL** pointer in *name* sets the **IsHyperlinkTarget** property to **FALSE**.

## See also

[IXpsOMVisual](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisual)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))