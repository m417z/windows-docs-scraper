typedef struct _CRYPTUI_WIZ_EXPORT_INFO {
  DWORD      dwSize;
  LPCWSTR    pwszExportFileName;
  DWORD      dwSubjectChoice;
  union {
    PCCERT_CONTEXT pCertContext;
    PCCTL_CONTEXT  pCTLContext;
    PCCRL_CONTEXT  pCRLContext;
    HCERTSTORE     hCertStore;
  };
  DWORD      cStores;
  HCERTSTORE *rghStores;
} CRYPTUI_WIZ_EXPORT_INFO, *PCRYPTUI_WIZ_EXPORT_INFO;