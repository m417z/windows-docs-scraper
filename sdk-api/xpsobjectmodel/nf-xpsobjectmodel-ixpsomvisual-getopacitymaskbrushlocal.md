# IXpsOMVisual::GetOpacityMaskBrushLocal

## Description

Gets the local, unshared opacity mask brush for the visual.

## Parameters

### `opacityMaskBrush` [out, retval]

A pointer to the [IXpsOMBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsombrush) interface of the visual's opacity mask brush. If an opacity mask brush lookup key has been set, or if a local opacity mask brush has not been set, a **NULL** pointer is returned.

| Most recent method called | Object that is returned in *opacityMaskBrush* |
| --- | --- |
| [SetOpacityMaskBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setopacitymaskbrushlocal) | The local opacity mask brush that is set by [SetOpacityMaskBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setopacitymaskbrushlocal). |
| [SetOpacityMaskBrushLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setopacitymaskbrushlookup) | **NULL** pointer. |
| Neither [SetOpacityMaskBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setopacitymaskbrushlocal) nor [SetOpacityMaskBrushLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setopacitymaskbrushlookup) has been called yet. | **NULL** pointer. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *opacityMaskBrush* is **NULL**. |

## See also

[IXpsOMBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsombrush)

[IXpsOMVisual](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisual)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))