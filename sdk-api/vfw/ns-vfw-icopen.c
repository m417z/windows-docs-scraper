typedef struct {
  DWORD   dwSize;
  DWORD   fccType;
  DWORD   fccHandler;
  DWORD   dwVersion;
  DWORD   dwFlags;
  LRESULT dwError;
  LPVOID  pV1Reserved;
  LPVOID  pV2Reserved;
  DWORD   dnDevNode;
} ICOPEN;