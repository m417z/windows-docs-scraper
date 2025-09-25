DWORD EapPeerInvokeConfigUI(
  [in]  EAP_METHOD_TYPE *pEapType,
  [in]  HWND            hwndParent,
  [in]  DWORD           dwFlags,
  [in]  DWORD           dwSizeOfConnectionDataIn,
  [in]  BYTE            *pConnectionDataIn,
        DWORD           *dwSizeOfConnectionDataOut,
  [out] BYTE            **ppConnectionDataOut,
  [out] EAP_ERROR       **ppEapError
);