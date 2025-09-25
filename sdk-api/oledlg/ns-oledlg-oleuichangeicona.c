typedef struct tagOLEUICHANGEICONA {
  DWORD         cbStruct;
  DWORD         dwFlags;
  HWND          hWndOwner;
  LPCSTR        lpszCaption;
  LPFNOLEUIHOOK lpfnHook;
  LPARAM        lCustData;
  HINSTANCE     hInstance;
  LPCSTR        lpszTemplate;
  HRSRC         hResource;
  HGLOBAL       hMetaPict;
  CLSID         clsid;
  CHAR          szIconExe[MAX_PATH];
  int           cchIconExe;
} OLEUICHANGEICONA, *POLEUICHANGEICONA, *LPOLEUICHANGEICONA;