typedef struct IPSEC_SA0_ {
  IPSEC_SA_SPI         spi;
  IPSEC_TRANSFORM_TYPE saTransformType;
  union {
    IPSEC_SA_AUTH_INFORMATION0            *ahInformation;
    IPSEC_SA_AUTH_INFORMATION0            *espAuthInformation;
    IPSEC_SA_CIPHER_INFORMATION0          *espCipherInformation;
    IPSEC_SA_AUTH_AND_CIPHER_INFORMATION0 *espAuthAndCipherInformation;
    IPSEC_SA_AUTH_INFORMATION0            *espAuthFwInformation;
  };
} IPSEC_SA0;