DWORD EapPeerSetCredentials(
  [in]  EAP_SESSION_HANDLE sessionHandle,
  [in]  LPWSTR             pwszIdentity,
  [in]  LPWSTR             pwszPassword,
  [out] EAP_ERROR          **ppEapError
);