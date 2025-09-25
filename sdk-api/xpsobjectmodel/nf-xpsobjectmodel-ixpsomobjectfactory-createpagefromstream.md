# IXpsOMObjectFactory::CreatePageFromStream

## Description

Reads the page markup from the specified stream to create and populate an [IXpsOMPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage) interface.

## Parameters

### `pageMarkupStream` [in]

The stream that contains the page markup.

### `partUri` [in]

The [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface that contains the page's URI.

### `resources` [in]

The [IXpsOMPartResources](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompartresources) interface that contains the resources used by the page.

### `reuseObjects` [in]

A Boolean value that specifies whether the software is to attempt to optimize the page contents tree by sharing objects that are identical in all properties and children.

| Value | Meaning |
| --- | --- |
| ****TRUE**** | The software will attempt to optimize the object tree. |
| ****FALSE**** | The software will not attempt to optimize the object tree. |

### `page` [out, retval]

A pointer to the new [IXpsOMPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage) interface created by this method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *pageMarkupStream*, *partUri*, *resources*, or *page* is **NULL**. |
| **XPS_E_NO_CUSTOM_OBJECTS** | *resources* does not point to a recognized interface implementation. Custom implementation of XPS Document API interfaces is not supported. |

This method calls the [Packaging](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging) API. For information about the Packaging API return values, see [Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors).

## Remarks

This method does not validate the contents of any stream-based resources that it loads from the stream into the document objects. The application must verify these resources before it uses them.

## See also

[IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi)

[IXpsOMObjectFactory](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomobjectfactory)

[IXpsOMPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage)

[IXpsOMPartResources](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompartresources)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))