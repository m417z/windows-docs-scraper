typedef struct tagMOUSEMOVEPOINT {
  int       x;
  int       y;
  DWORD     time;
  ULONG_PTR dwExtraInfo;
} MOUSEMOVEPOINT, *PMOUSEMOVEPOINT, *LPMOUSEMOVEPOINT;