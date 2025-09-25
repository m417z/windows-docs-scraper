DWORD EapPeerInvokeIdentityUI(
  [in]  EAP_METHOD_TYPE *pEapType,
  [in]  DWORD           dwFlags,
  [in]  HWND            hwndParent,
  [in]  DWORD           dwSizeOfConnectionData,
  [in]  const BYTE      *pConnectionData,
  [out] DWORD           dwSizeOfUserData,
  [in]  const BYTE      *pUserData,
  [out] DWORD           *pdwSizeOfUserDataOut,
  [out] BYTE            **ppUserDataOut,
  [out] LPWSTR          *ppwszIdentity,
  [out] EAP_ERROR       **ppEapError
);