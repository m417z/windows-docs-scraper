# IXpsOMPath::GetFillBrushLookup

## Description

Gets the lookup key of the brush that is stored in a resource dictionary and used as the fill brush for the path.

## Parameters

### `lookup` [out, retval]

The lookup key for the fill brush that is stored in a resource dictionary. If the lookup key has not been set or if a local fill brush has been set, a **NULL** pointer is returned.

| Most recent method called | String that is returned in *lookup* |
| --- | --- |
| [SetFillBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompath-setfillbrushlocal) | **NULL** pointer. |
| [SetFillBrushLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompath-setfillbrushlookup) | The lookup key that is set by [SetFillBrushLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompath-setfillbrushlookup). |
| Neither [SetFillBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompath-setfillbrushlocal) nor [SetFillBrushLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompath-setfillbrushlookup) has been called yet. | **NULL** pointer. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *lookup* is **NULL**. |

## Remarks

This method allocates the memory used by the string that is returned in *lookup*. If *lookup* is not **NULL**, use the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free the memory.

## See also

[IXpsOMPath](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompath)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))