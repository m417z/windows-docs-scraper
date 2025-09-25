# IXpsOMPageReference::GetThumbnailResource

## Description

Gets a pointer to the [IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource) interface of the thumbnail image resource that is associated with the page.

## Parameters

### `imageResource` [out, retval]

A pointer to the [IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource) interface of the thumbnail image resource that is associated with the page. If no thumbnail image resource has been assigned to the page, a **NULL** pointer is returned.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *imageResource* is **NULL**. |

This method calls the [Packaging](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging) API. For information about the Packaging API return values, see [Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors).

## Remarks

The thumbnail image is a small, visual representation of the page's contents.

After loading and parsing the resource into the XPS OM, this method might return an error that applies to another resource. This occurs because all of the relationships are parsed when a resource is loaded.

## See also

[IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource)

[IXpsOMPageReference](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompagereference)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))