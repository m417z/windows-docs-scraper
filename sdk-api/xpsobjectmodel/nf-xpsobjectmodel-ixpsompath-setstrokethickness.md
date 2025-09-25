# IXpsOMPath::SetStrokeThickness

## Description

Sets the stroke thickness.

## Parameters

### `strokeThickness` [in]

The stroke thickness value to be set; must be 0.0 or greater.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | A value that was passed in *strokeThickness* was not valid. |

## Remarks

The value returned in *strokeThickness* specifies the thickness of a stroke in units of the effective coordinate space; the units include the path's render transform.

The stroke is drawn on top of the boundary of the path's geometry, such that one half of the stroke's width extends outside of the path's specified geometry and the other half falls inside of it.

## See also

[IXpsOMPath](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompath)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))