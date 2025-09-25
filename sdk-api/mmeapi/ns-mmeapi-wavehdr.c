typedef struct wavehdr_tag {
  LPSTR              lpData;
  DWORD              dwBufferLength;
  DWORD              dwBytesRecorded;
  DWORD_PTR          dwUser;
  DWORD              dwFlags;
  DWORD              dwLoops;
  struct wavehdr_tag *lpNext;
  DWORD_PTR          reserved;
} WAVEHDR, *PWAVEHDR, *NPWAVEHDR, *LPWAVEHDR;