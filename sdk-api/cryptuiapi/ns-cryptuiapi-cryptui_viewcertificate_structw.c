typedef struct tagCRYPTUI_VIEWCERTIFICATE_STRUCTW {
  DWORD             dwSize;
  HWND              hwndParent;
  DWORD             dwFlags;
  LPCWSTR           szTitle;
  PCCERT_CONTEXT    pCertContext;
  LPCSTR            *rgszPurposes;
  DWORD             cPurposes;
  union {
    CRYPT_PROVIDER_DATA const *pCryptProviderData;
    HANDLE                    hWVTStateData;
  };
  BOOL              fpCryptProviderDataTrustedUsage;
  DWORD             idxSigner;
  DWORD             idxCert;
  BOOL              fCounterSigner;
  DWORD             idxCounterSigner;
  DWORD             cStores;
  HCERTSTORE        *rghStores;
  DWORD             cPropSheetPages;
  LPCPROPSHEETPAGEW rgPropSheetPages;
  DWORD             nStartPage;
} CRYPTUI_VIEWCERTIFICATE_STRUCTW, *PCRYPTUI_VIEWCERTIFICATE_STRUCTW;