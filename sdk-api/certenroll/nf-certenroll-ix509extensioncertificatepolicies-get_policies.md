# IX509ExtensionCertificatePolicies::get_Policies

## Description

The **Policies** property retrieves a collection of certificate policies.

This property is read-only.

## Parameters

## Remarks

Call the [InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensioncertificatepolicies-initializeencode) method or the [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensioncertificatepolicies-initializedecode) method to initialize the collection. You can also call the [Critical](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_critical) property to specify and retrieve a Boolean value that identifies whether the extension is critical, and you can call the [ObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_objectid) property to retrieve the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) associated with the extension.

## See also

[IX509ExtensionCertificatePolicies](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensioncertificatepolicies)