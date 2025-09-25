DWORD EapPeerGetIdentity(
  [in]      DWORD      dwFlags,
  [in]      DWORD      dwSizeofConnectionData,
  [in]      const BYTE *pConnectionData,
  [in]      DWORD      dwSizeofUserData,
  [in]      const BYTE *pUserData,
  [in]      HANDLE     hTokenImpersonateUser,
  [out]     BOOL       *pfInvokeUI,
  [in, out] DWORD      *pdwSizeOfUserDataOut,
  [out]     BYTE       **ppUserDataOut,
  [out]     LPWSTR     *ppwszIdentity,
  [out]     EAP_ERROR  **ppEapError
);