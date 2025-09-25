SECURITY_STATUS NCryptStreamOpenToUnprotectEx(
  [in]           NCRYPT_PROTECT_STREAM_INFO_EX *pStreamInfo,
                 DWORD                         dwFlags,
  [in, optional] HWND                          hWnd,
  [out]          NCRYPT_STREAM_HANDLE          *phStream
);