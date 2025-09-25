# ICertSrvSetup::GetHashAlgorithmList

## Description

The **GetHashAlgorithmList** method gets the list of hash algorithms supported by the specified [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) for an asymmetric signature key algorithm. This method does not change the state of the **CCertSrvSetup** object.

## Parameters

### `bstrProviderName` [in]

A string that contains the provider name. For key storage providers, this must be in the form *PublicKeyAlgorithmName*#*KeyStorageProviderName* for example "RSA#Microsoft Software Key Storage provider".

### `pVal` [out]

A pointer to a **VARIANT** array of **VT_BSTR** types, where each string represents the name of a hash algorithm supported by the CSP.

## See also

[ICertSrvSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertsrvsetup)