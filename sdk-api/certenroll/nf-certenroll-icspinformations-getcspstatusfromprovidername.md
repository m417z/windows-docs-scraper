# ICspInformations::GetCspStatusFromProviderName

## Description

The **GetCspStatusFromProviderName** method retrieves an [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) object for a legacy provider by provider name and supported key operations. This method is web enabled.

## Parameters

### `strProviderName` [in]

A **BSTR** that contains the cryptographic provider name or the provider and algorithm names separated by a comma in the format *algorithm_name, provider_name*.

### `LegacyKeySpec` [in]

An [X509KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509keyspec) enumeration value that specifies whether a key can be used for encryption, signing, or both. This can be one of the following values:

* XCN_AT_KEYEXCHANGE
* XCN_AT_SIGNATURE

### `ppValue` [out]

Address of a variable that receives a pointer to an [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) interface that contains information about a cryptographic provider and algorithm pair that satisfies the *strProviderName* and *LegacyKeySpec* parameter values.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation)

[ICspInformations](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformations)