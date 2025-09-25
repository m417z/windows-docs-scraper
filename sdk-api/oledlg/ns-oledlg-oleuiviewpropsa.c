typedef struct tagOLEUIVIEWPROPSA {
  DWORD                       cbStruct;
  DWORD                       dwFlags;
  DWORD                       dwReserved1[2];
  LPFNOLEUIHOOK               lpfnHook;
  LPARAM                      lCustData;
  DWORD                       dwReserved2[3];
  struct tagOLEUIOBJECTPROPSA *lpOP;
  int                         nScaleMin;
  int                         nScaleMax;
} OLEUIVIEWPROPSA, *POLEUIVIEWPROPSA, *LPOLEUIVIEWPROPSA;