# IX509CertificateRequestCmc::get_KeyArchivalCertificate

## Description

The **KeyArchivalCertificate** property specifies or retrieves a certification authority (CA) encryption certificate. The certificate is contained in a byte array that is encoded by using [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) as defined by the [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) standard. The DER-encoded byte array is represented by a string that is either a pure binary sequence or is Unicode encoded. This property is web enabled for both input and output.

This property is read/write.

## Parameters

## Remarks

If correctly configured, a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) can archive a client's private key. Typically, the client requests an exchange certificate from the CA, validates it, and uses it as input to the **KeyArchivalCertificate** property. The CA's public key is used to encrypt the private key that is being submitted for archiving. You can use the [ArchivePrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestcmc-get_archiveprivatekey) property to request key archival.

You must set this property, if at all, before calling the [Encode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-encode) method, but you must initialize the CMC request object before calling the property. For more information, see the following topics:

* [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-initialize)
* [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializedecode)
* [InitializeFromCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializefromcertificate)
* [InitializeFromInnerRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializefrominnerrequest)
* [InitializeFromInnerRequestTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestcmc-initializefrominnerrequesttemplatename)
* [InitializeFromTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializefromtemplatename)

## See also

[IX509CertificateRequestCmc](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcmc)