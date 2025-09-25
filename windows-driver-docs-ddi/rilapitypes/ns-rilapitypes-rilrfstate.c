typedef struct RILRFSTATE {
  DWORD cbSize;
  DWORD dwParams;
  DWORD dwRFState;
  DWORD dwRFDataSize;
  BYTE  bRFData[1];
} RILRFSTATE, *LPRILRFSTATE;