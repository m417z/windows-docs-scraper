# IOpcSignatureReference::GetUri

## Description

Gets the URI of the referenced XML element.

## Parameters

### `referenceUri` [out, retval]

A pointer to the URI of the referenced element.

This URI represented by a string is "#" followed by the **Id** attribute value of the referenced element: "#*\<elementIdValue>*".

For examples, see the Remarks section.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *referenceUri* parameter is **NULL**. |

## Remarks

The URI of the referenced element is serialized in the signature markup as the **URI** attribute of a **Reference** element.

The following table shows two examples of the *referenceUri* parameter value represented as strings.

| *referenceUri* Value as String | Referenced Element | Element Description |
| --- | --- | --- |
| "#*idMyCustomObject*" | "\<Object Id="*idMyCustomObject*">*...*\</Object>" | An application-specific **Object** element. |
| "#*idMyElement*" | "\<Object><*MyElement* Id="*idMyElement*">*...*</*MyElement*>...\</Object>" | A child element of an application-specific **Object**. |

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Core Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/core-packaging-interfaces)

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcSignatureReference](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturereference)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Digital Signature Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-digital-signature-interfaces)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**