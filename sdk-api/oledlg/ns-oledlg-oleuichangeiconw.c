typedef struct tagOLEUICHANGEICONW {
  DWORD         cbStruct;
  DWORD         dwFlags;
  HWND          hWndOwner;
  LPCWSTR       lpszCaption;
  LPFNOLEUIHOOK lpfnHook;
  LPARAM        lCustData;
  HINSTANCE     hInstance;
  LPCWSTR       lpszTemplate;
  HRSRC         hResource;
  HGLOBAL       hMetaPict;
  CLSID         clsid;
  WCHAR         szIconExe[MAX_PATH];
  int           cchIconExe;
} OLEUICHANGEICONW, *POLEUICHANGEICONW, *LPOLEUICHANGEICONW;