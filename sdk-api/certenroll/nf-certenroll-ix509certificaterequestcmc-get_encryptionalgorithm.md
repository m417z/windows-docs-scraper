# IX509CertificateRequestCmc::get_EncryptionAlgorithm

## Description

The **EncryptionAlgorithm** property specifies or retrieves an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) of the algorithm used to encrypt the private key to be archived. This property is web enabled for both input and output.

This property is read/write.

## Parameters

## Remarks

When you request that a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) archive your private key, you must retrieve an exchange certificate from the CA and use the public key contained in that certificate to encrypt the private key that you are submitting for archival. The **EncryptionAlgorithm** property identifies the algorithm used to encrypt your key.

This property is related to the following properties:

* [ArchivePrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestcmc-get_archiveprivatekey)
* [EncryptedKeyHash](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestcmc-get_encryptedkeyhash)
* [EncryptionStrength](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestcmc-get_encryptionstrength)
* [KeyArchivalCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestcmc-get_keyarchivalcertificate)

You must set this property, if at all, before calling the [Encode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-encode) method, but you must initialize the CMC request object before calling the property. For more information, see the following topics:

* [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-initialize)
* [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializedecode)
* [InitializeFromCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializefromcertificate)
* [InitializeFromInnerRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializefrominnerrequest)
* [InitializeFromInnerRequestTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestcmc-initializefrominnerrequesttemplatename)
* [InitializeFromTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-initializefromtemplatename)

## See also

[IX509CertificateRequestCmc](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcmc)