typedef struct tagOLEUIEDITLINKSW {
  DWORD                 cbStruct;
  DWORD                 dwFlags;
  HWND                  hWndOwner;
  LPCWSTR               lpszCaption;
  LPFNOLEUIHOOK         lpfnHook;
  LPARAM                lCustData;
  HINSTANCE             hInstance;
  LPCWSTR               lpszTemplate;
  HRSRC                 hResource;
  LPOLEUILINKCONTAINERW lpOleUILinkContainer;
} OLEUIEDITLINKSW, *POLEUIEDITLINKSW, *LPOLEUIEDITLINKSW;