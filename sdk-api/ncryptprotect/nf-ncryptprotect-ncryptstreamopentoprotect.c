SECURITY_STATUS NCryptStreamOpenToProtect(
  [in]           NCRYPT_DESCRIPTOR_HANDLE   hDescriptor,
                 DWORD                      dwFlags,
  [in, optional] HWND                       hWnd,
  [in]           NCRYPT_PROTECT_STREAM_INFO *pStreamInfo,
  [out]          NCRYPT_STREAM_HANDLE       *phStream
);