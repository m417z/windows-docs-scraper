# IXpsOMBrush::GetOpacity

## Description

Gets the opacity of the brush.

## Parameters

### `opacity` [out, retval]

The opacity value of the brush.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *opacity* is **NULL**. |

## Remarks

*opacity* is expressed as a value between 0.0 and 1.0; 0.0 indicates that the brush is completely transparent, 0.5 that it is 50 percent opaque, and 1.0 that it is completely opaque.

## See also

[IXpsOMBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsombrush)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))