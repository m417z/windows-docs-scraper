# ICspStatus::get_DisplayName

## Description

The **DisplayName** property retrieves a string that contains the name of the provider, the algorithm name, and the operations that can be performed by the algorithm.

This property is read-only.

## Parameters

## Remarks

The format of the string returned by this property depends on whether the provider is a CryptoAPI [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) or a Cryptography API: Next Generation (CNG) provider.

* The format of the string for a CSP is *ProviderName(KeyType)* where *KeyType* is either "Signature" or "Encryption".
* The format of the string for a CNG provider is *AlgorithmName,ProviderName* where *AlgorithmName* can be "Unknown Algorithm".

## See also

[ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus)

[ICspStatuses](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatuses)