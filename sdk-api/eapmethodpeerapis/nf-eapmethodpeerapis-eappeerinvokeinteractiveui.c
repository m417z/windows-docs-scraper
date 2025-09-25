DWORD EapPeerInvokeInteractiveUI(
  [in]  EAP_METHOD_TYPE *pEapType,
  [in]  HWND            hwndParent,
  [in]  DWORD           dwSizeofUIContextData,
  [in]  BYTE            *pUIContextData,
  [out] DWORD           *pdwSizeOfDataFromInteractiveUI,
  [out] BYTE            **ppDataFromInteractiveUI,
  [out] EAP_ERROR       **ppEapError
);