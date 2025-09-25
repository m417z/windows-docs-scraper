typedef struct tagSERIALKEYSA {
  UINT  cbSize;
  DWORD dwFlags;
  LPSTR lpszActivePort;
  LPSTR lpszPort;
  UINT  iBaudRate;
  UINT  iPortState;
  UINT  iActive;
} SERIALKEYSA, *LPSERIALKEYSA;