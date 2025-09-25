# CRYPT_RSAES_OAEP_PARAMETERS structure

## Description

The **CRYPT_RSAES_OAEP_PARAMETERS** structure contains the parameters for an RSAES-OAEP key encryption. This structure is used with the **PKCS_RSAES_OAEP_PARAMETERS** and **szOID_RSAES_OAEP** encoding types.

## Members

### `HashAlgorithm`

A [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that identifies the hash algorithm to use. If this is not set for encoding, the default algorithm is **szOID_OIWSEC_sha1**.

### `MaskGenAlgorithm`

A [CRYPT_MASK_GEN_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_mask_gen_algorithm) structure that identifies the mask generation function to use. If this is not set for encoding, the default algorithm is **szOID_RSA_MGF1** with the mask generation hash algorithm defaulting to the algorithm specified by the **HashAlgorithm** member.

### `PSourceAlgorithm`

A [CRYPT_PSOURCE_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_psource_algorithm) structure that contains the source of, and possibly the value of, the label to be used. If this is not set for encoding, the default algorithm is **szOID_RSA_PSPECIFIED** with no OCTET bytes.

## Remarks

RSAES-OAEP is normally used for encrypting AES symmetric keys. Normally, only the hash algorithm [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) will need to be set for encoding. For decoding, all the members are explicitly set.