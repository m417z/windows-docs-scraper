# IX509CertificateRequestPkcs10::get_ReuseKey

## Description

The **ReuseKey** property retrieves a Boolean value that indicates whether an existing private key was used to sign the request.

This property is read-only.

## Parameters

## Remarks

If you initialized the request object by calling the [InitializeFromCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializefromcertificate) method, you specified a value for the *InheritOptions* parameter that indicated whether the private key used to sign the request was inherited from the certificate. If you specified **InheritPrivateKey** for this parameter, the **ReuseKey** property returns a value of Boolean true.

## See also

[IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10)