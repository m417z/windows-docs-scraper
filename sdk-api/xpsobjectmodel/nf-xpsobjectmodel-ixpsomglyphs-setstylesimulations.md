# IXpsOMGlyphs::SetStyleSimulations

## Description

Sets the style simulations that will be applied when the glyphs are rendered.

## Parameters

### `styleSimulations` [in]

The [XPS_STYLE_SIMULATION](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_style_simulation) value that specifies the style simulation to be applied.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *styleSimulations* is not a valid [XPS_STYLE_SIMULATION](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_style_simulation) value. |

## See also

[IXpsOMGlyphs](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphs)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_STYLE_SIMULATION](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_style_simulation)