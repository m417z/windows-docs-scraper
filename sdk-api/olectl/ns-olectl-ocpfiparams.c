typedef struct tagOCPFIPARAMS {
  ULONG     cbStructSize;
  HWND      hWndOwner;
  int       x;
  int       y;
  LPCOLESTR lpszCaption;
  ULONG     cObjects;
  LPUNKNOWN *lplpUnk;
  ULONG     cPages;
  CLSID     *lpPages;
  LCID      lcid;
  DISPID    dispidInitialProperty;
} OCPFIPARAMS, *LPOCPFIPARAMS;