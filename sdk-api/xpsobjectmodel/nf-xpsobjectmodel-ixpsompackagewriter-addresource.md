# IXpsOMPackageWriter::AddResource

## Description

Creates a new part resource in the package.

## Parameters

### `resource` [in]

The [IXpsOMResource](https://learn.microsoft.com/previous-versions/windows/desktop/dd372762(v=vs.85)) interface of the part resource that will be added as a new part in the package. See Remarks for the types of resources that may be passed in this parameter.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | A resource with the same name as the resource that is referenced by *resource* has already been added to the stream or there is no relationship that includes the resource that is referenced by *resource*.<br><br>After **E_INVALIDARG** is returned, the stream or file is no longer valid and [Close](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompackagewriter-close) will return **XPS_E_UNAVAILABLE_PACKAGE**. |
| **XPS_E_UNAVAILABLE_PACKAGE** | A severe error occurred and the contents of the XPS OM might be unrecoverable. Some components of the XPS OM might still be usable but only after they have been verified. Because the state of the XPS OM cannot be predicted after this error is returned, all components of the XPS OM should be released and discarded. |

This method calls the [Packaging](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging) API. For information about the Packaging API return values, see [Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors).

## Remarks

This method creates a new part in the document package that corresponds to *resource*, adds the contents of *resource* to the new part, and then closes the new part.

If this method returns an error, the package writer is no longer usable.

The *resource* parameter must be one of the following:

* The [IXpsOMFontResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomfontresource) interface of a font resource that is used in the current page or a page that has already been added.
* The [IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource) interface of an image resource that is used in the current page or a page that has already been added.
* The [IXpsOMColorProfileResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcolorprofileresource) interface of color profile resource that is used in the current page or a page that has already been added.
* The [IXpsOMStoryFragmentsResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomstoryfragmentsresource) interface of a story fragments resource that is used in the current page or a page that has already been added.
* The [IXpsOMDocumentStructureResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdocumentstructureresource) interface of a document structure resource that is used in the current document or a document that has already been added.
* The [IXpsOMSignatureBlockResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomsignatureblockresource) interface of a signature block resource that is used in the current document or a document that has already been added.

This method returns an error if *resource* contains one of the following:

* The [IXpsOMRemoteDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomremotedictionaryresource) interface of a remote resource dictionary.
* The [IXpsOMPrintTicketResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomprintticketresource) interface of a print ticket.
* The [IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource) interface of a thumbnail image.

This method returns an error when *resource* references a resource that has the same name as a resource that has already been added to the stream or for which there is no existing relationship.

## See also

[IXpsOMPackageWriter](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackagewriter)

[IXpsOMPackageWriter3D](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel_2/nn-xpsobjectmodel_2-ixpsompackagewriter3d)

[IXpsOMResource](https://learn.microsoft.com/previous-versions/windows/desktop/dd372762(v=vs.85))

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[Using the IXpsOMPackageWriter Interface](https://learn.microsoft.com/previous-versions/windows/desktop/dd464658(v=vs.85))

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))