# ICertSrvSetup::GetPrivateKeyContainerList

## Description

The **GetPrivateKeyContainerList** method gets the list of [key container](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) names stored by the specified [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) for asymmetric signature key algorithms. This method does not change the state of the **CCertSrvSetup** object.

## Parameters

### `bstrProviderName` [in]

A string that contains the name of the provider. For key storage providers, this must be in the form *PublicKeyAlgorithmName*#*KeyStorageProviderName* for example "RSA#Microsoft Software Key Storage provider".

### `pVal` [out]

A pointer to a **VARIANT** array of **VT_BSTR** types, where each string represents the name of a key container used by the specified CSP.

## See also

[ICertSrvSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertsrvsetup)