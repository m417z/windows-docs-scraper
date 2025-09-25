typedef struct _CTL_VERIFY_USAGE_PARA {
  DWORD           cbSize;
  CRYPT_DATA_BLOB ListIdentifier;
  DWORD           cCtlStore;
  HCERTSTORE      *rghCtlStore;
  DWORD           cSignerStore;
  HCERTSTORE      *rghSignerStore;
} CTL_VERIFY_USAGE_PARA, *PCTL_VERIFY_USAGE_PARA;