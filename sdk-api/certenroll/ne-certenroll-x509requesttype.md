# X509RequestType enumeration

## Description

The **X509RequestType** enumeration specifies the [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) type. This enumeration is returned by the [Type](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_type) property on the [IX509CertificateRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequest) interface.

## Constants

### `TypeAny:0`

The type is not defined.

### `TypePkcs10:1`

A PKCS #10 request. For more information, see the [IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10) interface.

### `TypePkcs7:2`

A PKCS #7 request represented by an [IX509CertificateRequestPkcs7](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs7) interface.

### `TypeCmc:3`

A [Certificate Management over CMS](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CMC) request. For more information, see the [IX509CertificateRequestCmc](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcmc) interface.

### `TypeCertificate:4`

A self-signed [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). For more information, see the [IX509CertificateRequestCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcertificate) interface.

## See also

[CertEnroll Enumerations](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-enumerations)

[CertEnroll Interfaces](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-interfaces)