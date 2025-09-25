typedef struct tagACCEL {
#if ...
  BYTE  fVirt;
#if ...
  WORD  key;
#if ...
  WORD  cmd;
#else
  WORD  fVirt;
#endif
#else
  WORD  key;
#endif
#else
  DWORD cmd;
#endif
} ACCEL, *LPACCEL;