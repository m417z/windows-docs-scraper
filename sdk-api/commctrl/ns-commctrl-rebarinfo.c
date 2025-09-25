typedef struct tagREBARINFO {
  UINT       cbSize;
  UINT       fMask;
#if ...
  HIMAGELIST himl;
#else
  HANDLE     himl;
#endif
} REBARINFO, *LPREBARINFO;