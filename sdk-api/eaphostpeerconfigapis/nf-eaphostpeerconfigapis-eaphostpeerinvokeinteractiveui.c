DWORD EapHostPeerInvokeInteractiveUI(
  [in]  HWND       hwndParent,
  [in]  DWORD      dwSizeofUIContextData,
  [in]  const BYTE *pUIContextData,
  [out] DWORD      *pdwSizeOfDataFromInteractiveUI,
  [out] BYTE       **ppDataFromInteractiveUI,
  [out] EAP_ERROR  **ppEapError
);