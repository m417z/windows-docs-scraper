typedef struct _CRYPT_PROVIDER_REF {
  ULONG               dwInterface;
  PWSTR               pszFunction;
  PWSTR               pszProvider;
  ULONG               cProperties;
  PCRYPT_PROPERTY_REF *rgpProperties;
  PCRYPT_IMAGE_REF    pUM;
  PCRYPT_IMAGE_REF    pKM;
} CRYPT_PROVIDER_REF, *PCRYPT_PROVIDER_REF;