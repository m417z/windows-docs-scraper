typedef struct tagOLEUICHANGESOURCEW {
  DWORD                 cbStruct;
  DWORD                 dwFlags;
  HWND                  hWndOwner;
  LPCWSTR               lpszCaption;
  LPFNOLEUIHOOK         lpfnHook;
  LPARAM                lCustData;
  HINSTANCE             hInstance;
  LPCWSTR               lpszTemplate;
  HRSRC                 hResource;
  OPENFILENAMEW         *lpOFN;
  DWORD                 dwReserved1[4];
  LPOLEUILINKCONTAINERW lpOleUILinkContainer;
  DWORD                 dwLink;
  LPWSTR                lpszDisplayName;
  ULONG                 nFileLength;
  LPWSTR                lpszFrom;
  LPWSTR                lpszTo;
} OLEUICHANGESOURCEW, *POLEUICHANGESOURCEW, *LPOLEUICHANGESOURCEW;