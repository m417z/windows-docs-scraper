# IXpsOMBrush::SetOpacity

## Description

Sets the opacity of the brush.

## Parameters

### `opacity` [in]

The opacity value of the brush.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *opacity* is not a valid value. See the Remarks section. |

## Remarks

*opacity* is expressed as a value between 0.0 and 1.0; 0.0 indicates that the brush is completely transparent, 0.5 that it is 50 percent opaque, and 1.0 that it is completely opaque.

If *opacity* is less than 0.0 or greater than 1.0, the method returns an error.

## See also

[IXpsOMBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsombrush)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))