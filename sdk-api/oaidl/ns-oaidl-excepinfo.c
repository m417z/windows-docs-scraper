typedef struct tagEXCEPINFO {
  WORD      wCode;
  WORD      wReserved;
  BSTR      bstrSource;
  BSTR      bstrDescription;
  BSTR      bstrHelpFile;
  DWORD     dwHelpContext;
  ULONG_PTR pvReserved;
  ULONG_PTR pfnDeferredFillIn;
  SCODE     scode;
} EXCEPINFO, *LPEXCEPINFO;