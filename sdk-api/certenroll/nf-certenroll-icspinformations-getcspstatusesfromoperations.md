# ICspInformations::GetCspStatusesFromOperations

## Description

The **GetCspStatusesFromOperations** method retrieves an [ICspStatuses](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatuses) collection by supported key operations and optional provider information. This method is web enabled.

## Parameters

### `Operations` [in]

An [AlgorithmOperationFlags](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-algorithmoperationflags) enumeration value that specifies the supported operations. This can be a bitwise combination of the following flags:

* XCN_NCRYPT_NO_OPERATION
* XCN_NCRYPT_CIPHER_OPERATION
* XCN_NCRYPT_HASH_OPERATION
* XCN_NCRYPT_ASYMMETRIC_ENCRYPTION_OPERATION
* XCN_NCRYPT_SECRET_AGREEMENT_OPERATION
* XCN_NCRYPT_SIGNATURE_OPERATION
* XCN_NCRYPT_RNG_OPERATION
* XCN_NCRYPT_ANY_ASYMMETRIC_OPERATION
* XCN_NCRYPT_PREFER_SIGNATURE_ONLY_OPERATION
* XCN_NCRYPT_PREFER_NON_SIGNATURE_OPERATION
* XCN_NCRYPT_EXACT_MATCH_OPERATION
* XCN_NCRYPT_PREFERENCE_MASK_OPERATION

### `pCspInformation` [in, optional]

Pointer to an [ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation) interface that represents information for a specific provider.

### `ppValue` [out]

Address of a variable that receives a pointer to an [ICspStatuses](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatuses) interface that contains the collection.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation)

[ICspInformations](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformations)