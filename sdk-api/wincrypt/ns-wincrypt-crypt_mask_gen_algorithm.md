# CRYPT_MASK_GEN_ALGORITHM structure

## Description

The **CRYPT_MASK_GEN_ALGORITHM** structure identifies the algorithm used to generate an RSA PKCS #1 v2.1 signature mask.

## Members

### `pszObjId`

The address of a null-terminated ANSI string that contains the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) of the mask generation algorithm. This can be the following value or any other mask generation function OID.

| Value | Meaning |
| --- | --- |
| **szOID_RSA_MGF1**<br><br>"1.2.840.113549.1.1.8" | The RSA MGF1 function. |

### `HashAlgorithm`

A [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that identifies the hash algorithm to use for the mask generation.

## See also

[CRYPT_RSAES_OAEP_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_rsaes_oaep_parameters)

[CRYPT_RSA_SSA_PSS_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_rsa_ssa_pss_parameters)