typedef struct _CRYPT_IMAGE_REG {
  PWSTR                pszImage;
  ULONG                cInterfaces;
  PCRYPT_INTERFACE_REG *rgpInterfaces;
} CRYPT_IMAGE_REG, *PCRYPT_IMAGE_REG;