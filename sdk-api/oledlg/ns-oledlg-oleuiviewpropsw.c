typedef struct tagOLEUIVIEWPROPSW {
  DWORD                       cbStruct;
  DWORD                       dwFlags;
  DWORD                       dwReserved1[2];
  LPFNOLEUIHOOK               lpfnHook;
  LPARAM                      lCustData;
  DWORD                       dwReserved2[3];
  struct tagOLEUIOBJECTPROPSW *lpOP;
  int                         nScaleMin;
  int                         nScaleMax;
} OLEUIVIEWPROPSW, *POLEUIVIEWPROPSW, *LPOLEUIVIEWPROPSW;