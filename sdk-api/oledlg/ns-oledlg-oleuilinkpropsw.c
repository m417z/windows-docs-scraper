typedef struct tagOLEUILINKPROPSW {
  DWORD                       cbStruct;
  DWORD                       dwFlags;
  DWORD                       dwReserved1[2];
  LPFNOLEUIHOOK               lpfnHook;
  LPARAM                      lCustData;
  DWORD                       dwReserved2[3];
  struct tagOLEUIOBJECTPROPSW *lpOP;
} OLEUILINKPROPSW, *POLEUILINKPROPSW, *LPOLEUILINKPROPSW;