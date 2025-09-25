# ICertSrvSetupKeyInformation::put_ProviderName

## Description

The **ProviderName** property gets or sets the name of the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) or [key storage provider](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) (KSP) that is used to generate or store the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

This property is read/write.

## Parameters

## Remarks

For a KSP, the **ProviderName** property value must be formatted as *PublicKeyAlgorithmName*, number sign (#), and *KeyStorageProviderName*, for example "RSA#Microsoft Software Key Storage Provider" or "ECDSA_P256#Microsoft Software Key Storage Provider". The [public key algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) must be supported by the provider. To get supported algorithms, call the [NCryptEnumAlgorithms](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptenumalgorithms) function with the *dwAlgOperations* parameter set to **NCRYPT_SIGNATURE_OPERATION**. For information about algorithm identifiers, see [CNG Algorithm Identifiers](https://learn.microsoft.com/windows/desktop/SecCNG/cng-algorithm-identifiers).

## See also

[ICertSrvSetupKeyInformation](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertsrvsetupkeyinformation)