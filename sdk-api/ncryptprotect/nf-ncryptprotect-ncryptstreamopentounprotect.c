SECURITY_STATUS NCryptStreamOpenToUnprotect(
  [in]           NCRYPT_PROTECT_STREAM_INFO *pStreamInfo,
                 DWORD                      dwFlags,
  [in, optional] HWND                       hWnd,
  [out]          NCRYPT_STREAM_HANDLE       *phStream
);