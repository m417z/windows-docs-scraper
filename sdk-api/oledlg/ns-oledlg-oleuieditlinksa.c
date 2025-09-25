typedef struct tagOLEUIEDITLINKSA {
  DWORD                 cbStruct;
  DWORD                 dwFlags;
  HWND                  hWndOwner;
  LPCSTR                lpszCaption;
  LPFNOLEUIHOOK         lpfnHook;
  LPARAM                lCustData;
  HINSTANCE             hInstance;
  LPCSTR                lpszTemplate;
  HRSRC                 hResource;
  LPOLEUILINKCONTAINERA lpOleUILinkContainer;
} OLEUIEDITLINKSA, *POLEUIEDITLINKSA, *LPOLEUIEDITLINKSA;