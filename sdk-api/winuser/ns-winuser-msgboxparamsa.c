typedef struct tagMSGBOXPARAMSA {
  UINT           cbSize;
  HWND           hwndOwner;
  HINSTANCE      hInstance;
  LPCSTR         lpszText;
  LPCSTR         lpszCaption;
  DWORD          dwStyle;
  LPCSTR         lpszIcon;
  DWORD_PTR      dwContextHelpId;
  MSGBOXCALLBACK lpfnMsgBoxCallback;
  DWORD          dwLanguageId;
} MSGBOXPARAMSA, *PMSGBOXPARAMSA, *LPMSGBOXPARAMSA;