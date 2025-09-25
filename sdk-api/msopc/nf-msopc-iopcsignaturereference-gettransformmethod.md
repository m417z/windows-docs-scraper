# IOpcSignatureReference::GetTransformMethod

## Description

Gets the canonicalization method to use on the referenced XML element, when the element is signed.

## Parameters

### `transformMethod` [out, retval]

 The canonicalization method to use on the referenced XML element, when the element is signed.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *transformMethod* parameter is **NULL**. |

## See also

[Core Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/core-packaging-interfaces)

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcSignatureReference](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturereference)

[OPC_CANONICALIZATION_METHOD](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_canonicalization_method)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Digital Signature Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-digital-signature-interfaces)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**