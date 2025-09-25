# IXpsOMVisualBrush::SetVisualLocal

## Description

Sets the interface pointer of the local, unshared visual used as the source for the brush.

## Parameters

### `visual` [in]

A pointer to the [IXpsOMVisual](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisual) interface to be set as the visual for the brush. If a local visual has been set, passing a **NULL** pointer will release it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_NO_CUSTOM_OBJECTS** | *visual* does not point to a recognized interface implementation. Custom implementation of XPS Document API interfaces is not supported. |

## Remarks

After you call **SetVisualLocal**, the visual lookup key is released and [GetVisualLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisualbrush-getvisuallookup) returns a **NULL** pointer in the *lookup* parameter. The table that follows explains the relationship between the local and lookup values of this property.

| Most recent method called | Object that is returned in *visual* by [GetVisual](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisualbrush-getvisual) | Object that is returned in *visual* by [GetVisualLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisualbrush-getvisuallocal) | String that is returned in *lookup* by [GetVisualLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisualbrush-getvisuallookup) |
| --- | --- | --- | --- |
| **SetVisualLocal** (this method). | The visual that is set by **SetVisualLocal**. | The visual that is set by **SetVisualLocal**. | **NULL** pointer. |
| [SetVisualLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisualbrush-setvisuallookup) | The visual that is retrieved, with a lookup key that matches the key that is set by [SetVisualLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisualbrush-setvisuallookup), from the resource directory. | **NULL** pointer. | The lookup key that is set by [SetVisualLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisualbrush-setvisuallookup). |
| Neither **SetVisualLocal** nor [SetVisualLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisualbrush-setvisuallookup) has been called yet. | **NULL** pointer. | **NULL** pointer. | **NULL** pointer. |

## See also

[IXpsOMVisual](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisual)

[IXpsOMVisualBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisualbrush)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))