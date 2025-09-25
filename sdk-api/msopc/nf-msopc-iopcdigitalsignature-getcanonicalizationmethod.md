# IOpcDigitalSignature::GetCanonicalizationMethod

## Description

Gets the canonicalization method that was applied to the **SignedInfo** element of the serialized signature.

## Parameters

### `canonicalizationMethod` [out, retval]

An [OPC_CANONICALIZATION_METHOD](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_canonicalization_method) value that specifies the canonicalization method that was applied to the **SignedInfo** element of the signature markup when the signature was generated.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *canonicalizationMethod* parameter is **NULL**. |

## Remarks

When using the APIs to generate a signature, the C14N canonicalization method that removes comments is applied to the **SignedInfo** element. This method corresponds to the **OPC_CANONICALIZATION_C14N** enum value.

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Core Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/core-packaging-interfaces)

[Digital Signatures Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/digital-signatures-overview)

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcDigitalSignature](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcdigitalsignature)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Digital Signature Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-digital-signature-interfaces)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**