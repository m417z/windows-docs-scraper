# IX509CertificateRequestPkcs10::GetCspStatuses

## Description

The **GetCspStatuses** method retrieves an [ICspStatuses](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatuses) collection that contains all provider/algorithm pairs consistent with the intended use of the private key as specified by the caller.

## Parameters

### `KeySpec` [in]

An [X509KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509keyspec) enumeration value that specifies the intended use of the key. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **XCN_AT_NONE** | Only Cryptography API: Next Generation (CNG) providers are selected. |
| **XCN_AT_KEYEXCHANGE** | Only CryptoAPI [cryptographic service providers](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSPs) with encryption algorithms (including key exchange) are selected. |
| **XCN_AT_SIGNATURE** | Only CryptoAPI CSPs with signature algorithms are selected. |

### `ppCspStatuses` [out]

Address of a variable that receives a pointer to an [ICspStatuses](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatuses) interface that represents the collection.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **CERTSRV_E_PROPERTY_EMPTY** | The private key cannot be found. |
| **OLE_E_BLANK** | The object is not initialized. |

## Remarks

This method retrieves a collection of [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) objects. Each object represents a single provider/algorithm pair. If you specify a template when initializing the [IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10) request object, template attributes such as the **pKIDefaultCSPs** and **pKIDefaultKeySpec** affect which pairs are initially enabled. You can call the following properties on each **ICspStatus** object to retrieve information about a pair:

* The [CspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspstatus-get_cspinformation) property retrieves provider information.
* The [CspAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspstatus-get_cspalgorithm) property retrieves algorithm information.
* The [EnrollmentStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspstatus-get_enrollmentstatus) property retrieves an [IX509EnrollmentStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentstatus) object. Call the [Selected](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_selected) property on the status object to determine whether the provider/algorithm pair is enabled for this request.
* The [Ordinal](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspstatus-get_ordinal) property retrieves the position in the provider/algorithm pair collection.

The collection retrieved by this method is saved internally on the request object. Up to three collections, one for each *KeySpec* value, can be created and saved. This is done to preserve the selection state of the provider/algorithm pairs so that relevant property pages can be displayed accurately and quickly multiple times and so that the [Encode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-encode) method can identify which providers and algorithms are selected if a private key must be created. If the selection state of a provider/algorithm pair is modified, the changes are saved to the appropriate collection. Changes made to the members of one collection do not affect the members of any other collection. The collections exist as long as the PKCS #10 object continues to exist.

Assume, for example, that this method is called with the *KeySpec* parameter set to XCN_AT_SIGNATURE and that a template is used to initialize the request. The following statements will be true:

* A collection of [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) objects is created and saved on the [IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10) object. The collection contains all valid provider/algorithm pairs installed on the computer.
* Because the *KeySpec* parameter is not set to XCN_AT_NONE, the [Selected](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_selected) property is set to SelectedNo for each Cryptography API: Next Generation (CNG) provider/algorithm pair in the collection.
* Because the *KeySpec* parameter is not set to XCN_AT_KEYEXCHANGE, the [Selected](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_selected) property is set to SelectedNo for each CryptoAPI CSP/algorithm pair in the collection where the algorithm can be used to encrypt data or archive a key.
* For each provider referenced by the template or private key but not supported on the computer, a placeholder [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) object is created and added to the collection and the [Selected](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_selected) property is set to SelectedNo.
* The [Selected](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_selected) property is set to SelectedYes for each CryptoAPI CSP/algorithm pair where the algorithm can be used only to sign data.
* The [Ordinal](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspstatus-get_ordinal) property is set to reflect the CSP order, if any, identified by the **pKIDefaultCSPs** template attribute. The CSPs listed first by the attribute are ordered first in the collection. This property is used during enrollment if a private key must be created. The first selected CSP/algorithm pair is used to create the key, but if the operation fails, the next selected pair is tried.
* Calling this method again with the same *KeySpec* parameter retrieves a pointer to the existing collection created previously for that parameter value.
* Calling this method again with a different *KeySpec* parameter will not affect the collection created for the XCN_AT_SIGNATURE *KeySpec* value. Further, changing the [Selected](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_selected) property on any member of the new collection does not affect any member of the previous collection.

The **GetCspStatuses** method differs from the [CspStatuses](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-get_cspstatuses) property by use of the *KeySpec* parameter. The method allows users to specify this value, but the property uses the value set on the private key associated with the request object.

 You must initialize the [IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10) object before calling this method. For more information, see any of the following methods:

* [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializedecode)
* [InitializeFromCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializefromcertificate)
* [InitializeFromPrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializefromprivatekey)
* [InitializeFromPublicKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializefrompublickey)
* [InitializeFromTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializefromtemplatename)

## See also

[IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10)