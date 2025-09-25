typedef struct _CRYPT_INTERFACE_REG {
  ULONG dwInterface;
  ULONG dwFlags;
  ULONG cFunctions;
  PWSTR *rgpszFunctions;
} CRYPT_INTERFACE_REG, *PCRYPT_INTERFACE_REG;