typedef struct tagCSSW {
  DWORD           dwSize;
  HWND            hwndParent;
  HINSTANCE       hInstance;
  LPCWSTR         pTemplateName;
  DWORD           dwFlags;
  LPCWSTR         szTitle;
  DWORD           cCertStore;
  HCERTSTORE      *arrayCertStore;
  LPCSTR          szPurposeOid;
  DWORD           cCertContext;
  PCCERT_CONTEXT  *arrayCertContext;
  LPARAM          lCustData;
  PFNCMHOOKPROC   pfnHook;
  PFNCMFILTERPROC pfnFilter;
  LPCWSTR         szHelpFileName;
  DWORD           dwHelpId;
  HCRYPTPROV      hprov;
} CERT_SELECT_STRUCT_W, *PCERT_SELECT_STRUCT_W;