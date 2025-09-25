# IXpsOMVisual::GetOpacityMaskBrushLookup

## Description

Gets the name of the lookup key of the shared opacity mask brush in a resource dictionary.

## Parameters

### `key` [out, retval]

The name of the lookup key of the shared opacity mask brush in a resource dictionary. If the lookup key of an opacity mask brush has not been set, or if a local opacity mask brush has been set, a **NULL** pointer is returned.

| Most recent method called | Object that is returned in *key* |
| --- | --- |
| [SetOpacityMaskBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setopacitymaskbrushlocal) | **NULL** pointer. |
| [SetOpacityMaskBrushLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setopacitymaskbrushlookup) | The lookup key that is set by [SetOpacityMaskBrushLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setopacitymaskbrushlookup). |
| Neither [SetOpacityMaskBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setopacitymaskbrushlocal) nor [SetOpacityMaskBrushLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setopacitymaskbrushlookup) has been called yet. | **NULL** pointer. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *key* is **NULL**. |

## Remarks

This method allocates the memory that is used by the string returned in *key*. If *key* is not **NULL**, use the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free the memory.

## See also

[IXpsOMBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsombrush)

[IXpsOMVisual](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisual)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))