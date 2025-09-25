# IX509PrivateKey::put_CspInformations

## Description

The **CspInformations** property specifies or retrieves a collection of [ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation) objects that contain information about the available cryptographic providers that support the public key algorithm associated with the private key. This property is web enabled for both input and output.

This property is read/write.

## Parameters

## Remarks

The enrollment process expects the [ICspInformations](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformations) collection to include all providers installed on the client computer. You should therefore not attempt to set this property to a subset of the installed providers. We recommend that you create an empty collection and call [AddAvailableCsps](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformations-addavailablecsps) to populate it. Build this collection once and set it on all top level request objects (or the private key if you are using the [IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey) object directly) to avoid the cost of creating multiple collections. An **ICspInformations** collection is large.

## See also

[IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)