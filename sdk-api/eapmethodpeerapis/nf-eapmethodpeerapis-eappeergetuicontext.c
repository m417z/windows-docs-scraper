DWORD EapPeerGetUIContext(
  [in]  EAP_SESSION_HANDLE sessionHandle,
  [out] DWORD              *pdwSizeOfUIContextData,
  [out] BYTE               **ppUIContextData,
  [out] EAP_ERROR          **ppEapError
);