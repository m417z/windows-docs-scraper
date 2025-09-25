typedef struct _INTERNET_BUFFERSA {
  DWORD                     dwStructSize;
  struct _INTERNET_BUFFERSA *Next;
  LPCSTR                    lpcszHeader;
  DWORD                     dwHeadersLength;
  DWORD                     dwHeadersTotal;
  LPVOID                    lpvBuffer;
  DWORD                     dwBufferLength;
  DWORD                     dwBufferTotal;
  DWORD                     dwOffsetLow;
  DWORD                     dwOffsetHigh;
} INTERNET_BUFFERSA, *LPINTERNET_BUFFERSA;