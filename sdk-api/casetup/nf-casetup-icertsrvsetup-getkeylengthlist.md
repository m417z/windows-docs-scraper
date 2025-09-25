# ICertSrvSetup::GetKeyLengthList

## Description

The **GetKeyLengthList** method gets the list of [key lengths](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) supported by the specified [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP). This method does not change the state of the **CCertSrvSetup** object.

## Parameters

### `bstrProviderName` [in]

A string that contains the name of the provider. For key storage providers, this must be in the form *PublicKeyAlgorithmName*#*KeyStorageProviderName* for example "RSA#Microsoft Software Key Storage provider".

### `pVal` [out]

A pointer to a **VARIANT** array of **VT_UI4** types that correspond to the key lengths supported by the CSP.

## See also

[ICertSrvSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertsrvsetup)