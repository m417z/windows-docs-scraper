# IXpsSignatureManager::AddSignatureBlock

## Description

Creates a new [IXpsSignatureBlock](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignatureblock) interface and adds it to the signature block collection.

## Parameters

### `partName` [in]

A pointer to the [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface that contains the URI of the new part. For the method to generate a part name, this parameter can be set to **NULL**.

### `fixedDocumentIndex` [in]

The index value of the FixedDocument part with which the new signature block is to be associated.

### `signatureBlock` [out, retval]

A pointer to the new [IXpsSignatureBlock](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignatureblock) interface. If access to the new interface is not required, this parameter can be set to **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For return values that are not listed in this table, see [XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85)) and [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *fixedDocumentIndex* references a fixed document that is not found in the XPS package. |
| **XPS_E_PACKAGE_NOT_OPENED** | An XPS package has not yet been opened in the signature manager. |

## Remarks

A signature block represents a SignatureDefinitions part in an XPS package. According to section 10.2.2 in the [XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification), zero or more SignatureDefinitions parts can be attached to each FixedDocument.
This method creates a new SignatureDefinitions part with the specified name, links it from the specified FixedDocument part by a relationship,
creates a new [IXpsSignatureBlock](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignatureblock) interface, and adds this new interface to the internal signature block collection.

To retrieve a signature block, call the [GetSignatureBlocks](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nf-xpsdigitalsignature-ixpssignaturemanager-getsignatureblocks) method.

## See also

[IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi)

[IXpsSignatureBlock](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignatureblock)

[IXpsSignatureManager](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturemanager)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85))

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))