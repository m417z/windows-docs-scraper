typedef struct tagOLEUIBUSYW {
  DWORD         cbStruct;
  DWORD         dwFlags;
  HWND          hWndOwner;
  LPCWSTR       lpszCaption;
  LPFNOLEUIHOOK lpfnHook;
  LPARAM        lCustData;
  HINSTANCE     hInstance;
  LPCWSTR       lpszTemplate;
  HRSRC         hResource;
  HTASK         hTask;
  HWND          *lphWndDialog;
} OLEUIBUSYW, *POLEUIBUSYW, *LPOLEUIBUSYW;