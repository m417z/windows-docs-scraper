# IOpcRelationshipSet::CreateRelationship

## Description

Creates a relationship object that represents a specified relationship, then adds to the set a pointer to the object's [IOpcRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationship) interface.

## Parameters

### `relationshipIdentifier` [in]

A unique identifier of the relationship to be represented as the relationship object. To use a randomly generated identifier, pass **NULL** to this parameter.

Valid identifiers conform to the restrictions for **xsd:ID**, which are documented in section 3.3.8 ID of the [W3C Recommendation, XML Schema Part 2: Datatypes Second Edition](https://www.w3.org/TR/xmlschema-2/#ID) (http://www.w3.org/TR/xmlschema-2/#ID).

### `relationshipType` [in]

The relationship type that defines the role of the relationship to be represented as the relationship object.

### `targetUri` [in]

A URI to the target of the relationship to be represented as the relationship object.

If the value in *targetMode* is **OPC_URI_TARGET_MODE_INTERNAL**, target is a part and the URI must be relative to the source of the relationship.

If the value in *targetMode* is **OPC_URI_TARGET_MODE_EXTERNAL**, target is a resource outside of the package and the URI may be absolute or relative to the location of the package.

For more information about the URI of a relationship's target, see the *OPC*.

### `targetMode` [in]

A value that indicates whether the target of the relationship to be represented as the relationship object is internal or external to the package.

### `relationship` [out, retval]

A pointer to the [IOpcRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationship) interface of the relationship object that represents the relationship.

This parameter can be **NULL** if a pointer to the new object is not needed.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The value passed in the *targetMode* parameter is not a valid [OPC_URI_TARGET_MODE](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_uri_target_mode) enumeration value. |
| **E_POINTER** | At least one of the *relationshipType* and *targetUri* parameters is **NULL**. |
| **OPC_E_DUPLICATE_RELATIONSHIP**<br><br>0x80510013 | A relationship with the same identifier already exists in the current package. |
| **OPC_E_INVALID_RELATIONSHIP_ID**<br><br>0x80510010 | The **Id** attribute of a relationship does not conform to the rules specified in the *OPC*. |
| **OPC_E_INVALID_RELATIONSHIP_TARGET**<br><br>0x80510012 | The URI in *targetUri* is absolute and the value in *targetMode* is **OPC_URI_TARGET_MODE_INTERNAL**. The target's URI must be relative when this target mode is specified. |
| **OPC_E_INVALID_RELATIONSHIP_TARGET**<br><br>0x80510012 | The **Target** attribute of a relationship does not conform to the rules specified in the *OPC*. |
| **OPC_E_INVALID_RELATIONSHIP_TYPE**<br><br>0x80510011 | The **Type** attribute of a relationship does not conform to the rules specified in the *OPC*. |
| **Package Consumption error** | An **HRESULT** error code from the [Package Consumption Error Group](https://learn.microsoft.com/previous-versions/windows/desktop/opc/package-consumption-error-group). |
| **Part URI error** | An **HRESULT** error code from the [Part URI Error Group](https://learn.microsoft.com/previous-versions/windows/desktop/opc/part-uri-error-group). |

## Remarks

When a relationship object is created and a pointer to it is added to the set, the relationship it represents is saved when the package is saved.

The [IOpcRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationship) interface provides access to relationship properties. For details about these properties, see the [Relationships Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/relationships-overview) and [IOpcRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationship).

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[ECMA-376 OpenXML](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

**External Resources**

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcRelationshipSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationshipset)

[OPC_URI_TARGET_MODE](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_uri_target_mode)

[Open Packaging Conventions Fundamentals](https://learn.microsoft.com/previous-versions/windows/desktop/opc/open-packaging-conventions-overview)

**Overviews**

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

**Reference**

[Relationships Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/relationships-overview)

[W3C Recommendation, XML Schema Part 2: Datatypes Second Edition](https://www.w3.org/TR/xmlschema-2/#ID)