typedef struct _CTL_FIND_USAGE_PARA {
  DWORD           cbSize;
  CTL_USAGE       SubjectUsage;
  CRYPT_DATA_BLOB ListIdentifier;
  PCERT_INFO      pSigner;
} CTL_FIND_USAGE_PARA, *PCTL_FIND_USAGE_PARA;