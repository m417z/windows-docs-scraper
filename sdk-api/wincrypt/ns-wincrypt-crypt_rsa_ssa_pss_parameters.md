# CRYPT_RSA_SSA_PSS_PARAMETERS structure

## Description

The **CRYPT_RSA_SSA_PSS_PARAMETERS** structure contains the parameters for an RSA PKCS #1 v2.1 signature. This structure is used with the **PKCS_RSA_SSA_PSS_PARAMETERS** and **szOID_RSA_SSA_PSS** encoding types.

## Members

### `HashAlgorithm`

A [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that identifies the hash algorithm to use. If this is not set for encoding, the default algorithm is **szOID_OIWSEC_sha1**.

### `MaskGenAlgorithm`

A [CRYPT_MASK_GEN_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_mask_gen_algorithm) structure that identifies the mask generation function to use. If this is not set for encoding, the default algorithm is **szOID_RSA_MGF1** with the mask generation hash algorithm defaulting to the hash algorithm.

### `dwSaltLength`

The octet length of the salt. If this is not set for encoding, the default salt length is the length of the hash value.

### `dwTrailerField`

The trailer field number. If this is not set for encoding, the default is **PKCS_RSA_SSA_PSS_TRAILER_FIELD_BC**.