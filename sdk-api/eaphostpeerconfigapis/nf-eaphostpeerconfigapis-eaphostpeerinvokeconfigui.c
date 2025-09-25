DWORD EapHostPeerInvokeConfigUI(
  [in]  HWND            hwndParent,
  [in]  DWORD           dwFlags,
  [in]  EAP_METHOD_TYPE eapMethodType,
  [in]  DWORD           dwSizeOfConfigIn,
  [in]  const BYTE      *pConfigIn,
  [out] DWORD           *pdwSizeOfConfigOut,
  [out] BYTE            **ppConfigOut,
  [out] EAP_ERROR       **ppEapError
);