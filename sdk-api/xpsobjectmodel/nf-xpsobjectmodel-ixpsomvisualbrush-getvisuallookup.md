# IXpsOMVisualBrush::GetVisualLookup

## Description

Gets the lookup key name of a visual in a resource dictionary; the visual is to be used as the source for the brush.

## Parameters

### `lookup` [out, retval]

The key name of a visual in a resource dictionary; the visual is to be used as the source for the brush. If a visual's lookup key has not been set, or if a local visual has been set, a **NULL** pointer is returned.

| Most recent method called | Object that is returned in *lookup* |
| --- | --- |
| [SetVisualLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisualbrush-setvisuallocal) | **NULL** pointer. |
| [SetVisualLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisualbrush-setvisuallookup) | The lookup key that is set by [SetVisualLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisualbrush-setvisuallookup). |
| Neither [SetVisualLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisualbrush-setvisuallocal) nor [SetVisualLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisualbrush-setvisuallookup) has been called yet. | **NULL** pointer. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *lookup* is **NULL**. |

## Remarks

This method allocates the memory used by the string that is returned in *lookup*. If *lookup* is not **NULL**, use the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free the memory.

## See also

[IXpsOMVisualBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisualbrush)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)