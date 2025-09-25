typedef struct _CTL_VERIFY_USAGE_STATUS {
  DWORD          cbSize;
  DWORD          dwError;
  DWORD          dwFlags;
  PCCTL_CONTEXT  *ppCtl;
  DWORD          dwCtlEntryIndex;
  PCCERT_CONTEXT *ppSigner;
  DWORD          dwSignerIndex;
} CTL_VERIFY_USAGE_STATUS, *PCTL_VERIFY_USAGE_STATUS;