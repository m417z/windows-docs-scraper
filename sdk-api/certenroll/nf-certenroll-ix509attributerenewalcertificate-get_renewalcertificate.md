# IX509AttributeRenewalCertificate::get_RenewalCertificate

## Description

The **RenewalCertificate** property retrieves the certificate to be renewed. The [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) encoded certificate is contained in a byte array that is represented by a Unicode-encoded string.

This property is read-only.

## Parameters

## Remarks

Call the [InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributerenewalcertificate-initializeencode) method or the [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributerenewalcertificate-initializedecode) method to initialize the **RenewalCertificate** property.

## See also

[IX509AttributeRenewalCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributerenewalcertificate)