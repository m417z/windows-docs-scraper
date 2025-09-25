# InnerRequestLevel enumeration

## Description

The **InnerRequestLevel** enumeration type specifies the containment level of a [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) within a PKCS #7 or [Certificate Management over CMS](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CMC) request. This enumeration is used by the [GetInnerRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-getinnerrequest) method on the [IX509CertificateRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequest) interface and inherited by the [IX509CertificateRequestPkcs7](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs7) and [IX509CertificateRequestCmc](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcmc) interfaces. You can use the enumeration values to retrieve the innermost nested certificate or to iterate through all of the nesting levels.

## Constants

### `LevelInnermost:0`

Use to retrieve the most deeply nested request.

### `LevelNext:1`

Use to retrieve the request at the next nesting level.

## See also

[CertEnroll Enumerations](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-enumerations)

[CertEnroll Interfaces](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-interfaces)

[GetInnerRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-getinnerrequest)