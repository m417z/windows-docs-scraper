typedef struct _CERT_GENERAL_SUBTREE {
  CERT_ALT_NAME_ENTRY Base;
  DWORD               dwMinimum;
  BOOL                fMaximum;
  DWORD               dwMaximum;
} CERT_GENERAL_SUBTREE, *PCERT_GENERAL_SUBTREE;