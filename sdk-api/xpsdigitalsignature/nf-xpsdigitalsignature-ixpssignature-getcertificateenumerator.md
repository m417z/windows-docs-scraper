# IXpsSignature::GetCertificateEnumerator

## Description

Gets a pointer to an [IOpcCertificateEnumerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopccertificateenumerator) interface, which enumerates the package certificates that are attached to the signature.

## Parameters

### `certificateEnumerator` [out, retval]

A pointer to an [IOpcCertificateEnumerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopccertificateenumerator) interface, which enumerates the certificates that are attached to the signature.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For return values that are not listed in this table, see [XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85)) and [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_UNEXPECTED** | The interface is not connected to the signature manager. |

## Remarks

The [IOpcCertificateEnumerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopccertificateenumerator) interface returned in *certificateEnumerator* can be empty; however the [XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification) requires that at least the signing certificate be included in the XPS package. Package producers may include additional certificates as well. For example, the entire certificate trust chain could be included in the XPS package.

## See also

[IOpcCertificateEnumerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopccertificateenumerator)

[IOpcDigitalSignature](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcdigitalsignature)

[IXpsSignature](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignature)

[IXpsSignatureManager](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturemanager)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85))

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))