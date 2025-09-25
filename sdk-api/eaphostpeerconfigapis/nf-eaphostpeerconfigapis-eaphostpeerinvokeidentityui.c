DWORD EapHostPeerInvokeIdentityUI(
  [in]      DWORD           dwVersion,
  [in]      EAP_METHOD_TYPE eapMethodType,
  [in]      DWORD           dwFlags,
  [in]      HWND            hwndParent,
  [in]      DWORD           dwSizeofConnectionData,
  [in]      const BYTE      *pConnectionData,
  [in]      DWORD           dwSizeofUserData,
  [in]      const BYTE      *pUserData,
  [in, out] DWORD           *pdwSizeOfUserDataOut,
  [out]     BYTE            **ppUserDataOut,
  [out]     LPWSTR          *ppwszIdentity,
  [out]     EAP_ERROR       **ppEapError,
  [in, out] LPVOID          *ppvReserved
);