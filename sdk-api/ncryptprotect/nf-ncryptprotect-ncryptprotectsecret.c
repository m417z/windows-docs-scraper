SECURITY_STATUS NCryptProtectSecret(
  [in]           NCRYPT_DESCRIPTOR_HANDLE hDescriptor,
  [in]           DWORD                    dwFlags,
  [in]           const BYTE               *pbData,
  [in]           ULONG                    cbData,
  [in, optional] const NCRYPT_ALLOC_PARA  *pMemPara,
  [in, optional] HWND                     hWnd,
  [out]          BYTE                     **ppbProtectedBlob,
  [out]          ULONG                    *pcbProtectedBlob
);