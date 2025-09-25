# SecPkgContext_KeyInfoW structure

## Description

The **SecPkgContext_KeyInfo** structure contains information about the [session keys](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) used in a [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). The
[QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa) function uses this structure.

Applications using the Schannel [security support provider](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSP) should not use the **SecPkgContext_KeyInfo** structure. Instead, use the [SecPkgContext_ConnectionInfo](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-secpkgcontext_connectioninfo) structure.

## Members

### `sSignatureAlgorithmName`

Pointer to a null-terminated string that contains the name, if available, of the algorithm used for generating signatures, for example "MD5" or "SHA-2".

### `sEncryptAlgorithmName`

Pointer to a null-terminated string that contains the name, if available, of the algorithm used for encrypting messages. Reserved for future use.

### `KeySize`

Specifies the effective key length, in bits, for the session key. This is typically 40, 56, or 128 bits.

### `SignatureAlgorithm`

Specifies the algorithm identifier ([ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id)) used for generating signatures, if available.

### `EncryptAlgorithm`

Specifies the algorithm identifier ([ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id)) used for encrypting messages. Reserved for future use.

## See also

[QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa)

## Remarks

> [!NOTE]
> The sspi.h header defines SecPkgContext_KeyInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).