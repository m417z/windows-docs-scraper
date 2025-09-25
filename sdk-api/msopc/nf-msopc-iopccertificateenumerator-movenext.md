# IOpcCertificateEnumerator::MoveNext

## Description

Moves the current position of the enumerator to the next [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure.

## Parameters

### `hasNext` [out, retval]

A Boolean value that indicates the status of the [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure at the current position.

The value of *hasNext* is only valid when the method succeeds.

| Value | Meaning |
| --- | --- |
| TRUE | The current position of the enumerator has been advanced to the next pointer and that pointer is valid. |
| FALSE | The current position of the enumerator has been advanced past the end of the collection and is no longer valid. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *hasNext* parameter is **NULL**. |
| **OPC_E_ENUM_CANNOT_MOVE_NEXT**<br><br>0x80510051 | The current position is already past the last item of the enumerator. |
| **OPC_E_ENUM_COLLECTION_CHANGED**<br><br>0x80510050 | The enumerator is invalid because the underlying set has changed. |

## See also

[Certificates](https://learn.microsoft.com/windows/desktop/SecCrypto/certificates)

[Core Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/core-packaging-interfaces)

[Digital Signatures Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/digital-signatures-overview)

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcCertificateEnumerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopccertificateenumerator)

[IOpcCertificateSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopccertificateset)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**