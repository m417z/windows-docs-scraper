# ICspInformations::GetEncryptionCspAlgorithms

## Description

The **GetEncryptionCspAlgorithms** method retrieves the collection of encryption algorithms supported by a provider.

## Parameters

### `pCspInformation` [in, optional]

Pointer to an [ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation) interface that represents the provider. This can be a legacy cryptographic service provider (CSP), a Cryptography API: Next Generation (CNG) provider, or **NULL**. If you specify **NULL**, this method returns the collection of all encryption algorithms supported by all CSPs and CNG providers.

### `ppValue` [out]

Address of a variable that receives a pointer to an [ICspAlgorithms](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspalgorithms) interface that represents the collection.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation)

[ICspInformations](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformations)