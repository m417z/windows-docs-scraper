# ICspInformation::GetCspStatusFromOperations

## Description

The **GetCspStatusFromOperations** method creates an [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) object for the first supported algorithm that is consistent with the specified signature, encryption, hashing, or cipher operation.

## Parameters

### `pAlgorithm` [in, optional]

Pointer to an [IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid) interface that represents an algorithm OID. This parameter is optional and can be **NULL**.

* If you specify an OID and set the *Operations* parameter to **XCN_NCRYPT_SIGNATURE_OPERATION** and combine this flag with either XCN_NCRYPT_EXACT_MATCH_OPERATION or XCN_NCRYPT_PREFER_SIGNATURE_ONLY_OPERATION, the first signature algorithm, if any, that matches the OID is used.
* If you specify an OID but do not set the *Operations* parameter to **XCN_NCRYPT_SIGNATURE_OPERATION**, or you set **XCN_NCRYPT_SIGNATURE_OPERATION** but do not combine it with either XCN_NCRYPT_EXACT_MATCH_OPERATION or XCN_NCRYPT_PREFER_SIGNATURE_ONLY_OPERATION, the first algorithm that can be used for signing or encryption is used.
* If you do not specify an OID, the first supported algorithm consistent with the flags specified in the *Operations* parameter is used.

### `Operations` [in]

An [AlgorithmOperationFlags](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-algorithmoperationflags) enumeration value that identifies the type of algorithm to retrieve. One of the following values must be specified:

* XCN_NCRYPT_CIPHER_OPERATION
* XCN_NCRYPT_HASH_OPERATION
* XCN_NCRYPT_SIGNATURE_OPERATION
* XCN_NCRYPT_SECRET_AGREEMENT_OPERATION
* XCN_NCRYPT_ASYMMETRIC_ENCRYPTION_OPERATION

You can refine the search characteristics by combining one of the preceding flags with one of the following:

* XCN_NCRYPT_PREFER_SIGNATURE_ONLY_OPERATION
* XCN_NCRYPT_PREFER_NON_SIGNATURE_OPERATION
* XCN_NCRYPT_EXACT_MATCH_OPERATION

If you set the XCN_NCRYPT_PREFER_SIGNATURE_ONLY_OPERATION or XCN_NCRYPT_PREFER_NON_SIGNATURE_OPERATION preference flags, you cannot also specify either of the following:

* XCN_NCRYPT_CIPHER_OPERATION
* XCN_NCRYPT_HASH_OPERATION

### `ppValue` [out]

Address of a variable that receives a pointer to an [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) interface.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****CERTSRV_E_PROPERTY_EMPTY**** | The [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) object could not be found. |
| ****OLE_E_BLANK**** | The [ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation) object has not been initialized. |

## Remarks

An [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) object contains status information about a cryptographic provider. Each object is initialized for a specific algorithm supported by the provider. If you do not specify an algorithm in the *pAlgorithm* parameter, the first supported algorithm that is consistent with the permitted operations is chosen to create the **ICspStatus** object.

## See also

[ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation)