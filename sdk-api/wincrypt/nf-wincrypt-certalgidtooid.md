# CertAlgIdToOID function

## Description

Use the [CryptFindOIDInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptfindoidinfo) function instead of this function because [ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id) identifiers are no longer supported in CNG. Use the **CRYPT_OID_INFO_CNG_ALGID_KEY** value in the *dwKeyType* parameter of the [CryptFindOIDInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptfindoidinfo) function instead.

**Windows Server 2003 and Windows XP:** The **CertAlgIdToOID** function converts a [CryptoAPI](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) algorithm identifier ([ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id)) to an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) string.

## Parameters

### `dwAlgId` [in]

Value to be converted to an OID.

## Return value

If the function succeeds, the function returns the null-terminated OID string.

If no OID string corresponds to the algorithm identifier, the function returns **NULL**.

## See also

[Data Conversion Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)