# ICertSrvSetupKeyInformation::put_HashAlgorithm

## Description

The **HashAlgorithm** property gets or sets the name of the [hashing algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) used to sign or verify the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) certificate for the key.

This property is read/write.

## Parameters

## Remarks

The hashing algorithm must be supported by the [ProviderName](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertsrvsetupkeyinformation-get_providername) provider. For [cryptographic service providers](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSPs), get supported algorithms by calling the [CryptGetProvParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetprovparam) function for the given provider. For [key storage providers](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) (KSPs), get supported algorithms by calling the [BCryptEnumAlgorithms](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptenumalgorithms) function with the *dwAlgOperations* parameter set to **BCRYPT_HASH_OPERATION**. For information about algorithm identifiers, see [CNG Algorithm Identifiers](https://learn.microsoft.com/windows/desktop/SecCNG/cng-algorithm-identifiers).

#### Examples

For an example of enumerating supported algorithms by using [CryptGetProvParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetprovparam), see [Example C Program: Enumerating CSP Providers and Provider Types](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-enumerating-csp-providers-and-provider-types).

## See also

[ICertSrvSetupKeyInformation](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertsrvsetupkeyinformation)