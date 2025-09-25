# IXpsSignatureBlock::CreateRequest

## Description

Creates a new [IXpsSignatureRequest](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturerequest) interface and adds it to the signature block.

## Parameters

### `requestId` [in]

A string that uniquely identifies the new signature request within the signature block. For the method to generate an ID string, set this parameter to **NULL**.

### `signatureRequest` [out, retval]

A pointer to the new [IXpsSignatureRequest](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturerequest) interface. If access to the new request interface is not required, this parameter can be set to **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For return values that are not listed in this table, see [XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85)) and [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_UNEXPECTED** | Either the interface is not connected to the signature manager, or *requestId* is **NULL** and a unique ID string could not be generated. |

## Remarks

The new signature request must have a unique request ID; no two requests may have the same ID string.

Creating a new request marks the signature block as *dirty* and generates new content for the SignatureDefinitions part. When the XPS package is serialized, the new content will overwrite the previous content in the SignatureDefinitions part.

## See also

[IXpsSignatureBlock](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignatureblock)

[IXpsSignatureManager](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturemanager)

[IXpsSignatureRequest](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturerequest)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85))

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))