typedef struct _CRYPTUI_WIZ_IMPORT_SUBJECT_INFO {
  DWORD   dwSize;
  DWORD   dwSubjectChoice;
  union {
    LPCWSTR        pwszFileName;
    PCCERT_CONTEXT pCertContext;
    PCCTL_CONTEXT  pCTLContext;
    PCCRL_CONTEXT  pCRLContext;
    HCERTSTORE     hCertStore;
  };
  DWORD   dwFlags;
  LPCWSTR pwszPassword;
} CRYPTUI_WIZ_IMPORT_SRC_INFO, *PCRYPTUI_WIZ_IMPORT_SRC_INFO;