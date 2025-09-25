typedef struct _PROPSHEETUI_INFO {
  WORD            cbSize;
  WORD            Version;
  WORD            Flags;
  WORD            Reason;
  HANDLE          hComPropSheet;
  PFNCOMPROPSHEET pfnComPropSheet;
  LPARAM          lParamInit;
  ULONG_PTR       UserData;
  ULONG_PTR       Result;
} PROPSHEETUI_INFO, *PPROPSHEETUI_INFO;