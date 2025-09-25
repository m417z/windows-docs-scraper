typedef struct videohdr_tag {
  LPBYTE    lpData;
  DWORD     dwBufferLength;
  DWORD     dwBytesUsed;
  DWORD     dwTimeCaptured;
  DWORD_PTR dwUser;
  DWORD     dwFlags;
  DWORD_PTR dwReserved[4];
} VIDEOHDR, *PVIDEOHDR, *LPVIDEOHDR;