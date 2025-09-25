typedef struct tagGESTUREINFO {
  UINT      cbSize;
  DWORD     dwFlags;
  DWORD     dwID;
  HWND      hwndTarget;
  POINTS    ptsLocation;
  DWORD     dwInstanceID;
  DWORD     dwSequenceID;
  ULONGLONG ullArguments;
  UINT      cbExtraArgs;
} GESTUREINFO, *PGESTUREINFO;