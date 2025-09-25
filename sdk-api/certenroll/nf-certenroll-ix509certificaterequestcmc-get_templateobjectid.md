# IX509CertificateRequestCmc::get_TemplateObjectId

## Description

The **TemplateObjectId** property retrieves the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) of the template used to create the certificate request.

This property is read-only.

## Parameters

## Remarks

The object identifier can be an OID for the Active Directory Common Name (CN) of the template. You must initialize the [IX509CertificateRequestCmc](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcmc) object before calling this property. For more information, see any of the following methods:

* [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-initialize)
* [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializedecode)
* [InitializeFromCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializefromcertificate)
* [InitializeFromInnerRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializefrominnerrequest)
* [InitializeFromInnerRequestTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestcmc-initializefrominnerrequesttemplatename)
* [InitializeFromTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializefromtemplatename)

## See also

[IX509CertificateRequestCmc](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcmc)