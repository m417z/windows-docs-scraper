typedef struct tagCSSA {
  DWORD           dwSize;
  HWND            hwndParent;
  HINSTANCE       hInstance;
  LPCSTR          pTemplateName;
  DWORD           dwFlags;
  LPCSTR          szTitle;
  DWORD           cCertStore;
  HCERTSTORE      *arrayCertStore;
  LPCSTR          szPurposeOid;
  DWORD           cCertContext;
  PCCERT_CONTEXT  *arrayCertContext;
  LPARAM          lCustData;
  PFNCMHOOKPROC   pfnHook;
  PFNCMFILTERPROC pfnFilter;
  LPCSTR          szHelpFileName;
  DWORD           dwHelpId;
  HCRYPTPROV      hprov;
} CERT_SELECT_STRUCT_A, *PCERT_SELECT_STRUCT_A;