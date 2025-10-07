typedef struct _BCRYPT_PQDSA_PADDING_INFO {
  PUCHAR    pbCtx;
  ULONG     cbCtx;
  LPCWSTR   pszPrehashAlgId;
} BCRYPT_PQDSA_PADDING_INFO;