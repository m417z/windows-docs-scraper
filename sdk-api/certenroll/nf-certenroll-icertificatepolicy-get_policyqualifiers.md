# ICertificatePolicy::get_PolicyQualifiers

## Description

The **PolicyQualifiers** property retrieves a collection of optional policy qualifiers that can be applied to a certificate policy.

This property is read-only.

## Parameters

## Remarks

An empty [IPolicyQualifiers](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ipolicyqualifiers) object is created when you call the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertificatepolicy-initialize) method. You can call the **PolicyQualifiers** property to retrieve this object and specify qualifying information for the policy. Policy qualifiers only apply if you are creating a **CertificatePolicies** extension. For more information, see the [IX509ExtensionCertificatePolicies](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensioncertificatepolicies).

## See also

[ICertificatePolicies](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertificatepolicies)

[ICertificatePolicy](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertificatepolicy)