typedef struct _CRYPT_PROVIDER_REG {
  ULONG            cAliases;
  PWSTR            *rgpszAliases;
  PCRYPT_IMAGE_REG pUM;
  PCRYPT_IMAGE_REG pKM;
} CRYPT_PROVIDER_REG, *PCRYPT_PROVIDER_REG;