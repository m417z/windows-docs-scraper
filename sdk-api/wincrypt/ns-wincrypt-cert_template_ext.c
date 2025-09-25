typedef struct _CERT_TEMPLATE_EXT {
  LPSTR pszObjId;
  DWORD dwMajorVersion;
  BOOL  fMinorVersion;
  DWORD dwMinorVersion;
} CERT_TEMPLATE_EXT, *PCERT_TEMPLATE_EXT;