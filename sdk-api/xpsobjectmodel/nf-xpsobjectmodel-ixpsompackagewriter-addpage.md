# IXpsOMPackageWriter::AddPage

## Description

Writes a new FixedPage part to the currently open FixedDocument part in the package.

## Parameters

### `page` [in]

The [IXpsOMPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage) interface whose page content is to be written to the currently open FixedDocument of the package.

### `advisoryPageDimensions` [in]

The [XPS_SIZE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_size) structure that contains page dimensions.

Size is described in XPS units. There are 96 XPS units per inch. For example, the dimensions of an 8.5" by 11.0" page are 816 by 1,056 XPS units.

### `discardableResourceParts` [in]

The [IXpsOMPartUriCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomparturicollection) interface that contains a collection of the discardable resource parts.

### `storyFragments` [in]

The [IXpsOMStoryFragmentsResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomstoryfragmentsresource) interface that is to be used for this page.

### `pagePrintTicket` [in]

The [IXpsOMPrintTicketResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomprintticketresource) interface that contains the page-level print ticket for this page. See also Remarks.

### `pageThumbnail` [in]

The [IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource) interface that contains the thumbnail image of this page.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_MISSING_DISCARDCONTROL** | A page refers to discardable resources but does not specify a DiscardControl part name. |
| **XPS_E_MISSING_DOCUMENT** | This method was called before [StartNewDocument](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompackagewriter-startnewdocument). |
| **XPS_E_UNAVAILABLE_PACKAGE** | A severe error occurred and the contents of the XPS OM might be unrecoverable. Some components of the XPS OM might still be usable but only after they have been verified. Because the state of the XPS OM cannot be predicted after this error is returned, all components of the XPS OM should be released and discarded. |

This method calls the [Packaging](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging) API. For information about the Packaging API return values, see [Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors).

## Remarks

Call this method after calling [StartNewDocument](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompackagewriter-startnewdocument).

This method creates a new FixedPage part in the package, copies the contents of the [IXpsOMPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage) interface that is passed in the *page* parameter, and then closes the new FixedPage part after the page has been written to the package.

If *pagePrintTicket* contains a **NULL** pointer and the package writer was created with interleaving set to **XPS_INTERLEAVING_ON**, this method creates a blank page-level print ticket, if one does not already exist. Each time method is called with a **NULL** pointer in *pagePrintTicket*, it adds a relationship from the new page to the blank print ticket. This is done to provide more efficient streaming consumption of the package.

If *pagePrintTicket* contains a **NULL** pointer and the package writer was created with interleaving set to **XPS_INTERLEAVING_OFF**, no blank print ticket is created.

## See also

[IXpsOMDocumentStructureResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdocumentstructureresource)

[IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource)

[IXpsOMPackageWriter](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackagewriter)

[IXpsOMPackageWriter3D](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel_2/nn-xpsobjectmodel_2-ixpsompackagewriter3d)

[IXpsOMPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage)

[IXpsOMPartUriCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomparturicollection)

[IXpsOMPrintTicketResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomprintticketresource)

[IXpsOMStoryFragmentsResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomstoryfragmentsresource)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[Using the IXpsOMPackageWriter Interface](https://learn.microsoft.com/previous-versions/windows/desktop/dd464658(v=vs.85))

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_SIZE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_size)