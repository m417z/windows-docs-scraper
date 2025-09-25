DWORD EapMethodAuthenticatorUpdateInnerMethodParams(
  [in]  EAP_SESSION_HANDLE          sessionHandle,
  [in]  DWORD                       dwFlags,
  [in]  LPCWSTR                     pwszIdentity,
  [in]  const EapAttributes * const pAttributeArray,
  [out] EAP_ERROR                   **ppEapError
);