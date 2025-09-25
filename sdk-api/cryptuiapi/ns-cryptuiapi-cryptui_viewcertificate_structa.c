typedef struct tagCRYPTUI_VIEWCERTIFICATE_STRUCTA {
  DWORD             dwSize;
  HWND              hwndParent;
  DWORD             dwFlags;
  LPCSTR            szTitle;
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
  LPCPROPSHEETPAGEA rgPropSheetPages;
  DWORD             nStartPage;
} CRYPTUI_VIEWCERTIFICATE_STRUCTA, *PCRYPTUI_VIEWCERTIFICATE_STRUCTA;