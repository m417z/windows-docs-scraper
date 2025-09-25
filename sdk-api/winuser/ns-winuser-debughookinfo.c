typedef struct tagDEBUGHOOKINFO {
  DWORD  idThread;
  DWORD  idThreadInstaller;
  LPARAM lParam;
  WPARAM wParam;
  int    code;
} DEBUGHOOKINFO, *PDEBUGHOOKINFO, *NPDEBUGHOOKINFO, *LPDEBUGHOOKINFO;