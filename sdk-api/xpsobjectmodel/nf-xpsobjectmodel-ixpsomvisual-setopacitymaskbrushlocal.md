# IXpsOMVisual::SetOpacityMaskBrushLocal

## Description

Sets the [IXpsOMBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsombrush) interface pointer as the local, unshared opacity mask brush.

## Parameters

### `opacityMaskBrush` [in]

A pointer to the [IXpsOMBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsombrush) interface to be set as the local, unshared opacity mask brush. A **NULL** pointer clears the previously assigned opacity mask brush.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_NO_CUSTOM_OBJECTS** | *opacityMaskBrush* does not point to a recognized interface implementation. Custom implementation of XPS Document API interfaces is not supported. |

## Remarks

After you call **SetOpacityMaskBrushLocal**, the opacity mask brush lookup key is released and [GetOpacityMaskBrushLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-getopacitymaskbrushlookup) returns a **NULL** pointer in the *key* parameter. The table that follows explains the relationship between the local and lookup values of this property.

| Most recent method called | Object that is returned in *opacityMaskBrush* by [GetOpacityMaskBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-getopacitymaskbrush) | Object that is returned in *opacityMaskBrush* by [GetOpacityMaskBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-getopacitymaskbrushlocal) | String that is returned in *key* by [GetOpacityMaskBrushLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-getopacitymaskbrushlookup) |
| --- | --- | --- | --- |
| **SetOpacityMaskBrushLocal** (this method) | The local opacity mask brush that is set by **SetOpacityMaskBrushLocal**. | The local opacity mask brush that is set by **SetOpacityMaskBrushLocal**. | **NULL** pointer. |
| [SetOpacityMaskBrushLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setopacitymaskbrushlookup) | The shared opacity mask brush that gets retrieved, with a lookup key that matches the key that is set by [SetOpacityMaskBrushLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setopacitymaskbrushlookup), from the resource directory. | **NULL** pointer. | The lookup key that is set by [SetOpacityMaskBrushLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setopacitymaskbrushlookup). |
| Neither **SetOpacityMaskBrushLocal** nor [SetOpacityMaskBrushLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setopacitymaskbrushlookup) has been called yet. | **NULL** pointer. | **NULL** pointer. | **NULL** pointer. |

## See also

[IXpsOMBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsombrush)

[IXpsOMVisual](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisual)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))