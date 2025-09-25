typedef struct RILREMOTEPARTYINFO {
  DWORD                   cbSize;
  DWORD                   dwParams;
  DWORD                   dwExecutor;
  RILADDRESS              raAddress;
  RILSUBADDRESS           rsaSubAddress;
  WCHAR                   wszDescription[256];
  RILREMOTEPARTYINFOVALUE dwNumberPresentationIndicator;
  RILREMOTEPARTYINFOVALUE dwNamePresentationIndicator;
  DWORD                   dwID;
} RILREMOTEPARTYINFO, *LPRILREMOTEPARTYINFO;