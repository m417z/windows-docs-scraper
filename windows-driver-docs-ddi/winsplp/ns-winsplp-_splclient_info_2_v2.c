typedef struct _SPLCLIENT_INFO_2_V2 {
#if ...
  DWORD64 hSplPrinter;
#else
  DWORD32 hSplPrinter;
#endif
} SPLCLIENT_INFO_2_WINXP;