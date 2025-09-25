typedef struct _ads_class_def {
  LPWSTR pszClassName;
  DWORD  dwMandatoryAttrs;
  LPWSTR *ppszMandatoryAttrs;
  DWORD  optionalAttrs;
  LPWSTR **ppszOptionalAttrs;
  DWORD  dwNamingAttrs;
  LPWSTR **ppszNamingAttrs;
  DWORD  dwSuperClasses;
  LPWSTR **ppszSuperClasses;
  BOOL   fIsContainer;
} ADS_CLASS_DEF, *PADS_CLASS_DEF;