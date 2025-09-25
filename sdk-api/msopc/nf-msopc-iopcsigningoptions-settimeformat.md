# IOpcSigningOptions::SetTimeFormat

## Description

Sets the format of the string retrieved by the [IOpcDigitalSignature::GetSigningTime](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcdigitalsignature-getsigningtime) method.

## Parameters

### `timeFormat` [in]

The value that describes the format of the string retrieved by the [IOpcDigitalSignature::GetSigningTime](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcdigitalsignature-getsigningtime) method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The value passed in the *timeFormat* parameter is not a valid [OPC_SIGNATURE_TIME_FORMAT](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_signature_time_format) enumeration value. |

## Remarks

This method changes the format of the signing time string from the default format, **OPC_SIGNATURE_TIME_FORMAT_MILLISECONDS**, to a format that is specified by the caller.

To access the format of the signing time string before the signature is generated, call the [IOpcSigningOptions::GetTimeFormat](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcsigningoptions-gettimeformat) method. To access the format after the signature has been generated, call the [IOpcDigitalSignature::GetTimeFormat](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcdigitalsignature-gettimeformat) method.

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Core Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/core-packaging-interfaces)

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcDigitalSignature](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcdigitalsignature)

[IOpcSigningOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsigningoptions)

[OPC_SIGNATURE_TIME_FORMAT](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_signature_time_format)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Digital Signature Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-digital-signature-interfaces)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**