DWORD IPsecKeyManagerAddAndRegister0(
  [in]  HANDLE                             engineHandle,
  [in]  const IPSEC_KEY_MANAGER0           *keyManager,
  [in]  const IPSEC_KEY_MANAGER_CALLBACKS0 *keyManagerCallbacks,
  [out] HANDLE                             *keyMgmtHandle
);