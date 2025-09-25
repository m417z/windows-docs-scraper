typedef struct _SecPkgContext_CredInfo {
  SECPKG_CRED_CLASS CredClass;
  unsigned long     IsPromptingNeeded;
} SecPkgContext_CredInfo, *PSecPkgContext_CredInfo;