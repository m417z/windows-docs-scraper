typedef struct tagOLEUIBUSYA {
  DWORD         cbStruct;
  DWORD         dwFlags;
  HWND          hWndOwner;
  LPCSTR        lpszCaption;
  LPFNOLEUIHOOK lpfnHook;
  LPARAM        lCustData;
  HINSTANCE     hInstance;
  LPCSTR        lpszTemplate;
  HRSRC         hResource;
  HTASK         hTask;
  HWND          *lphWndDialog;
} OLEUIBUSYA, *POLEUIBUSYA, *LPOLEUIBUSYA;