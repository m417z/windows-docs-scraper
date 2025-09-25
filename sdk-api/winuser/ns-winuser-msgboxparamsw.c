typedef struct tagMSGBOXPARAMSW {
  UINT           cbSize;
  HWND           hwndOwner;
  HINSTANCE      hInstance;
  LPCWSTR        lpszText;
  LPCWSTR        lpszCaption;
  DWORD          dwStyle;
  LPCWSTR        lpszIcon;
  DWORD_PTR      dwContextHelpId;
  MSGBOXCALLBACK lpfnMsgBoxCallback;
  DWORD          dwLanguageId;
} MSGBOXPARAMSW, *PMSGBOXPARAMSW, *LPMSGBOXPARAMSW;