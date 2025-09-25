# IX509CertificateRequestCmc::get_SuppressOids

## Description

The **SuppressOids** property retrieves a collection of extension or attribute [object identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OIDs) to be suppressed from the certificate during the encoding process.

This property is read-only.

## Parameters

## Remarks

Attributes and extensions are added to a certificate request when it is encoded or initialized. You can suppress the addition of default extensions and attributes by calling the [SuppressDefaults](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_suppressdefaults) property. For a CMC request, only the XCN_OID_REQUEST_CLIENT_INFO
([IX509AttributeClientId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributeclientid)) attribute is created by default. No extensions are added by default.

You must initialize the [IX509CertificateRequestCmc](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcmc) object before calling this property. For more information, see any of the following methods:

* [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-initialize)
* [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializedecode)
* [InitializeFromCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializefromcertificate)
* [InitializeFromInnerRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializefrominnerrequest)
* [InitializeFromInnerRequestTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestcmc-initializefrominnerrequesttemplatename)
* [InitializeFromTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializefromtemplatename)

## See also

[IX509CertificateRequestCmc](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcmc)