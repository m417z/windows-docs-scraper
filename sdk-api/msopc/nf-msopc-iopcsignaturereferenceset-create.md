# IOpcSignatureReferenceSet::Create

## Description

Creates an [IOpcSignatureReference](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturereference) interface pointer that represents a reference to an XML element to be signed.

## Parameters

### `referenceUri` [in]

The URI of the referenced XML element.

Set the value of this parameter to a URI that represents "#" followed by the **Id** attribute value of the referenced element: "#*<elementIdValue>*".

For examples, see the Remarks section.

### `referenceId` [in]

The **Id** attribute of the **Reference** element that represents the reference in signature markup. To omit the **Id** attribute, set this parameter value to **NULL**.

### `type` [in]

The **Type** attribute of the **Reference** element that represents the reference in signature markup. To omit the **Type** attribute, set this parameter value to **NULL**.

### `digestMethod` [in]

The digest method to be used for the XML markup to be referenced. To use the default digest method, set this parameter value to **NULL**.

**Important** The default digest method must be set by calling the [IOpcSigningOptions::SetDefaultDigestMethod](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcsigningoptions-setdefaultdigestmethod) method before [IOpcDigitalSignatureManager::Sign](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcdigitalsignaturemanager-sign) is called.

### `transformMethod` [in]

The canonicalization method to be used for the XML markup to be referenced.

### `reference` [out, retval]

A new [IOpcSignatureReference](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturereference) interface pointer that represents the reference to the XML element to be signed.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The value passed in the *transformMethod* parameter is not a valid [OPC_CANONICALIZATION_METHOD](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_canonicalization_method) enumeration value. |
| **E_POINTER** | The *referenceUri* parameter is **NULL**. |
| **OPC_E_DS_PACKAGE_REFERENCE_URI_RESERVED**<br><br>0x80510025 | The reserved **URI** attribute value of the signature's **Reference** element to the package **Object** is being used as the **URI** attribute value of a **Reference** to a custom **Object** element. |

## Remarks

This method creates a reference to an XML element that is signed when the signature is generated. The referenced element can be either an application-specific **Object** element or a child of an application-specific **Object**.

To reference an XML element for signing, set the *referenceUri* parameter value to a URI that represents "#" followed by the **Id** attribute value of the referenced element, as shown in the following table.

| *referenceUri* Value as String | Referenced Element | Element Description |
| --- | --- | --- |
| "#*idMyCustomObject*" | "<Object Id="*idMyCustomObject*">*...*</Object>" | An application-specific **Object** element. |
| "#*idMyElement*" | "<Object><*MyElement* Id="*idMyElement*">*...*</*MyElement*>...</Object>" | A child element of an application-specific **Object**. |

This method does not create the reference to the package-specific **Object** element to be signed; that reference is created automatically when the signature is generated.

When an [IOpcSignatureReference](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturereference) interface pointer is created and added to the set, the reference it represents is saved when the package is saved.

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Core Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/core-packaging-interfaces)

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcDigitalSignatureManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcdigitalsignaturemanager)

[IOpcSignatureReferenceSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturereferenceset)

[IOpcSigningOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsigningoptions)

[OPC_CANONICALIZATION_METHOD](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_canonicalization_method)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Digital Signature Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-digital-signature-interfaces)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**