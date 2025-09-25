SECURITY_STATUS NCryptUnprotectSecret(
  [out, optional] NCRYPT_DESCRIPTOR_HANDLE *phDescriptor,
  [in]            DWORD                    dwFlags,
  [in]            const BYTE               *pbProtectedBlob,
                  ULONG                    cbProtectedBlob,
  [in, optional]  const NCRYPT_ALLOC_PARA  *pMemPara,
  [in, optional]  HWND                     hWnd,
  [out]           BYTE                     **ppbData,
  [out]           ULONG                    *pcbData
);