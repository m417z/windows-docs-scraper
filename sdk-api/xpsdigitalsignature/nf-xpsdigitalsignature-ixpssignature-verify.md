# IXpsSignature::Verify

## Description

Verifies the signature against a specified X.509 certificate.

## Parameters

### `x509Certificate` [in]

The [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that contains the X.509 certificate that will be used for verification.

If the signature is not incomplete or incompliant, this certificate will be used only to validate that the signed data in the XPS package is intact. The certificate will not be used to perform any other checks.
Before using the certificate the application is expected to verify the trust chain and any other requirements.

### `sigStatus` [out, retval]

The [XPS_SIGNATURE_STATUS](https://learn.microsoft.com/windows/win32/api/xpsdigitalsignature/ne-xpsdigitalsignature-xps_signature_status) value that describes the results of the verification.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For return values that are not listed in this table, see [XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85)) and [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *x509Certificate* or *sigStatus* is **NULL**. |
| **E_UNEXPECTED** | The interface is not connected to the signature manager. |

## Remarks

This method detects the signature status in the order that is specified in section 10.2.1.2 of the [XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification).
The sequence of detection is as follows: incompliant, incomplete, broken, questionable, and, finally, valid.
This means that if, for example, a signature is found to be incompliant, no digest will be calculated if the signature is also broken.

For more information on the different types of signature statuses that can be detected by this method, see [XPS_SIGNATURE_STATUS](https://learn.microsoft.com/windows/win32/api/xpsdigitalsignature/ne-xpsdigitalsignature-xps_signature_status).

## See also

[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context)

[IOpcDigitalSignature](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcdigitalsignature)

[IXpsSignature](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignature)

[IXpsSignatureManager](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturemanager)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85))

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_SIGNATURE_STATUS](https://learn.microsoft.com/windows/win32/api/xpsdigitalsignature/ne-xpsdigitalsignature-xps_signature_status)