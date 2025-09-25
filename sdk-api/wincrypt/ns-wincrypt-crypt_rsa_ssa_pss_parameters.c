typedef struct _CRYPT_RSA_SSA_PSS_PARAMETERS {
  CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
  CRYPT_MASK_GEN_ALGORITHM   MaskGenAlgorithm;
  DWORD                      dwSaltLength;
  DWORD                      dwTrailerField;
} CRYPT_RSA_SSA_PSS_PARAMETERS, *PCRYPT_RSA_SSA_PSS_PARAMETERS;