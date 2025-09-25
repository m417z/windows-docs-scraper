# IXpsOMPackageWriter::StartNewDocument

## Description

Opens and initializes a new FixedDocument in the FixedDocumentSequence of the package.

## Parameters

### `documentPartName` [in]

A pointer to an [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface that contains the part name of the new document.

### `documentPrintTicket` [in]

A pointer to an [IXpsOMPrintTicketResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomprintticketresource) interface that contains the document-level print ticket. If there is no document-level print ticket for this package, this parameter can be set to **NULL**. See also Remarks.

### `documentStructure` [in]

A pointer to an [IXpsOMDocumentStructureResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdocumentstructureresource) interface that contains the initial document structure resource, if the resource is available; if it is not available, this parameter can be set to **NULL**.

### `signatureBlockResources` [in]

A pointer to an [IXpsOMSignatureBlockResourceCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomsignatureblockresourcecollection) interface that contains a collection of digital signatures to be attached to the document. If there are no digital signatures to be attached, this parameter can be set to **NULL**.

### `restrictedFonts` [in]

A pointer to an [IXpsOMPartUriCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomparturicollection) interface that contains the fonts that must have restricted font relationships written for them. The font data are not written until [AddResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompackagewriter-addresource) or [Close](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompackagewriter-close) is called.

If the document does not contain any restricted fonts, this parameter can be set to **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_UNAVAILABLE_PACKAGE** | A severe error occurred and the contents of the XPS OM might be unrecoverable. Some components of the XPS OM might still be usable but only after they have been verified. Because the state of the XPS OM cannot be predicted after this error is returned, all components of the XPS OM should be released and discarded. |
| **XPS_E_UNEXPECTED_RESTRICTED_FONT_RELATIONSHIP** | The restricted font collection passed in *restrictedFonts* contains an unrestricted font. |

This method calls the [Packaging](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging) API. For information about the Packaging API return values, see [Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors).

## Remarks

This method must be called before [AddPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompackagewriter-addpage) can be called to write the contents of an [IXpsOMPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage) interface.

Immediately after the [IXpsOMPackageWriter](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackagewriter) interface has been instantiated, the package contains only an empty Fixed Document Sequence part. The first time this method is called, a FixedDocument part is added to the Fixed Document Sequence part and the [AddPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompackagewriter-addpage) method will add pages to that FixedDocument part. Each time this method is called after the first time, the current FixedDocument part is closed, and a new FixedDocument part is opened and added to the Fixed Document Sequence part. All subsequent calls to the **AddPage** method add pages to the most recently opened FixedDocument part. This interface does not support adding pages to closed FixedDocument parts.

If *documentPrintTicket* contains a **NULL** pointer and the package writer was created with interleaving set to **XPS_INTERLEAVING_ON**, this method creates a blank document-level print ticket, if one does not already exist. Each time this method is called with a **NULL** pointer in *documentPrintTicket*, it adds a relationship from the new document to the blank print ticket. This is done to provide more efficient streaming consumption of the package.

If *documentPrintTicket* contains a **NULL** pointer and the package writer was created with interleaving set to **XPS_INTERLEAVING_OFF**, no blank print ticket is created.

**Note** Creating a new document in the package does not automatically create a thumbnail for the XPS document. To create a thumbnail of the XPS document, use the [IXpsOMThumbnailGenerator](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomthumbnailgenerator) interface.

## See also

[IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi)

[IXpsOMDocumentStructureResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdocumentstructureresource)

[IXpsOMPackageWriter](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackagewriter)

[IXpsOMPackageWriter3D](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel_2/nn-xpsobjectmodel_2-ixpsompackagewriter3d)

[IXpsOMPrintTicketResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomprintticketresource)

[IXpsOMSignatureBlockResourceCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomsignatureblockresourcecollection)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[Using the IXpsOMPackageWriter Interface](https://learn.microsoft.com/previous-versions/windows/desktop/dd464658(v=vs.85))

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))