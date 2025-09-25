# IOpcSigningOptions::GetCertificateEmbeddingOption

## Description

Gets a value that specifies the storage location in the package of the certificate to be used for the signature.

## Parameters

### `embeddingOption` [out, retval]

A value that specifies the location of the certificate.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *embeddingOption* parameter is not a valid [OPC_CERTIFICATE_EMBEDDING_OPTION](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_certificate_embedding_option) enum value. |

## Remarks

The default location of the certificate is **OPC_CERTIFICATE_IN_CERTIFICATE_PART**. To change this value, call the [IOpcSigningOptions::SetCertificateEmbeddingOption](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcsigningoptions-setcertificateembeddingoption) method.

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Core Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/core-packaging-interfaces)

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcSigningOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsigningoptions)

[OPC_CERTIFICATE_EMBEDDING_OPTION](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_certificate_embedding_option)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Digital Signature Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-digital-signature-interfaces)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**