typedef struct RILLINECONTROLINFO {
  DWORD cbSize;
  DWORD dwExecutor;
  BOOL  fPolarityIncluded;
  BOOL  fToggleMode;
  BOOL  fReversePolarity;
  DWORD dwPowerDenialTime;
} RILLINECONTROLINFO, *LPRILLINECONTROLINFO;