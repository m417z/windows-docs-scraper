# IOpcSignatureRelationshipReferenceSet::Create

## Description

Creates an [IOpcSignatureRelationshipReference](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturerelationshipreference) interface pointer that represents a reference to a Relationships part, and adds the new interface pointer to the set. All or a subset of the relationships stored in the Relationships part to be referenced are selected for signing.

## Parameters

### `sourceUri` [in]

An [IOpcUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcuri) interface pointer that represents the source URI of the relationships to be selected for signing.

### `digestMethod` [in]

The digest method to be used for the relationships to be selected. To use the default digest method, pass **NULL** in this parameter.

**Important** The default digest method must be set by calling the [IOpcSigningOptions::SetDefaultDigestMethod](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcsigningoptions-setdefaultdigestmethod) method before [IOpcDigitalSignatureManager::Sign](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcdigitalsignaturemanager-sign) is called.

### `relationshipSigningOption` [in]

A value that indicates whether the relationships selected for signing include all or a subset of the relationships in the Relationships part to be referenced.

For information about the effect of *relationshipSigningOption* values on other parameters, see Remarks.

### `selectorSet` [in]

An [IOpcRelationshipSelectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationshipselectorset) interface pointer that can be used to identify a subset of relationships in the Relationships part to be selected for signing.

If *relationshipSigningOption* is set to **OPC_RELATIONSHIP_SIGN_PART**, *selectorSet* is **NULL**.

For information about *selectorSet* values, see Remarks.

### `transformMethod` [in]

A value that describes the canonicalization method to be applied to the relationship markup of the selected relationships.

If *relationshipSigningOption* is set **OPC_RELATIONSHIP_SIGN_USING_SELECTORS**, the value of *transformMethod* is ignored.

For more information about the transform methods to be applied when *relationshipSigningOption* is set to **OPC_RELATIONSHIP_SIGN_USING_SELECTORS**, see Remarks.

### `relationshipReference` [out, retval]

A new [IOpcSignatureRelationshipReference](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturerelationshipreference) interface pointer that represents the referenced Relationships part.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The value passed in the *relationshipSigningOption* parameter is not a valid [OPC_RELATIONSHIPS_SIGNING_OPTION](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_relationships_signing_option) enumeration value. |
| **E_INVALIDARG** | The value passed in the *transformMethod* parameter is not a valid [OPC_CANONICALIZATION_METHOD](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_canonicalization_method) enumeration value. |
| **E_POINTER** | The *sourceUri* parameter is **NULL**. |
| **E_UNEXPECTED** | The *selectorSet* parameter is not being passed **NULL** while the *relationshipSigningOption* parameter is passed a value of **OPC_RELATIONSHIP_SIGN_PART**. |

## Remarks

This method creates a reference to a Relationships part. All or a subset of the relationships that are stored in a referenced Relationships part can be signed when the signature is generated.

To sign all of the relationships in a Relationships part, call this method with the *relationshipSigningOption* parameter value set to **OPC_RELATIONSHIP_SIGN_PART** and the *selectorSet* parameter value set to **NULL**.

To sign a subset of the relationships in a Relationships part, call this method with the *relationshipSigningOption* parameter value set to **OPC_RELATIONSHIP_SIGN_USING_SELECTORS** and the *selectorSet* parameter value set to an [IOpcRelationshipSelectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationshipselectorset) interface pointer. To create an **IOpcRelationshipSelectorSet** interface pointer, call the [CreateRelationshipSelectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcsignaturerelationshipreferenceset-createrelationshipselectorset) method.

The following table summarizes the parameter values required by this method to create a reference that indicates whether all of the relationships or a subset of the relationships (which are stored in the Relationships part to be referenced) are to be signed.

| Description | *relationshipSigningOption* Value | *selectorSet* Value |
| --- | --- | --- |
| Sign all of the relationships in the Relationships part | **OPC_RELATIONSHIP_SIGN_PART** | **NULL** |
| Sign a subset of the relationships in the Relationships part | **OPC_RELATIONSHIP_SIGN_USING_SELECTORS** | An [IOpcRelationshipSelectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationshipselectorset) interface pointer |

If a subset of relationships are to be signed, the specified transform method is ignored. Instead, when the signature is generated, the first transform applied is the Relationships Transform, and the second is the **OPC_CANONICALIZATION_C14N** canonicalization method.

When an [IOpcSignatureRelationshipReference](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturerelationshipreference) interface pointer is created and added to the set, the reference it represents is saved when the package is saved.

 Relationships that will not be signed can be removed, modified or added to the package without invalidating the signature. If a subset of relationships has been selected for signing and the subset is altered, the signature will be invalidated.

**Important** A selected subset could be altered if the relationship type of a relationship that is added to or modified in a referenced Relationships part matches a relationship type that was used to select one or more relationships in the subset.

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Core Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/core-packaging-interfaces)

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcDigitalSignatureManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcdigitalsignaturemanager)

[IOpcSignatureRelationshipReferenceSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturerelationshipreferenceset)

[IOpcSigningOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsigningoptions)

[OPC_CANONICALIZATION_METHOD](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_canonicalization_method)

[OPC_RELATIONSHIPS_SIGNING_OPTION](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_relationships_signing_option)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Digital Signature Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-digital-signature-interfaces)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**