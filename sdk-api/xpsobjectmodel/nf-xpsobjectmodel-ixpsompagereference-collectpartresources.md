# IXpsOMPageReference::CollectPartResources

## Description

Creates a list of all part-based resources that are associated with the page.

## Parameters

### `partResources` [out, retval]

A pointer to the [IXpsOMPartResources](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompartresources) interface that contains the list of all part-based resources that are associated with the page.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *partResources* is **NULL**. |

This method calls the [Packaging](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging) API. For information about the Packaging API return values, see [Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors).

## Remarks

If the page is not loaded when this method is called, this method finds the part-based resources that are associated with this page by parsing the relationships part of the page and returns them in the *partResources* parameter. If the page is loaded, this method traverses the page's object model to find the part-based resources and returns them in *partResources*.

The list of resource parts that are returned in the [IXpsOMPartResources](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompartresources) interface is a snapshot of the document structure that is taken when the method is called. Changes made to the document after this call are not reflected in the **IXpsOMPartResources** interface after it is returned by this method. Likewise, changes made to the **IXpsOMPartResources** interface that is returned by this method will not be reflected in the document contents.

## See also

[IXpsOMPageReference](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompagereference)

[IXpsOMPartResources](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompartresources)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))