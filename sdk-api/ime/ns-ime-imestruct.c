typedef struct tagIMESTRUCT {
  UINT   fnc;
  WPARAM wParam;
  UINT   wCount;
  UINT   dchSource;
  UINT   dchDest;
  LPARAM lParam1;
  LPARAM lParam2;
  LPARAM lParam3;
} IMESTRUCT, *PIMESTRUCT, *NPIMESTRUCT, *LPIMESTRUCT;