# IX509CertificateRequest::put_UIContextMessage

## Description

The **UIContextMessage** property specifies or retrieves a context string to display in the user interface.

This property is read/write.

## Parameters

## Remarks

You can set this property before calling any initialization method or the [Encode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-encode) method. For a PKCS #10 request, the property value is retrieved from and specified on the associated [IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey) object if the key exists. For a PKCS #7 or CMC request the property value is updated on the inner request and all signing certificates.

The context string should include additional information about an action. For example, if the user interface instructs the user to enter a smartcard PIN, the context string can indicate that a PIN is used to verify the identity of the user so that the request can be signed.

## See also

[IX509CertificateRequest](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequest)

[IX509CertificateRequestCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcertificate)

[IX509CertificateRequestCmc](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestcmc)

[IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10)

[IX509CertificateRequestPkcs7](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs7)

[IX509SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509signatureinformation)