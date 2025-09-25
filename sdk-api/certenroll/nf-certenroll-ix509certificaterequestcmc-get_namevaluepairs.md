# IX509CertificateRequestCmc::get_NameValuePairs

## Description

The **NameValuePairs** property retrieves an [IX509NameValuePairs](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509namevaluepairs) collection associated with a certificate request.

This property is read-only.

## Parameters

## Remarks

For an example of a name-value pair in a CMC request object, see [IX509NameValuePair](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509namevaluepair). You must initialize the CMC request object before calling this property. For more information, see the following topics:

* [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-initialize)
* [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializedecode)
* [InitializeFromCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializefromcertificate)
* [InitializeFromInnerRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializefrominnerrequest)
* [InitializeFromInnerRequestTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestcmc-initializefrominnerrequesttemplatename)
* [InitializeFromTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializefromtemplatename)

## See also

[IX509CertificateRequestCmc](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcmc)