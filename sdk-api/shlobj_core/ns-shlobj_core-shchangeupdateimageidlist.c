typedef struct _SHChangeUpdateImageIDList {
  USHORT cb;
  int    iIconIndex;
  int    iCurIndex;
  UINT   uFlags;
  DWORD  dwProcessID;
  WCHAR  szName[MAX_PATH];
  USHORT cbZero;
} SHChangeUpdateImageIDList, *LPSHChangeUpdateImageIDList;