typedef struct tagOLEUICHANGESOURCEA {
  DWORD                 cbStruct;
  DWORD                 dwFlags;
  HWND                  hWndOwner;
  LPCSTR                lpszCaption;
  LPFNOLEUIHOOK         lpfnHook;
  LPARAM                lCustData;
  HINSTANCE             hInstance;
  LPCSTR                lpszTemplate;
  HRSRC                 hResource;
  OPENFILENAMEA         *lpOFN;
  DWORD                 dwReserved1[4];
  LPOLEUILINKCONTAINERA lpOleUILinkContainer;
  DWORD                 dwLink;
  LPSTR                 lpszDisplayName;
  ULONG                 nFileLength;
  LPSTR                 lpszFrom;
  LPSTR                 lpszTo;
} OLEUICHANGESOURCEA, *POLEUICHANGESOURCEA, *LPOLEUICHANGESOURCEA;