# IX509CertificateRequest::get_Silent

## Description

The **Silent** property specifies or retrieves a Boolean value that indicates whether any of the key-related modal dialogs are displayed during the certificate enrollment process.

This property is read/write.

## Parameters

## Remarks

This property value is used by key-related Certificate Enrollment Control modal dialogs that:

* Direct a user to insert a smart card
* Request a smart card pin number
* Request the protection level for a new key
* Request a user password before accessing a key

You can set this property before calling any initialization method or the [Encode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-encode) method. For a PKCS #10 request, the property value is retrieved from and specified on the associated [IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey) object if the key exists. For a PKCS #7 or CMC request the property value is updated on the inner request and all signing certificates.

If the certificate request contains nested requests and you set the **Silent** property on the top level request, it is automatically propagated to all of the inner requests. You can, however, set the property manually on each of the inner objects.

## See also

[IX509CertificateRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequest)

[IX509CertificateRequestCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcertificate)

[IX509CertificateRequestCmc](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcmc)

[IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10)

[IX509CertificateRequestPkcs7](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs7)

[IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation)