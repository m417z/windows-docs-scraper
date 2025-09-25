typedef struct {
  LPCWSTR szReader;
  LPVOID  pvUserData;
  DWORD   dwCurrentState;
  DWORD   dwEventState;
  DWORD   cbAtr;
  BYTE    rgbAtr[36];
} SCARD_READERSTATEW, *PSCARD_READERSTATEW, *LPSCARD_READERSTATEW;