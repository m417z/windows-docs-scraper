# IOpcDigitalSignatureEnumerator::GetCurrent

## Description

Gets the [IOpcDigitalSignature](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcdigitalsignature) interface pointer at the current position of the enumerator.

## Parameters

### `digitalSignature` [out, retval]

An [IOpcDigitalSignature](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcdigitalsignature) interface pointer.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *partReference* parameter is **NULL**. |
| **OPC_E_ENUM_COLLECTION_CHANGED**<br><br>0x80510050 | The enumerator is invalid because the underlying set has changed. |
| **OPC_E_ENUM_INVALID_POSITION**<br><br>0x80510053 | The enumerator cannot perform this operation from its current position. |
| **OPC_E_DS_DUPLICATE_PACKAGE_OBJECT_REFERENCES**<br><br>0x8051002D | The signature markup contains more than one **Reference** element that refers to the package **Object** element, but only one such **Reference** is allowed. |
| **OPC_E_DS_DUPLICATE_SIGNATURE_PROPERTY_ELEMENT**<br><br>0x80510028 | The signature markup contains more than one **SignatureProperty** element that has the same **Id** attribute. |
| **OPC_E_DS_EXTERNAL_SIGNATURE_REFERENCE**<br><br>0x8051002F | A **Reference** element in the signature markup indicates an object that is external to the package. **Reference** elements must point to parts or **Object** elements that are internal. |
| **OPC_E_DS_INVALID_CANONICALIZATION_METHOD**<br><br>0x80510022 | An unsupported canonicalization method was requested or used in a signature. |
| **OPC_E_DS_INVALID_SIGNATURE_COUNT**<br><br>0x8051002B | A Signature part does not contain the signature markup for exactly one signature. |
| **OPC_E_DS_INVALID_SIGNATURE_XML**<br><br>0x8051002A | The signature markup in a Signature part does not conform to the schema specified in the *OPC* or [XML-Signature Syntax and Processing](https://www.w3.org/TR/xmldsig-core/) (http://www.w3.org/TR/xmldsig-core/). |
| **OPC_E_DS_MISSING_CANONICALIZATION_TRANSFORM**<br><br>0x80510032 | A relationships transform must be followed by a canonicalization method. |
| **OPC_E_DS_MISSING_PACKAGE_OBJECT_REFERENCE**<br><br>0x8051002E | The signature markup is missing a **Reference** to the package-specific **Object** element. |
| **OPC_E_DS_MISSING_SIGNATURE_ALGORITHM**<br><br>0x8051002C | The signature markup does not specify signature method algorithm. |
| **OPC_E_DS_MISSING_SIGNATURE_PART**<br><br>0x80510020 | The specified Signature part does not exist in the package. |
| **OPC_E_DS_MISSING_SIGNATURE_PROPERTIES_ELEMENT**<br><br>0x80510026 | The **SignatureProperties**  element was not found in the signature markup. |
| **OPC_E_DS_MISSING_SIGNATURE_PROPERTY_ELEMENT**<br><br>0x80510027 | The **SignatureProperty** child element of the **SignatureProperties** element was not found. |
| **OPC_E_DS_MISSING_SIGNATURE_TIME_PROPERTY**<br><br>0x80510029 | The **SignatureProperty** element with the **Id** attribute value of "idSignatureTime" does not exist or is not correctly constructed. |
| **OPC_E_DS_MULTIPLE_RELATIONSHIP_TRANSFORMS**<br><br>0x80510031 | More than one relationships transform is specified for a **Reference** element, but only one relationships transform is allowed. |
| **OPC_E_DS_REFERENCE_MISSING_CONTENT_TYPE**<br><br>0x80510030 | The **URI** attribute value of a **Reference** element in the signature markup does not include the content type of the referenced part. |
| **OPC_E_DS_SIGNATURE_REFERENCE_MISSING_URI**<br><br>0x80510043 | The **URI** attribute is required for a **Reference** element but is missing. |
| **OPC_E_UNEXPECTED_CONTENT_TYPE**<br><br>0x80510005 | Either the content type of a part differed from the expected content type (specified in the OPC, [ECMA-376 Part 2](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)), or the part content did not match the part's content type. |

## Remarks

When an enumerator is created, the current position precedes the first pointer. To set the current position to the first pointer of the enumerator, call the [MoveNext](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcdigitalsignatureenumerator-movenext) method after creating the enumerator.

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Digital Signatures Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/digital-signatures-overview)

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcDigitalSignatureEnumerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcdigitalsignatureenumerator)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Digital Signature Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-digital-signature-interfaces)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**