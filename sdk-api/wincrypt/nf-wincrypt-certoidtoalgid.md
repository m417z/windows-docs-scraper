# CertOIDToAlgId function

## Description

Use the [CryptFindOIDInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptfindoidinfo) function instead of this function because [ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id) identifiers are no longer supported in CNG. Use the **CRYPT_OID_INFO_OID_KEY** value in the *dwKeyType* parameter of the [CryptFindOIDInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptfindoidinfo) function instead.

**Windows Server 2003 and Windows XP:** The **CertOIDToAlgId** function converts the [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) string to the CryptoAPI algorithm identifier ([ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id)).

## Parameters

### `pszObjId` [in]

Pointer to the ASN.1 OID to be converted to an algorithm identifier.

## Return value

Returns the
[ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id) that corresponds to the object identifier (OID) or zero if no **ALG_ID** corresponds to the OID.

## See also

[Data Conversion Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)