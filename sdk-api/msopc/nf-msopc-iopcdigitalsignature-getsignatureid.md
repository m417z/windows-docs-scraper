# IOpcDigitalSignature::GetSignatureId

## Description

Gets the value of the **Id** attribute from the **Signature** element of the signature markup.

## Parameters

### `signatureId` [out, retval]

A pointer to the **Id** attribute value of the signature markup **Signature** element.

If the **Signature** element does not have an **Id** attribute value, *signatureId* will be the empty string.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *signatureId* parameter is **NULL**. |

## Remarks

This method allocates memory used by the string returned in *signatureId*. If the method succeeds, call the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free the memory.

The **Id** attribute of the **Signature** element is optional. If this method is not called, the **Signature** element will not have the **Id** attribute.

To set the signature Id before the signature is generated, call the [IOpcSigningOptions::SetSignatureId](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcsigningoptions-setsignatureid) method.

To access the Id before the signature is generated, call the [IOpcSigningOptions::GetSignatureId](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcsigningoptions-getsignatureid). method.

## See also

[Core Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/core-packaging-interfaces)

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcDigitalSignature](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcdigitalsignature)

[IOpcSigningOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsigningoptions)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Digital Signature Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-digital-signature-interfaces)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**