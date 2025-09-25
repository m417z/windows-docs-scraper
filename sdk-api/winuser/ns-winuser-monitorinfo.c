typedef struct tagMONITORINFO {
  DWORD cbSize;
  RECT  rcMonitor;
  RECT  rcWork;
  DWORD dwFlags;
} MONITORINFO, *LPMONITORINFO;