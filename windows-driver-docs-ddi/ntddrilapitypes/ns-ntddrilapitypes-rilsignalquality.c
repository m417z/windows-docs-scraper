typedef struct RILSIGNALQUALITY {
  DWORD cbSize;
  DWORD dwParams;
  DWORD dwExecutor;
  DWORD dwSystemType;
  int   nNumSignalBars;
  int   nSignalStrength;
  int   nSNRStrength;
} RILSIGNALQUALITY, *LPRILSIGNALQUALITY;