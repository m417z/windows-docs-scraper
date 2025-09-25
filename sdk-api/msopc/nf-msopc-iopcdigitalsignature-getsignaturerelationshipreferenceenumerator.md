# IOpcDigitalSignature::GetSignatureRelationshipReferenceEnumerator

## Description

Gets an enumerator of [IOpcSignatureRelationshipReference](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturerelationshipreference) interface pointers, which represent references to relationships that have been signed.

## Parameters

### `relationshipReferenceEnumerator` [out, retval]

A pointer to an enumerator of [IOpcSignatureRelationshipReference](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturerelationshipreference) interface pointers, which represent references to relationships that have been signed.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *relationshipReferenceEnumerator* parameter is **NULL**. |

## See also

[Core Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/core-packaging-interfaces)

[Digital Signatures Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/digital-signatures-overview)

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcDigitalSignature](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcdigitalsignature)

[IOpcSignatureRelationshipReferenceEnumerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturerelationshipreferenceenumerator)

[IOpcSignatureRelationshipReferenceSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturerelationshipreferenceset)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Digital Signature Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-digital-signature-interfaces)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**