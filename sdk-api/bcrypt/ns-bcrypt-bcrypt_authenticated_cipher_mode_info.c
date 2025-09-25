typedef struct _BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO {
  ULONG     cbSize;
  ULONG     dwInfoVersion;
  PUCHAR    pbNonce;
  ULONG     cbNonce;
  PUCHAR    pbAuthData;
  ULONG     cbAuthData;
  PUCHAR    pbTag;
  ULONG     cbTag;
  PUCHAR    pbMacContext;
  ULONG     cbMacContext;
  ULONG     cbAAD;
  ULONGLONG cbData;
  ULONG     dwFlags;
} BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO, *PBCRYPT_AUTHENTICATED_CIPHER_MODE_INFO;