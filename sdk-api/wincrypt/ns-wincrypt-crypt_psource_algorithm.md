# CRYPT_PSOURCE_ALGORITHM structure

## Description

The **CRYPT_PSOURCE_ALGORITHM** structure identifies the algorithm and (optionally) the value of the label for an RSAES-OAEP key encryption.

## Members

### `pszObjId`

The address of a null-terminated ANSI string that contains the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) of the algorithm. This can be the following value or any other mask generation function OID.

| Value | Meaning |
| --- | --- |
| **szOID_RSA_PSPECIFIED**<br><br>"1.2.840.113549.1.1.9" | The RSAES-OAEP label function. |

### `EncodingParameters`

A [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) that contains the label. This member is optional and may contain an empty BLOB.

## See also

[CRYPT_RSAES_OAEP_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_rsaes_oaep_parameters)