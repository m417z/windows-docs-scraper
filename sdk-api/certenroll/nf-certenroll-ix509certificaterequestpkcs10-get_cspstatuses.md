# IX509CertificateRequestPkcs10::get_CspStatuses

## Description

The **CspStatuses** property retrieves a collection of [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) objects that matches the intended use of the private key associated with the certificate request.

This property is read-only.

## Parameters

## Remarks

This property retrieves a collection of [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) objects. Each object represents a single provider/algorithm pair. The **CspStatuses** property differs from the [GetCspStatuses](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-getcspstatuses) method. The method enables you to set a *KeySpec* parameter, but **CspStatuses** uses the [KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_keyspec) property set on the private key associated with the [IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10) object. This can be one of the following values.

| Value | Description |
| --- | --- |
| XCN_AT_NONE | Only Cryptography API: Next Generation (CNG) providers are selected. |
| XCN_AT_KEYEXCHANGE | Only CryptoAPI cryptographic service providers (CSPs) with encryption algorithms (including key exchange) are selected. |
| XCN_AT_SIGNATURE | Only CryptoAPI cryptographic service providers (CSPs) with signature algorithms are selected. |

 If you specify a template when initializing the request object, template attributes such as the **pKIDefaultCSPs** and **pKIDefaultKeySpec** affect which provider/algorithm pairs are initially enabled in the collection. You can call the following properties on each [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) object to retrieve information about a pair:

* The [CspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspstatus-get_cspinformation) property retrieves provider information.
* The [CspAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspstatus-get_cspalgorithm) property retrieves algorithm information.
* The [EnrollmentStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspstatus-get_enrollmentstatus) property retrieves an [IX509EnrollmentStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentstatus) object. Call the [Selected](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_selected) property on the status object to determine whether the provider/algorithm pair is enabled for this request.
* The [Ordinal](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspstatus-get_ordinal) property retrieves the position in the collection of the provider/algorithm pair.

The collection retrieved by this method is saved internally on the request object. The collection exists as long as the PKCS #10 object continues to exist.

Assume, for example, that the [KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_keyspec) property on the private key associated with the request object is set to XCN_AT_SIGNATURE and that a template is used to initialize the request. The following statements will be true:

* A collection of [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) objects is created and saved on the [IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10) object. The collection contains all valid provider/algorithm pairs installed on the computer.
* Because the [KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_keyspec) property is not set to XCN_AT_NONE, the [Selected](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_selected) property is set to SelectedNo for each Cryptography API: Next Generation (CNG) provider/algorithm pair in the collection.
* Because the [KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_keyspec) property is not set to XCN_AT_KEYEXCHANGE, the [Selected](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_selected) property is set to SelectedNo for each CryptoAPI CSP/algorithm pair in the collection where the algorithm can be used only to encrypt data or archive a key.
* For each provider referenced by the template or private key but not supported on the computer, a placeholder [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) object is created and added to the collection and the [Selected](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_selected) property is set to SelectedNo.
* The [Selected](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_selected) property is set to SelectedYes for each CryptoAPI CSP/algorithm pair where the algorithm can be used only to sign data.
* The [Ordinal](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspstatus-get_ordinal) property is set to reflect the CSP order, if any, identified by the **pKIDefaultCSPs** template attribute. The CSPs listed first by the attribute are ordered first in the collection. This property is used during enrollment if a private key must be created. The first selected CSP/algorithm pair is used to create the key, but if the operation fails, the next selected pair is tried.

 You must initialize the [IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10) object before calling this method. For more information, see any of the following methods:

* [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializedecode)
* [InitializeFromCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializefromcertificate)
* [InitializeFromPrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializefromprivatekey)
* [InitializeFromPublicKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializefrompublickey)
* [InitializeFromTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializefromtemplatename)

## See also

[ICspAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspalgorithm)

[ICspAlgorithms](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspalgorithms)

[ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation)

[ICspInformations](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformations)

[ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus)

[IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10)