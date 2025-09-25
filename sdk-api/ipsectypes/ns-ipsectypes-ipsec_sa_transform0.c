typedef struct IPSEC_SA_TRANSFORM0_ {
  IPSEC_TRANSFORM_TYPE ipsecTransformType;
  union {
    IPSEC_AUTH_TRANSFORM0            *ahTransform;
    IPSEC_AUTH_TRANSFORM0            *espAuthTransform;
    IPSEC_CIPHER_TRANSFORM0          *espCipherTransform;
    IPSEC_AUTH_AND_CIPHER_TRANSFORM0 *espAuthAndCipherTransform;
    IPSEC_AUTH_TRANSFORM0            *espAuthFwTransform;
  };
} IPSEC_SA_TRANSFORM0;