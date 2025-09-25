typedef struct {
  LPCSTR szReader;
  LPVOID pvUserData;
  DWORD  dwCurrentState;
  DWORD  dwEventState;
  DWORD  cbAtr;
  BYTE   rgbAtr[36];
} SCARD_READERSTATEA, *PSCARD_READERSTATEA, *LPSCARD_READERSTATEA;