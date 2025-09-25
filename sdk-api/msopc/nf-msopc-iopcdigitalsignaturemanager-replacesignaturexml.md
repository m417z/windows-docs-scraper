# IOpcDigitalSignatureManager::ReplaceSignatureXml

## Description

Replaces the existing signature markup that is stored in a specified signature part.

## Parameters

### `signaturePartName` [in]

An [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface pointer that represents the part name of the signature part that stores the existing signature markup.

### `newSignatureXml` [in]

A buffer that contains the signature markup that will replace the existing markup.

### `count` [in]

The size of the *newSignatureXml* buffer.

### `digitalSignature` [out, retval]

A pointer to a new [IOpcDigitalSignature](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcdigitalsignature) interface that represents the signature derived from the signature markup that is passed in *newSignatureXml*.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | At least one of the *signaturePartName*, *newSignatureXml*, and *digitalSignature* parameters is **NULL**. |
| **OPC_E_DS_DUPLICATE_PACKAGE_OBJECT_REFERENCES**<br><br>0x8051002D | The *newSignatureXml* buffer contains more than one **Reference** element that refers to the package **Object** element, but only one such **Reference** is allowed. |
| **OPC_E_DS_DUPLICATE_SIGNATURE_PROPERTY_ELEMENT**<br><br>0x80510028 | The *newSignatureXml* buffer contains more than one **SignatureProperty** element that has the same **Id** attribute. |
| **OPC_E_DS_EXTERNAL_SIGNATURE_REFERENCE**<br><br>0x8051002F | In the *newSignatureXml* buffer, a **Reference** element refers to an object that is external to the package. **Reference** elements must point to parts or **Object** elements that are internal. |
| **OPC_E_DS_INVALID_CANONICALIZATION_METHOD**<br><br>0x80510022 | An unsupported canonicalization method was requested or used in the *newSignatureXml* buffer. |
| **OPC_E_DS_INVALID_RELATIONSHIP_TRANSFORM_XML**<br><br>0x80510021 | In the *newSignatureXml* buffer, a **Transform** element that indicates the use of the relationships transform and the selection criteria for the transform does not conform to the schema specified in the *OPC*. |
| **OPC_E_DS_INVALID_SIGNATURE_COUNT**<br><br>0x8051002B | The *newSignatureXml* buffer does not contain the signature markup for exactly one signature. |
| **OPC_E_DS_INVALID_SIGNATURE_XML**<br><br>0x8051002A | The size of the *newSignatureXml* buffer is 0, but this buffer must have a size that is greater than 0. |
| **OPC_E_DS_MISSING_CANONICALIZATION_TRANSFORM**<br><br>0x80510032 | In the *newSignatureXml* buffer, a relationships transform is not followed by a canonicalization method; the relationships transform must be followed by a canonicalization method. |
| **OPC_E_DS_MISSING_PACKAGE_OBJECT_REFERENCE**<br><br>0x8051002E | In the *newSignatureXml* buffer, a **Reference** to the package-specific **Object** element was not found. |
| **OPC_E_DS_MISSING_SIGNATURE_ALGORITHM**<br><br>0x8051002C | The signature markup in the *newSignatureXml* buffer does not specify a signature method algorithm. |
| **OPC_E_DS_MISSING_SIGNATURE_PROPERTIES_ELEMENT**<br><br>0x80510026 | In the *newSignatureXml* buffer, the **SignatureProperties**  element was not found. |
| **OPC_E_DS_MISSING_SIGNATURE_PROPERTY_ELEMENT**<br><br>0x80510027 | In the *newSignatureXml* buffer, the **SignatureProperty** child element of the **SignatureProperties** element was not found. |
| **OPC_E_DS_MISSING_SIGNATURE_TIME_PROPERTY**<br><br>0x80510029 | In the *newSignatureXml* buffer, the **SignatureProperty** element with the **Id** attribute value of "idSignatureTime" does not exist or is not correctly constructed. |
| **OPC_E_DS_MULTIPLE_RELATIONSHIP_TRANSFORMS**<br><br>0x80510031 | In the *newSignatureXml* buffer, more than one relationships transform is specified for a **Reference** element, but only one relationships transform is allowed. |
| **OPC_E_DS_REFERENCE_MISSING_CONTENT_TYPE**<br><br>0x80510030 | The **URI** attribute value of a **Reference** element in the *newSignatureXml* buffer does not include the content type of the referenced part. |
| **OPC_E_DS_SIGNATURE_PROPERTY_MISSING_TARGET**<br><br>0x80510045 | In the *newSignatureXml* buffer, the **SignatureProperty** element is missing the required **Target** attribute. |
| **OPC_E_DS_SIGNATURE_REFERENCE_MISSING_URI**<br><br>0x80510043 | A **Reference** element, which is in the *newSignatureXml* buffer, requires the **URI** attribute, but the attribute is missing. |
| **OPC_E_DS_UNSIGNED_PACKAGE**<br><br>0x80510055 | The package is not signed; therefore, the signature markup cannot be replaced. |
| **OPC_E_NO_SUCH_PART**<br><br>0x80510018 | The specified part does not exist. |

## Remarks

This method does not validate the signature that is derived from the new signature markup that is in the *newSignatureXml* parameter.

The caller must confirm that the new signature markup, which replaces the existing signature markup in the specified signature part, will not break the signature.

This method changes the existing signature markup; certificates and relationships that have the specified signature part as their source are preserved.

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Core Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/core-packaging-interfaces)

[Digital Signatures Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/digital-signatures-overview)

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcDigitalSignatureManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcdigitalsignaturemanager)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Digital Signature Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-digital-signature-interfaces)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**