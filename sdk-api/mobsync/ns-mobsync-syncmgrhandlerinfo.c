typedef struct _tagSYNCMGRHANDLERINFO {
  DWORD cbSize;
  HICON hIcon;
  DWORD SyncMgrHandlerFlags;
  WCHAR wszHandlerName[32];
} SYNCMGRHANDLERINFO, *LPSYNCMGRHANDLERINFO;