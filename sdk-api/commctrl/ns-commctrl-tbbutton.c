typedef struct _TBBUTTON {
  int       iBitmap;
  int       idCommand;
  BYTE      fsState;
  BYTE      fsStyle;
#if ...
  BYTE      bReserved[6];
#else
  BYTE      bReserved[2];
#endif
  DWORD_PTR dwData;
  INT_PTR   iString;
} TBBUTTON, *PTBBUTTON, *LPTBBUTTON;