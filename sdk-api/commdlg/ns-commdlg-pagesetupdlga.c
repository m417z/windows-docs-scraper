typedef struct tagPSDA {
  DWORD           lStructSize;
  HWND            hwndOwner;
  HGLOBAL         hDevMode;
  HGLOBAL         hDevNames;
  DWORD           Flags;
  POINT           ptPaperSize;
  RECT            rtMinMargin;
  RECT            rtMargin;
  HINSTANCE       hInstance;
  LPARAM          lCustData;
  LPPAGESETUPHOOK lpfnPageSetupHook;
  LPPAGEPAINTHOOK lpfnPagePaintHook;
  LPCSTR          lpPageSetupTemplateName;
  HGLOBAL         hPageSetupTemplate;
} PAGESETUPDLGA, *LPPAGESETUPDLGA;