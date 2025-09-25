typedef struct tagSERIALKEYSW {
  UINT   cbSize;
  DWORD  dwFlags;
  LPWSTR lpszActivePort;
  LPWSTR lpszPort;
  UINT   iBaudRate;
  UINT   iPortState;
  UINT   iActive;
} SERIALKEYSW, *LPSERIALKEYSW;