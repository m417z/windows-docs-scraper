# IXpsOMVisual::SetOpacity

## Description

Sets the opacity value of the visual.

## Parameters

### `opacity` [in]

The opacity value to be set for the visual.

The range of allowed values for this parameter is 0.0 to 1.0; with 0.0 the visual is completely transparent, and with 1.0 it is completely opaque.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *opacity* contains a value that is not allowed. |

## See also

[IXpsOMVisual](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisual)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))