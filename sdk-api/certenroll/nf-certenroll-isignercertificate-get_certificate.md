# ISignerCertificate::get_Certificate

## Description

The **Certificate** property retrieves a [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) encoded byte array that contains the certificate. The DER-encoded byte array is represented by a Unicode-encoded string.

This property is read-only.

## Parameters

## Remarks

Call the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-initialize) method to specify the certificate. You can also call the following properties to retrieve information about the signing certificate object:

* [Pin](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-put_pin)
* [PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_privatekey)
* [SignatureInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_signatureinformation)
* [Silent](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_silent)
* [UIContextMessage](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-isignercertificate-get_uicontextmessage)

## See also

[ISignerCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-isignercertificate)